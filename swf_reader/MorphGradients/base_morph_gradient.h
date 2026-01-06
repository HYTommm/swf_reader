/**
 * @file    base_morph_gradient.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "morph_spread_mode.h"
#include "morph_interpolation_mode.h"
#include "morph_gradient_record.h"

namespace swf_reader::morph_gradients
{
    class BaseMorphGradient
    {
    public:
        MorphSpreadMode spread_mode;
        MorphInterpolationMode interpolation_mode;

        Vec<Box<MorphGradientRecord>> gradient_records;
        BaseMorphGradient() = default;
        virtual ~BaseMorphGradient() = default;
    };
}