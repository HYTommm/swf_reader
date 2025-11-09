/**
 * @file    filter_factory.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#include "filter_factory.h"
#include "drop_shadow_filter.h"
#include "blur_filter.h"
#include "glow_filter.h"
#include "bevel_filter.h"
#include "gradient_glow_filter.h"
#include "convolution_filter.h"
#include "color_matrix_filter.h"
#include "gradient_bevel_filter.h"

namespace swf_reader::filters
{
    Box<BaseFilter> FilterFactory::create(FilterType type)
    {
        switch (type)
        {
            case FilterType::DropShadow:
                return boxed<DropShadowFilter>();
            case FilterType::Blur:
                return boxed<BlurFilter>();
            case FilterType::Glow:
                return boxed<GlowFilter>();
            case FilterType::Bevel:
                return boxed<BevelFilter>();
            case FilterType::GradientGlow:
                return boxed<GradientGlowFilter>();
            case FilterType::Convolution:
                return boxed<ConvolutionFilter>();
            case FilterType::ColorMatrix:
                return boxed<ColorMatrixFilter>();
            case FilterType::GradientBevel:
                return boxed<GradientBevelFilter>();
            default:
                throw std::runtime_error("Unknown filter type");
        }
    }
}