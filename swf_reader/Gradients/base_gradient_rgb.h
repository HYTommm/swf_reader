/**
 * @file    base_gradient_rgb.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "spread_mode.h"
#include "interpolation_mode.h"
#include "gradient_record_rgb.h"
namespace swf_reader::gradients
{
    class BaseGradientRgb
    {
    public:
        SpreadMode spread_mode;
        InterpolationMode interpolation_mode;

        Vec<Box<GradientRecordRgb>> gradient_records;
        BaseGradientRgb() = default;
        virtual ~BaseGradientRgb() = default;
    };
}
