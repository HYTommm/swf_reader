/*
 * @file    color_stream_ext.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "color_stream_ext.h"
#include "i_swf_stream_reader.h"
#include "swf_rgb.h"

namespace swf_reader::data
{
	inline SwfRGB ColorStreamExt::read_rgb(ISwfStreamReader& reader)
	{
		SwfRGB color;
		read_rgb(reader, color);
		return color;
	}
	inline void ColorStreamExt::read_rgb(ISwfStreamReader& reader, SwfRGB& color)
	{
		color.red = reader.read_byte();
		color.green = reader.read_byte();
		color.blue = reader.read_byte();
	}
}