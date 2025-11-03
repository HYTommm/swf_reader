/**
 * @file    focal_gradient_rgb.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include "base_gradient_rgb.h"

namespace swf_reader::gradients
{
    class FocalGradientRgb : public BaseGradientRgb
    {
    public:
        f64 focal_point;
    };
}
