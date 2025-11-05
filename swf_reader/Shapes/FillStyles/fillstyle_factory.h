/**
 * @file    fillstyle_factory.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "fillstyle_type.h"
#include "fillstyle_rgb.h"
#include "fillstyle_rgba.h"
#include "solid_fillstyle_rgb.h"
#include "solid_fillstyle_rgba.h"
#include "linear_gradient_fillstyle_rgb.h"
#include "linear_gradient_fillstyle_rgba.h"
#include "radial_gradient_fillstyle_rgb.h"
#include "radial_gradient_fillstyle_rgba.h"
#include "focal_gradient_fillstyle_rgb.h"
#include "focal_gradient_fillstyle_rgba.h"
#include "bitmap_fillstyle_rgb.h"
#include "bitmap_fillstyle_rgba.h"
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
                case FillStyleType::LinearGradient:
                    return boxed<LinearGradientFillStyleRgb>();
                case FillStyleType::RadialGradient:
                    return boxed<RadialGradientFillStyleRgb>();
                case FillStyleType::FocalGradient:
                    return boxed<FocalGradientFillStyleRgb>();
                case FillStyleType::RepeatingBitmap:
                    return boxed<BitmapFillStyleRgb>(true, BitmapMode::Repeat);
                case FillStyleType::ClippedBitmap:
                    return boxed<BitmapFillStyleRgb>(true, BitmapMode::Clip);
                case FillStyleType::NonSmoothedRepeatingBitmap:
                    return boxed<BitmapFillStyleRgb>(false, BitmapMode::Repeat);
                case FillStyleType::NonSmoothedClippedBitmap:
                    return boxed<BitmapFillStyleRgb>(false, BitmapMode::Clip);
                default:
                    throw std::runtime_error("Not supported");
            }
        }
        Box<FillStyleRgba> create_rgba(const FillStyleType type)
        {
            switch (type)
            {
                case FillStyleType::SolidColor:
                    return boxed<SolidFillStyleRgba>();
                case FillStyleType::LinearGradient:
                    return boxed<LinearGradientFillStyleRgba>();
                case FillStyleType::RadialGradient:
                    return boxed<RadialGradientFillStyleRgba>();
                case FillStyleType::FocalGradient:
                    return boxed<FocalGradientFillStyleRgba>();
                case FillStyleType::RepeatingBitmap:
                    return boxed<BitmapFillStyleRgba>(true, BitmapMode::Repeat);
                case FillStyleType::ClippedBitmap:
                    return boxed<BitmapFillStyleRgba>(true, BitmapMode::Clip);
                case FillStyleType::NonSmoothedRepeatingBitmap:
                    return boxed<BitmapFillStyleRgba>(false, BitmapMode::Repeat);
                case FillStyleType::NonSmoothedClippedBitmap:
                    return boxed<BitmapFillStyleRgba>(false, BitmapMode::Clip);
                default:
                    throw std::runtime_error("Not supported");
            }
        }
    };
}
