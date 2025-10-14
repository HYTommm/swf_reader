/**
 * @file    fillstyle_rgb_reader.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "fillstyle_rgb_reader.h"

namespace swf_reader::shapes::fillstyles {
	inline FillStyleRGB& FillStyleRGBReader::visit(SolidFillStyleRGB& fillStyle, ISwfStreamReader& reader)
	{
		fillStyle.color = data::ColorStreamExt::read_rgb(reader);
		return fillStyle;
	}
}