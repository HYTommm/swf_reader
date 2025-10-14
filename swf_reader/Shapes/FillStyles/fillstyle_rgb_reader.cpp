#include "fillstyle_rgb_reader.h"

namespace swf_reader::shapes::fillstyles {
	inline FillStyleRGB& FillStyleRGBReader::visit(SolidFillStyleRGB& fillStyle, ISwfStreamReader& reader)
	{
		fillStyle.color = data::ColorStreamExt::read_rgb(reader);
		return fillStyle;
	}
}