/**
 * @file    swf_file.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "swf_file.h"

#include <format>
#include <memory>
#include <print>
#include <sstream>
#include <stdexcept>

#include "cpp_base_type.h"
#include "swf_stream_reader.h"
#include "swf_stream_reader_ext.h"
#include "swf_zip.h"
#include "Tags/swf_tag_deserializer.h"
#include "Tags/tag_stream_ext.h"

namespace swf_reader {

    Box<SwfFile> SwfFile::read_from(std::istream& stream)
    {
	    Box<SwfFile> file = boxed<SwfFile>();
        std::print("开始读取文件\n");

        SwfStreamReader reader(stream);
        file->file_info = SwfStreamReaderExt::read_swf_file_info(reader);
        std::print("文件信息读取完毕\n");
        const Box<ISwfStreamReader> final_reader = file->get_swf_stream_reader(file->file_info, stream);
        file->header = SwfStreamReaderExt::read_swf_header(*final_reader);
        std::print("头部信息读取完毕\n");
        read_tags(*file, *final_reader);

        return file;
    }

    void SwfFile::read_tags(SwfFile& file, ISwfStreamReader& reader)
    {
        while (!reader.is_eof())
        {
	        const Box<tags::SwfTagDeserializer> deserializer = boxed<tags::SwfTagDeserializer>(file);
	        tags::SwfTagData tag_data = tags::TagStreamExt::read_tag_data(reader);

            if (Box<tags::SwfTagBase> tag = deserializer->read_tag(tag_data))
            {
                std::print("读取到标签 {}\n", (int)tag->tag_type);
                file.tags.push_back(std::move(tag));
            }
            else
            {
                throw std::runtime_error("Tag can't be null. Loss of data possible");
            }
        }
    }

    Box<ISwfStreamReader> SwfFile::get_swf_stream_reader(
        const SwfFileInfo& info,
        std::istream& stream)
    {
    
        if (info.format == SwfFormat::FWS)
        {
            return boxed<SwfStreamReader>(stream);
        }
        //decompressed_stream_ = std::make_unique<std::stringstream>();
    
        // 对于压缩格式，先解压
        decompressed_stream_ = boxed<std::stringstream>();
        SwfZip::decompress(stream, *decompressed_stream_, info.format);
        decompressed_stream_->seekg(0);
    
        return boxed<SwfStreamReader>(*decompressed_stream_);
    }

    

}
