/**
 * @file    base_gradient_rgba.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "spread_mode.h"
#include "interpolation_mode.h"
#include "gradient_record_rgba.h"

namespace swf_reader::gradients
{
    class BaseGradientRgba
    {
    public:
        SpreadMode spread_mode;
        InterpolationMode interpolation_mode;

        Vec<Box<GradientRecordRgba>> gradient_records;
        BaseGradientRgba() = default;
        virtual ~BaseGradientRgba() = default;
    };
}