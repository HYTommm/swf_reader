/**
 * @file    fillstyle_rgb_reader.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include "fillstyle_rgb.h"
#include "i_fillstyle_rgb_visitor.h"
#include "fillstyle_factory.h"
#include "Data/color_stream_ext.h"
namespace swf_reader::shapes::fillstyles
{
	class FillStyleRgbReader : IFillStyleRgbVisitor<ISwfStreamReader, FillStyleRgb&>
	{
	private:
		FillStyleFactory _factory;
	public:
		Box<FillStyleRgb> read(ISwfStreamReader& reader, FillStyleType type);
		FillStyleRgb& visit(SolidFillStyleRgb& fillstyle, ISwfStreamReader& reader) override;
	};
}
