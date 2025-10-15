/**
 * @file    fillstyle_rgba.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "i_fillstyle_rgba_visitor.h"
#include "fillstyle_type.h"
#include "i_swf_stream_reader.h"
namespace swf_reader::shapes::fillstyles
{
	class FillStyleRgba
	{
	public:
		FillStyleRgba() = default;
		virtual ~FillStyleRgba() = default;

		virtual FillStyleType get_type() const = 0;
		virtual FillStyleRgba& accept_visitor(IFillStyleRgbaVisitor<ISwfStreamReader, FillStyleRgba&>& visitor, ISwfStreamReader& arg) = 0;
	};
}