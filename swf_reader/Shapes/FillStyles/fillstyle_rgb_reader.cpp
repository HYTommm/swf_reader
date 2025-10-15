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
	inline Box<FillStyleRgb> FillStyleRgbReader::read(ISwfStreamReader& reader, FillStyleType type) {
		Box<FillStyleRgb> fillstyle = _factory.create_rgb(type);
		fillstyle->accept_visitor(*this, reader);
		return fillstyle;
	}
	inline FillStyleRgb& FillStyleRgbReader::visit(SolidFillStyleRgb& fillstyle, ISwfStreamReader& reader)
	{
		fillstyle.color = data::ColorStreamExt::read_rgb(reader);
		return fillstyle;
	}
}