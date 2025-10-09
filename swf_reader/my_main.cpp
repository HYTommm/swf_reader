#include <cstdlib>
#include <format>
#include <fstream>
#include <iostream> 
#include <vector>
#include "lzma.h"
#include "swf_file.h"
#include "zlib.h"
#include <print>

// 简单的压缩函数
std::vector<uint8_t> simple_compress(const std::vector<uint8_t>& input)
{
    lzma_stream strm = LZMA_STREAM_INIT;
    if (lzma_easy_encoder(&strm, 6, LZMA_CHECK_CRC64) != LZMA_OK)
    {
        return {};
    }

    std::vector<uint8_t> output;
    const size_t buffer_size = 1024;
    uint8_t buffer[buffer_size];

    strm.next_in = input.data();
    strm.avail_in = input.size();

    do
    {
        strm.next_out = buffer;
        strm.avail_out = buffer_size;

        lzma_ret ret = lzma_code(&strm, LZMA_FINISH);

        if (ret != LZMA_OK && ret != LZMA_STREAM_END)
        {
            lzma_end(&strm);
            return {};
        }

        size_t compressed_size = buffer_size - strm.avail_out;
        output.insert(output.end(), buffer, buffer + compressed_size);

    } while (strm.avail_out == 0);

    lzma_end(&strm);
    return output;
}

// 简单的解压函数
std::vector<uint8_t> simple_decompress(const std::vector<uint8_t>& input)
{
    lzma_stream strm = LZMA_STREAM_INIT;
    if (lzma_stream_decoder(&strm, UINT64_MAX, 0) != LZMA_OK)
    {
        return {};
    }

    std::vector<uint8_t> output;
    const size_t buffer_size = 1024;
    uint8_t buffer[buffer_size];

    strm.next_in = input.data();
    strm.avail_in = input.size();

    do
    {
        strm.next_out = buffer;
        strm.avail_out = buffer_size;

        lzma_ret ret = lzma_code(&strm, LZMA_FINISH);

        if (ret != LZMA_OK && ret != LZMA_STREAM_END)
        {
            lzma_end(&strm);
            return {};
        }

        size_t decompressed_size = buffer_size - strm.avail_out;
        output.insert(output.end(), buffer, buffer + decompressed_size);

    } while (strm.avail_out == 0);

    lzma_end(&strm);
    return output;
}


int my_main()
{
    /* 原始数据 */
    unsigned char strSrc[] = "hello world! aaaaa bbbbb ccccc ddddd 中文测试 yes";
    unsigned char buf[1024] = { 0 };
    unsigned char strDst[1024] = { 0 };
    unsigned long srcLen = sizeof(strSrc);
    unsigned long bufLen = sizeof(buf);
    unsigned long dstLen = sizeof(strDst);
    //std::system("chcp 65001>nul");
    printf("Src string:%s\nLength:%ld\n", strSrc, srcLen);

    /* 压缩 */
    compress(buf, &bufLen, strSrc, srcLen);
    printf("After Compressed Length:%ld\n", bufLen);

    /* 解压缩 */
    uncompress(strDst, &dstLen, buf, bufLen);
    printf("After UnCompressed Length:%ld\n", dstLen);

    printf("UnCompressed String:%s\n", strDst);


    std::cout << "测试liblzma库配置和功能..." << std::endl;
    std::cout << "liblzma版本: " << lzma_version_string() << std::endl;

    // 测试数据
    const char* test_string = "Hello, liblzma! 这是一个测试字符串，用于验证压缩和解压缩功能。";
    std::vector<uint8_t> original_data(test_string, test_string + strlen(test_string));

    std::cout << "\n原始数据: " << test_string << std::endl;
    std::cout << "原始数据大小: " << original_data.size() << " 字节" << std::endl;

    // 压缩
    auto compressed_data = simple_compress(original_data);
    if (compressed_data.empty())
    {
        std::cout << "✗ 压缩失败!" << std::endl;
        return 1;
    }
    std::cout << "压缩后大小: " << compressed_data.size() << " 字节" << std::endl;
    std::cout << "压缩率: " << (compressed_data.size() * 100.0 / original_data.size()) << "%" << std::endl;

    // 解压缩
    auto decompressed_data = simple_decompress(compressed_data);
    if (decompressed_data.empty())
    {
        std::cout << "解压缩失败!" << std::endl;
        return 1;
    }

    // 转换为字符串并输出
    std::string decompressed_string(decompressed_data.begin(), decompressed_data.end());
    std::cout << "解压缩后数据: " << decompressed_string << std::endl;
    std::cout << "解压缩后大小: " << decompressed_data.size() << " 字节" << std::endl;

    // 验证数据一致性
    if (original_data == decompressed_data)
    {
        std::cout << "\n测试成功! 压缩解压缩数据完全一致!" << std::endl;
    }
    else
    {
        std::cout << "\n测试失败! 数据不一致!" << std::endl;
        return 1;
    }
    return 0;
}



