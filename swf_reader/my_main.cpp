#ifdef _DEBUG

#include <cstdlib>
#include <format>
#include <fstream>
#include <iostream>
#include <print>
#include <vector>
#include "lzma.h"
#include "swf_file.h"
#include "zlib.h"
#include "Tags/ShapeTags/define_shape_tag.h"

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
    int unknown_count = 0;
    for (i32 i = 0; i < swf_file->tags.size(); i++)
    {
        swf_reader::tags::SwfTagBase& tag = *(swf_file->tags[i]);
        if (tag.get_type() == swf_reader::tags::SwfTagType::Unknown)
        {
            unknown_count++;
            continue;
        }

        //std::print("标签类型: {}", static_cast<int>(tag.get_type()));
        //if (tag.get_type() == swf_reader::tags::SwfTagType::DefineShape
        //    || tag.get_type() == swf_reader::tags::SwfTagType::DefineShape2
        //    || tag.get_type() == swf_reader::tags::SwfTagType::DefineShape3
        //    || tag.get_type() == swf_reader::tags::SwfTagType::DefineShape4
        //    )
        //{
        //    std::print("id: {}", static_cast<swf_reader::tags::shape_tags::ShapeBaseTag&>(tag).shape_id);
        //}
        //std::print("\n");

        ////std::print("标签数据: {}\n", tag.data);
    }
    std::print("可解析的标签比例: {}%\n", (100.0 - unknown_count * 100.0 / swf_file->tags.size()));

    return 0;
}

#endif // _DEBUG