//#ifdef _DEBUG

#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include "swf_file.h"
#include "zlib.h"
#include "Tags/ShapeTags/define_shape_tag.h"

#include <chrono>

#include "Tags/define_sprite_tag.h"
#include "Tags/ControlTags/symbol_class_tag.h"

int main(int argc, char* argv[])
{
    //std::system("chcp 65001>nul");
    if (argc != 2)
    {
        //std::cout << "Usage: " << argv[0] << " <swf_file>\n";
        std::cout << "Usage: " << argv[0] << " <swf_file>\n";
        return 1;
    }
    //std::print("读取swf文件{}\n", argv[1]);
    // 以二进制形式打开swf文件
    std::ifstream file(argv[1], std::ios::binary);

    //std::print("文件打开成功\n");

    constexpr usize buffer_size = static_cast<usize>(16) * 1024; // 128kb
    char my_buffer[buffer_size];

    file.rdbuf()->pubsetbuf(my_buffer, buffer_size);
    const Box<swf_reader::SwfFile> swf_file = swf_reader::SwfFile::read_from(file);

    //std::print("已读取\n");

    if (!swf_file)
    {
        std::cout << "Failed to read SWF file\n";
        return 2;
    }
    for (const Box<swf_reader::tags::SwfTagBase>& tag : swf_file->tags)
    {
        using namespace swf_reader::tags;
        if (tag->get_type() == SwfTagType::SymbolClass)
        {
            auto* sym_tag = static_cast<control_tags::SymbolClassTag*>(tag.get());
            for (const swf_reader::data::SwfSymbolReference& ref : sym_tag->references)
            {
                //_symbol_map.insert(StringName(ref.symbol_name.c_str()), ref.symbol_id);
                //id宽度至少4位
                printf("Symbol ID: %-4d  Symbol Name: %s\n", ref.symbol_id, ref.symbol_name.c_str());
            }
        }
    }

    return 0;
}

//#endif // _DEBUG