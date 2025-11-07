/**
 * @file    filter_factory.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#include "filter_factory.h"

namespace swf_reader::filters
{
    Box<BaseFilter> FilterFactory::create(FilterType type)
    {
        switch (type)
        {
            //case FilterType::DropShadow:
            //    return Box<DropShadowFilter>();
            //case FilterType::Blur:
            //    return Box<BlurFilter>();
            //case FilterType::Glow:
            //    return Box<GlowFilter>();
            //case FilterType::Bevel:
            //    return Box<BevelFilter>();
            //case FilterType::GradientGlow:
            //    return Box<GradientGlowFilter>();
            //case FilterType::Convolution:
            //    return Box<ConvolutionFilter>();
            //case FilterType::ColorMatrix:
            //    return Box<ColorMatrixFilter>();
            //case FilterType::GradientBevel:
            //    return Box<GradientBevelFilter>();
            default:
                return nullptr;
        }
    }
}