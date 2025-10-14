#pragma once

#include "fillstyle_rgb.h"
#include "i_fillstyle_rgb_visitor.h"
#include "fillstyle_factory.h"
#include "Data/color_stream_ext.h"
namespace swf_reader::shapes::fillstyles
{
	class FillStyleRGBReader : IFillStyleRGBVisitor<ISwfStreamReader, FillStyleRGB&>
	{
	private:
		FillStyleFactory _factory;
	public:
		FillStyleRGB& visit(SolidFillStyleRGB& fillStyle, ISwfStreamReader& reader);
	};
}
