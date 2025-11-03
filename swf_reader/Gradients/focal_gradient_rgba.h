/**
 * @file    focal_gradient_rgba.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "base_gradient_rgba.h"

namespace swf_reader::gradients
{
    class FocalGradientRgba : public BaseGradientRgba
    {
    public:
        f64 focal_point;
    };
}
