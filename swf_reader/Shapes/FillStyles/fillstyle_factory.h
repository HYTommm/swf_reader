/**
 * @file    fillstyle_factory.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "fillstyle_rgb.h"
#include "fillstyle_rgba.h"
#include "solid_fillstyle_rgb.h"
#include "solid_fillstyle_rgba.h"
namespace swf_reader::shapes::fillstyles
{
	class FillStyleFactory
	{
	public:
		Box<FillStyleRgb> create_rgb(const FillStyleType type)
		{
			switch (type)
			{
				case FillStyleType::SolidColor:
					return boxed<SolidFillStyleRgb>();
					//case FillStyleType.LinearGradient:
					//    return new LinearGradientFillStyleRGB();
					//case FillStyleType.RadialGradient:
					//    return new RadialGradientFillStyleRGB();
					//case FillStyleType.FocalGradient:
					//    return new FocalGradientFillStyleRGB();
					//case FillStyleType.RepeatingBitmap:
					//    return new BitmapFillStyleRGB { Smoothing = true, Mode = BitmapMode.Repeat};
					//case FillStyleType.ClippedBitmap:
					//    return new BitmapFillStyleRGB { Smoothing = true, Mode = BitmapMode.Clip};
					//case FillStyleType.NonSmoothedRepeatingBitmap:
					//    return new BitmapFillStyleRGB { Smoothing = false, Mode = BitmapMode.Repeat };
					//case FillStyleType.NonSmoothedClippedBitmap:
					//    return new BitmapFillStyleRGB { Smoothing = false, Mode = BitmapMode.Clip};
					//default:
					//    throw new NotSupportedException();
			}
		}
		Box<FillStyleRgba> create_rgba(const FillStyleType type)
		{
			switch (type)
			{
				case FillStyleType::SolidColor:
					return boxed<SolidFillStyleRgba>();
			}
		}
	};
}
