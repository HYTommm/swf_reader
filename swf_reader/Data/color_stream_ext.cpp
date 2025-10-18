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
#include "swf_rgba.h"

namespace swf_reader::data
{
	SwfRgb ColorStreamExt::read_rgb(ISwfStreamReader& reader)
	{
		SwfRgb color;
		read_rgb(reader, color);
		return color;
	}
	void ColorStreamExt::read_rgb(ISwfStreamReader& reader, SwfRgb& color)
	{
		color.red = reader.read_byte();
		color.green = reader.read_byte();
		color.blue = reader.read_byte();
	}
	SwfRgba ColorStreamExt::read_rgba(ISwfStreamReader& reader)
	{
		SwfRgba color;
		color.red = reader.read_byte();
		color.green = reader.read_byte();
		color.blue = reader.read_byte();
		color.alpha = reader.read_byte();
		return color;
	}
	SwfRgba ColorStreamExt::read_argb(ISwfStreamReader& reader)
	{
		SwfRgba color;
		color.alpha = reader.read_byte();
		color.red = reader.read_byte();
		color.green = reader.read_byte();
		color.blue = reader.read_byte();
		return color;
	}
}