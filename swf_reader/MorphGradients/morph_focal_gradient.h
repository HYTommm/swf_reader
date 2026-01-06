/**
 * @file    morph_focal_gradient.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "base_morph_gradient.h"

namespace swf_reader::morph_gradients
{
    class MorphFocalGradient : public BaseMorphGradient
    {
    public:
        f32 start_focal_point;
        f32 end_focal_point;
    };
}
