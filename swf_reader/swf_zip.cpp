/**
 * @file    swf_zip.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "swf_zip.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "lzma.h"
#include "zlib.h"

namespace swf_reader {

    void SwfZip::decompress(std::istream& source, std::ostream& target, const SwfFormat format)
    {
        validate_compression_format(format);
        switch (format)
        {
            case SwfFormat::FWS:
                // 未压缩，直接返回
                break;
            case SwfFormat::CWS:
                decompress_zlib(source, target);
                break;
            case SwfFormat::ZWS:
                decompress_lzma(source, target);
                break;
            case SwfFormat::Unknown:
                throw std::invalid_argument("Unknown compression format");
        }
    }

    Vec<u8> SwfZip::decompress(const std::vector<u8>& compressed, const SwfFormat format)
    {
        std::istringstream source(std::string(compressed.begin(), compressed.end()));
        std::ostringstream target;

        decompress(source, target, format);

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


    void SwfZip::decompress_zlib(std::istream& source, std::ostream& target)
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
            throw std::runtime_error("Failed to initialize zlib decompression");
        }

        constexpr usize BUFFER_SIZE = 4096;
        Vec<u8> in_buffer(BUFFER_SIZE);
        Vec<u8> out_buffer(BUFFER_SIZE);

        int result = Z_OK;
        bool stream_ended = false;
        std::streamsize total_decompressed_size = 0;
        try
        {
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
                        throw std::runtime_error("Incomplete zlib stream");
                    }
                }
                else
                {
                    // 真正的错误
                    throw std::runtime_error("Zlib decompression failed with error: " + std::to_string(result));
                }

            } while (stream.avail_out == 0 || !stream_ended);
        }
        catch (...)
        {
            inflateEnd(&stream);
            throw;
        }

        inflateEnd(&stream);
        std::cout << "Decompression completed. Output size: " << total_decompressed_size << " bytes" << std::endl;
    }

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

    void SwfZip::validate_compression_format(const SwfFormat format)
    {
        if (format == SwfFormat::Unknown)
        {
            throw std::invalid_argument("Unknown compression format");
        }
    }

}
