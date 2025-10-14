/**
 * @file    solid_fillstyle_rgb.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "fillstyle_rgb.h"
#include "Data/swf_rgb.h"
namespace swf_reader::shapes::fillstyles
{
	class SolidFillStyleRgb : public FillStyleRgb {
	public:
		data::SwfRGB color;

		/// <summary>
		/// Gets type of fill style.
		/// </summary>
		FillStyleType get_type() const override
		{
			return FillStyleType::SolidColor;
		}

		FillStyleRgb& accept_visitor(IFillStyleRgbVisitor<ISwfStreamReader, FillStyleRgb&>& visitor, ISwfStreamReader& arg) override
		{
			return visitor.visit(*this, arg);
		}
	};
}
