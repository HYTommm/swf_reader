#pragma once

#include "fillstyle_rgb.h"
#include "Data/swf_rgb.h"
namespace swf_reader::shapes::fillstyles
{
	class SolidFillStyleRGB : public FillStyleRGB {
	public:
		data::SwfRGB color;

		/// <summary>
		/// Gets type of fill style.
		/// </summary>
		FillStyleType get_type() const override {
			return FillStyleType::SolidColor;
		}

		FillStyleRGB& accept_visitor(IFillStyleRGBVisitor<ISwfStreamReader, FillStyleRGB&>& visitor, ISwfStreamReader& arg) override
		{
			return visitor.visit(*this, arg);
		}
	};
}
