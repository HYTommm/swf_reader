/**
 * @file    color_stream_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

 //#include "i_swf_stream_reader.h"
 //#include "swf_rgb.h"
namespace swf_reader
{
	class ISwfStreamReader;
}
namespace swf_reader::data
{
	struct SwfRGB;
	class ColorStreamExt {
	public:
		static SwfRGB read_rgb(ISwfStreamReader& reader);

		static void read_rgb(ISwfStreamReader& reader, SwfRGB& color);

		//static SwfRGBA read_rgba(ISwfStreamReader& reader) {
		//	SwfRGBA color;
		//	color.red = reader.read_byte();
		//	color.green = reader.read_byte();
		//	color.blue = reader.read_byte();
		//	color.alpha = reader.read_byte();
		//	return color;
		//}

		//static SwfRGBA read_argb(ISwfStreamReader& reader) {
		//	SwfRGBA color;
		//	color.alpha = reader.read_byte();
		//	color.red = reader.read_byte();
		//	color.green = reader.read_byte();
		//	color.blue = reader.read_byte();
		//	return color;
		//}
	};
}