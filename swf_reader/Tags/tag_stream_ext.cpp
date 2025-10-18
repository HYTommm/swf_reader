/**
 * @file    tag_stream_ext.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "tag_stream_ext.h"
#include "cpp_base_type.h"

namespace swf_reader::tags
{
	SwfTagData TagStreamExt::read_tag_data(ISwfStreamReader& reader)
	{
		const u16 type_and_size = reader.read_ui16();
		const SwfTagType type = static_cast<SwfTagType>(type_and_size >> 6);
		const int short_size = type_and_size & 0x3f;

		u32 size = 0;
		if (short_size < 0x3f)
		{
			size = short_size;
		}
		else
		{
			size = static_cast<u32>(reader.read_si32());
		}

		const Vec<u8> tag_data = reader.read_bytes(size);
		return SwfTagData{ type, tag_data };
	}
}