int main(int argc, char* argv[])
{
    //std::system("chcp 65001>nul");
    if (argc != 2)
    {
        //std::cout << "Usage: " << argv[0] << " <swf_file>\n";
        std::print("Usage: {} <swf_file>\n", argv[0]);
        return 1;
    }
    std::print("读取swf文件{}\n", argv[1]);
    // 以二进制形式打开swf文件
    std::ifstream file(argv[1], std::ios::binary);

    std::print("文件打开成功\n");

    Box<swf_reader::SwfFile> swf_file = swf_reader::SwfFile::read_from(file);

    std::print("已读取\n");

    if (!swf_file)
    {
        std::print("Failed to read SWF file\n");
        return 2;
    }
    /*
    *         SwfFile swf = SwfFile.ReadFrom(_stream);
        // 文件信息
        GD.Print("签名: " + swf.FileInfo.Format);
        GD.Print("版本: " + swf.FileInfo.Version);
        GD.Print("文件大小: " + swf.FileInfo.FileLength);
        GD.Print("帧率: " + swf.Header.FrameRate);
        GD.Print("帧数: " + swf.Header.FrameCount);
        GD.Print("显示区域（缇）: " + swf.Header.FrameSize.XMin + ", " + swf.Header.FrameSize.YMin + "=> "
                                    + swf.Header.FrameSize.XMax + ", " + swf.Header.FrameSize.YMax + "缇");
        GD.Print("显示区域（像素）: " + swf.Header.FrameSize.XMin / 20 + ", " + swf.Header.FrameSize.YMin / 20 + "=> "
                                      + swf.Header.FrameSize.XMax / 20 + ", " + swf.Header.FrameSize.YMax / 20 + "像素");
    */

    // 打印swf文件信息
    std::print("签名: {}\n", static_cast<int>(swf_file->file_info.format));
    std::print("版本: {}\n", swf_file->file_info.version);
    std::print("文件大小: {}\n", swf_file->file_info.file_length);
    std::print("帧率: {}\n", swf_file->header.frame_rate);
    std::print("帧数: {}\n", swf_file->header.frame_count);
    std::print("显示区域（缇）: {}, {}=> {}, {}缇\n", 
               swf_file->header.frame_size.x_min, swf_file->header.frame_size.y_min, 
               swf_file->header.frame_size.x_max, swf_file->header.frame_size.y_max);
    std::print("显示区域（像素）: {}, {}=> {}, {}像素\n", 
               swf_file->header.frame_size.x_min / 20, swf_file->header.frame_size.y_min / 20, 
               swf_file->header.frame_size.x_max / 20, swf_file->header.frame_size.y_max / 20);

    for (Box<swf_reader::tags::SwfTagBase>& tag : swf_file->tags)
    {
        if (tag->tag_type == swf_reader::tags::SwfTagType::Unknown)
        {
            continue;
        }
        std::print("标签类型: {}\n", static_cast<int>(tag->tag_type));
        //std::print("标签数据: {}\n", tag.data);
    }
    

    return 0;
}