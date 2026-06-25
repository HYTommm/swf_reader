/**
 * @file    swf_zip.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "swf_zip.h"

#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "lzma.h"
#include "zlib.h"

namespace swf_reader
{
    bool SwfZip::decompress(std::istream& source, std::ostream& target, const SwfFormat format)
    {
        switch (format)
        {
            case SwfFormat::FWS:
                // 未压缩，直接返回
                break;
            case SwfFormat::CWS:
            {
                const bool result = decompress_zlib(source, target);
                if (!result)
                {
                    std::cerr << "Failed to decompress zlib compressed data\n";
                    return false;
                }
            }break;
            case SwfFormat::ZWS:
            {
                const bool result = decompress_lzma(source, target);
                if (!result)
                {
                    std::cerr << "Failed to decompress lzma compressed data\n";
                    return false;
                }
            }break;
            case SwfFormat::Unknown:
                std::cerr << "Unknown compression format\n";
                return false;
        }
        return true;
    }

    Vec<u8> SwfZip::decompress(const Vec<u8>& compressed, const SwfFormat format)
    {
        std::istringstream source(std::string(compressed.begin(), compressed.end()));
        std::ostringstream target;

        if (!decompress(source, target, format))
        {
            return {};
        }

        std::string result_str = target.str();
        return { result_str.begin(), result_str.end() };
    }

    //void SwfZip::decompress_zlib(std::istream& source, std::ostream& target)
    //{
    //    z_stream stream = {};

    //    if (inflateInit(&stream) != Z_OK)
    //    {
    //        throw std::runtime_error("Failed to initialize zlib decompression");
    //    }

    //    constexpr usize BUFFER_SIZE = 4096;
    //    Vec<u8> in_buffer(BUFFER_SIZE);
    //    Vec<u8> out_buffer(BUFFER_SIZE);

    //    int result = Z_OK;
    //
    //    do
    //    {
    //        // 读取压缩数据
    //        source.read(reinterpret_cast<char*>(in_buffer.data()), BUFFER_SIZE);
    //        stream.avail_in = static_cast<uInt>(source.gcount());
    //        stream.next_in = in_buffer.data();

    //        if (stream.avail_in == 0)
    //        {
    //            break;
    //        }

    //        // 解压数据
    //        do
    //        {
    //            stream.avail_out = BUFFER_SIZE;
    //            stream.next_out = out_buffer.data();

    //            result = inflate(&stream, Z_NO_FLUSH);
    //            if (result != Z_OK && result != Z_STREAM_END)
    //            {
    //                inflateEnd(&stream);
    //                throw std::runtime_error("Zlib decompression failed");
    //            }

    //            // 写入解压后的数据
    //            usize decompressed_size = BUFFER_SIZE - stream.avail_out;
    //            target.write(reinterpret_cast<const char*>(out_buffer.data()),
    //                static_cast<std::streamsize>(decompressed_size));
    //        } while (stream.avail_out == 0);

    //    } while (result != Z_STREAM_END);

    //    inflateEnd(&stream);
    //    std::cout << "Decompression completed. Output size: " << total_decompressed_size << " bytes" << std::endl;
    //}

    bool SwfZip::decompress_zlib(std::istream& source, std::ostream& target)
    {
        z_stream stream = {};

        // 确保正确初始化所有字段
        stream.zalloc = Z_NULL;
        stream.zfree = Z_NULL;
        stream.opaque = Z_NULL;
        stream.avail_in = 0;
        stream.next_in = Z_NULL;

        if (inflateInit(&stream) != Z_OK)
        {
            //throw std::runtime_error("Failed to initialize zlib decompression");
            std::cerr << "Failed to initialize zlib decompression\n";
            return false;
        }

        constexpr usize BUFFER_SIZE = 4096;
        Vec<u8> in_buffer(BUFFER_SIZE);
        Vec<u8> out_buffer(BUFFER_SIZE);

        int result = Z_OK;
        bool stream_ended = false;
        [[maybe_unused]] std::streamsize total_decompressed_size = 0;
        do
        {
            // 只有当输入缓冲区为空时才读取新数据
            if (stream.avail_in == 0 && !stream_ended)
            {
                source.read(reinterpret_cast<char*>(in_buffer.data()), BUFFER_SIZE);
                stream.avail_in = static_cast<uInt>(source.gcount());
                stream.next_in = in_buffer.data();

                // 检查是否到达文件末尾
                if (stream.avail_in == 0)
                {
                    stream_ended = true;
                }
            }

            // 设置输出缓冲区
            stream.avail_out = BUFFER_SIZE;
            stream.next_out = out_buffer.data();

            // 解压数据
            result = inflate(&stream, stream_ended ? Z_FINISH : Z_NO_FLUSH);

            // 处理返回值
            if (result == Z_STREAM_END)
            {
                // 正常结束
                usize decompressed_size = BUFFER_SIZE - stream.avail_out;
                if (decompressed_size > 0)
                {
                    target.write(reinterpret_cast<const char*>(out_buffer.data()),
                        static_cast<std::streamsize>(decompressed_size));
                }
                break;
            }
            else if (result == Z_OK || result == Z_BUF_ERROR)
            {
                // Z_BUF_ERROR 是正常情况，表示需要更多输入或输出空间
                usize decompressed_size = BUFFER_SIZE - stream.avail_out;
                if (decompressed_size > 0)
                {
                    target.write(reinterpret_cast<const char*>(out_buffer.data()),
                        static_cast<std::streamsize>(decompressed_size));
                    total_decompressed_size += decompressed_size;
                }

                // 如果已经到达流末尾但解压还没结束，可能是数据不完整
                if (stream_ended && result == Z_BUF_ERROR)
                {
                    //throw std::runtime_error("Incomplete zlib stream");
                    std::cerr << "Incomplete zlib stream\n";
                    return false;
                }
            }
            else
            {
                // 真正的错误
                //throw std::runtime_error("Zlib decompression failed with error: " + std::to_string(result));
                std::cerr << "Zlib decompression failed with error: " << result << "\n";
                return false;
            }
        } while (stream.avail_out == 0 || !stream_ended);

        inflateEnd(&stream);
        return true;
    }

    bool SwfZip::decompress_lzma(std::istream& source, std::ostream& target)
    {
        u32 uncompressed_size = 0;
        source.read(reinterpret_cast<char*>(&uncompressed_size), 4);

        // 检查流状态
        if (!source.good() || !target.good())
        {
            return false;
        }

        // 1. 读取并解析5字节LZMA属性头
        std::array<u8, 5> header{};
        source.read(reinterpret_cast<char*>(header.data()), header.size());
        if (source.gcount() != header.size())
        {
            std::cerr << "Failed to read LZMA header\n";
            return false;
        }

        // 2. 配置LZMA1过滤器
        lzma_filter filters[2];
        lzma_options_lzma opt_lzma;

        // 使用默认预设初始化LZMA选项
        if (lzma_lzma_preset(&opt_lzma, LZMA_PRESET_DEFAULT) != LZMA_OK)
        {
            return false;
        }

        // 解析属性字节 (第一个字节)
        // 覆盖为文件中的实际属性
        const u8 props = header[0];
        opt_lzma.lc = props % 9;
        opt_lzma.lp = (props / 9) % 5;
        opt_lzma.pb = props / 45;
        // 解析字典大小 (后4字节，小端)
        opt_lzma.dict_size = static_cast<u32>(header[1]) |
            (static_cast<u32>(header[2]) << 8) |
            (static_cast<u32>(header[3]) << 16) |
            (static_cast<u32>(header[4]) << 24);

        filters[0].id = LZMA_FILTER_LZMA1;
        filters[0].options = &opt_lzma;
        filters[1].id = LZMA_VLI_UNKNOWN;
        filters[1].options = nullptr;

        // 3. 初始化原始解码器
        lzma_stream strm = LZMA_STREAM_INIT;
        lzma_ret ret = lzma_raw_decoder(&strm, filters);
        if (ret != LZMA_OK)
        {
            lzma_end(&strm);
            return false;
        }

        // 4. 准备缓冲区
        constexpr size_t BUFFER_SIZE = 8192;
        u8 in_buf[BUFFER_SIZE];
        u8 out_buf[BUFFER_SIZE];

        // 5. 解压数据
        bool success = false;
        strm.next_in = nullptr;
        strm.avail_in = 0;
        strm.next_out = out_buf;
        strm.avail_out = BUFFER_SIZE;

        while (true)
        {
            // 读取更多输入数据
            if (strm.avail_in == 0 && !source.eof())
            {
                //source.read(reinterpret_cast<char*>(in_buf.data()), in_buf.size());
                source.read(reinterpret_cast<char*>(in_buf), BUFFER_SIZE);
                strm.next_in = in_buf;
                strm.avail_in = source.gcount();

                if (source.bad())
                {
                    break;
                }
            }

            // 确定动作：如果输入已读完且没有更多数据，使用LZMA_FINISH
            const lzma_action action = source.eof() ? LZMA_FINISH : LZMA_RUN;

            // 执行解压
            ret = lzma_code(&strm, action);

            // 写入输出数据
            if (strm.avail_out == 0 || ret == LZMA_STREAM_END)
            {
                const size_t write_size = BUFFER_SIZE - strm.avail_out;
                target.write(reinterpret_cast<const char*>(out_buf), write_size);

                if (!target.good())
                {
                    break;
                }

                strm.next_out = out_buf;
                strm.avail_out = BUFFER_SIZE;
            }

            // 检查解压结果
            if (ret != LZMA_OK)
            {
                if (ret == LZMA_STREAM_END)
                {
                    success = true;
                }
                break;
            }
        }

        // 6. 清理资源
        lzma_end(&strm);

        // 确保输出流刷新
        if (success)
        {
            target.flush();
        }

        return success;
    }

    #if false
    void SwfZip::decompress_lzma(std::istream& source, std::ostream& target)
    {
        // SWF LZMA 格式：前 4 字节是未压缩数据大小
        u32 uncompressed_size = 0;
        source.read(reinterpret_cast<char*>(&uncompressed_size), 4);

        if (!source)
        {
            throw std::runtime_error("Failed to read LZMA uncompressed size");
        }

        lzma_stream stream = LZMA_STREAM_INIT;

        // 配置 LZMA 解码器
        if (lzma_auto_decoder(&stream, UINT64_MAX, 0) != LZMA_OK)
        {
            throw std::runtime_error("Failed to initialize LZMA decoder");
        }

        constexpr usize BUFFER_SIZE = 4096;
        Vec<u8> in_buffer(BUFFER_SIZE);
        Vec<u8> out_buffer(BUFFER_SIZE);

        lzma_ret result = LZMA_OK;

        do
        {
            // 读取压缩数据
            source.read(reinterpret_cast<char*>(in_buffer.data()), BUFFER_SIZE);
            stream.avail_in = static_cast<size_t>(source.gcount());
            stream.next_in = in_buffer.data();

            if (stream.avail_in == 0)
            {
                break;
            }

            // 解压数据
            do
            {
                stream.avail_out = BUFFER_SIZE;
                stream.next_out = out_buffer.data();

                result = lzma_code(&stream, LZMA_RUN);
                if (result != LZMA_OK && result != LZMA_STREAM_END)
                {
                    lzma_end(&stream);
                    throw std::runtime_error("LZMA decompression failed");
                }

                // 写入解压后的数据
                usize decompressed_size = BUFFER_SIZE - stream.avail_out;
                target.write(reinterpret_cast<const char*>(out_buffer.data()),
                    static_cast<std::streamsize>(decompressed_size));
            } while (stream.avail_out == 0);
        } while (result != LZMA_STREAM_END);

        lzma_end(&stream);
    }
    #endif
}