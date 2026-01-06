/**
 * @file    morph_fillstyle_factory.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include <stdexcept>

#include "cpp_base_type.h"
#include "morph_bitmap_mode.h"
#include "morph_fillstyle.h"
#include "morph_solid_fillstyle.h"
#include "morph_linear_gradient_fillstyle.h"
#include "morph_radial_gradient_fillstyle.h"
#include "morph_focal_gradient_fillstyle.h"
#include "morph_bitmap_fillstyle.h"

namespace swf_reader::shape_morphing::morph_fillstyles
{
    class MorphFillStyleFactory
    {
    public:
        [[nodiscard]] static Box<MorphFillStyle> create(const MorphFillStyleType type)
        {
            switch (type)
            {
                case MorphFillStyleType::SolidColor:
                    return boxed<MorphSolidFillStyle>();
                case MorphFillStyleType::LinearGradient:
                    return boxed<MorphLinearGradientFillStyle>();
                case MorphFillStyleType::RadialGradient:
                    return boxed<MorphRadialGradientFillStyle>();
                case MorphFillStyleType::FocalGradient:
                    return boxed<MorphFocalGradientFillStyle>();
                case MorphFillStyleType::RepeatingBitmap:
                    return boxed<MorphBitmapFillStyle>(true, MorphBitmapMode::Repeat);
                case MorphFillStyleType::ClippedBitmap:
                    return boxed<MorphBitmapFillStyle>(true, MorphBitmapMode::Clip);
                case MorphFillStyleType::NonSmoothedRepeatingBitmap:
                    return boxed<MorphBitmapFillStyle>(false, MorphBitmapMode::Repeat);
                case MorphFillStyleType::NonSmoothedClippedBitmap:
                    return boxed<MorphBitmapFillStyle>(false, MorphBitmapMode::Clip);
            }
        }
    };
}
