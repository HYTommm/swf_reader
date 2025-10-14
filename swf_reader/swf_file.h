/**
 * @file    swf_file.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include <istream>
#include <sstream>
#include <memory>
#include <vector>

#include "i_swf_stream_reader.h"
#include "swf_file_info.h"
#include "Data/swf_header.h"
#include "Tags/swf_tag_base.h"

namespace swf_reader {
	//class SwfTagDeserializer;
	class SwfTagSerializer;

	class SwfFile {
	public:

		SwfFileInfo file_info;
		data::SwfHeader header;

		Vec<Box<tags::SwfTagBase>> tags;

		SwfFile() = default;
		~SwfFile() = default;

		// 删除拷贝操作，允许移动操作
		SwfFile(const SwfFile&) = delete;
		SwfFile& operator=(const SwfFile&) = delete;
		SwfFile(SwfFile&&) = default;
		SwfFile& operator=(SwfFile&&) = default;

		static Box<SwfFile> read_from(std::istream& stream);

	private:
		Box<std::stringstream> decompressed_stream_;
		static void read_tags(SwfFile& file, ISwfStreamReader& reader);
		Box<ISwfStreamReader> get_swf_stream_reader(
			const SwfFileInfo& info, std::istream& stream);
	};
}
