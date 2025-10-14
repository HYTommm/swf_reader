/**
 * @file    i_fillstyle_rgb_visitor.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

namespace swf_reader::shapes::fillstyles
{
	// Forward declaration
	class SolidFillStyleRGB;

	template<typename TArg, typename TResult>
	class IFillStyleRGBVisitor
	{
	public:
		virtual TResult& visit(SolidFillStyleRGB& fillStyle, TArg& arg) = 0;
		//virtual TResult visit(LinearGradientFillStyleRGB& fillStyle, TArg arg) = 0;
		//virtual TResult visit(RadialGradientFillStyleRGB& fillStyle, TArg arg) = 0;
		//virtual TResult visit(FocalGradientFillStyleRGB& fillStyle, TArg arg) = 0;
		//virtual TResult visit(BitmapFillStyleRGB& fillStyle, TArg arg) = 0;
		virtual ~IFillStyleRGBVisitor() = default;
	};
}