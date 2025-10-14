/**
 * @file    fillstyle_rgb.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "i_fillstyle_rgb_visitor.h"
#include "fillstyle_type.h"
#include "i_swf_stream_reader.h"
namespace swf_reader::shapes::fillstyles
{
	class FillStyleRgb
	{
	private:
		FillStyleType type_;
	public:
		FillStyleRgb() = default;
		virtual ~FillStyleRgb() = default;

		virtual FillStyleType get_type() const = 0;
		virtual FillStyleRgb& accept_visitor(IFillStyleRGBVisitor<ISwfStreamReader, FillStyleRgb&>& visitor, ISwfStreamReader& arg) = 0;
	};
}