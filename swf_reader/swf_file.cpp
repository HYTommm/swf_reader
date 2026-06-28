/**
 * @file    swf_file.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "swf_file.h"

#include <memory>
#include <sstream>
#include <stdexcept>

#include "cpp_base_type.h"
#include "swf_stream_reader.h"
#include "swf_stream_reader_ext.h"
#include "swf_zip.h"
#include "Tags/swf_tag_deserializer.h"
#include "Tags/tag_stream_ext.h"

namespace swf_reader
{
    Box<SwfFile> SwfFile::read_from(std::istream& stream)
    {
        Box<SwfFile> file = boxed<SwfFile>();
        SwfStreamReader reader(stream);
        file->file_info = SwfStreamReaderExt::read_swf_file_info(reader);
        const Box<ISwfStreamReader> final_reader = file->get_swf_stream_reader(file->file_info, stream);
        if (final_reader != nullptr)
        {
            file->header = SwfStreamReaderExt::read_swf_header(*final_reader);
            read_tags(*file, *final_reader);
        }
        else
        {
            std::cerr << "Error reading SWF file: Unsupported compression format";
            file = nullptr;
        }
        return file;
    }

    void SwfFile::read_tags(SwfFile& file, ISwfStreamReader& reader)
    {
        //const Box<tags::SwfTagDeserializer> deserializer = boxed<tags::SwfTagDeserializer>(file);
        tags::SwfTagDeserializer deserializer = tags::SwfTagDeserializer(file);
        file.tags.reserve(file.file_info.file_length / 512);
        while (!reader.is_eof())
        {
            tags::SwfTagData tag_data = tags::TagStreamExt::read_tag_data(reader);

            if (Box<tags::SwfTagBase> tag = deserializer.read_tag(tag_data))
            {
                file.tags.push_back(std::move(tag));
            }
            else
            {
                continue;
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