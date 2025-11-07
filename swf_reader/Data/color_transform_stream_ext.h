/**
 * @file    color_transform_stream_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "color_transform_rgb.h"
#include "color_transform_rgba.h"
#include "i_swf_stream_reader.h"

namespace swf_reader::data {
	class ColorTransformStreamExt {
	public:
		static ColorTransformRGB read_color_transform_rgb(ISwfStreamReader& reader);
		static ColorTransformRgba read_color_transform_rgba(ISwfStreamReader& reader);
	};
}
