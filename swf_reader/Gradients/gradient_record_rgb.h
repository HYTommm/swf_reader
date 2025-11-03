/*
 * @file    gradient_record_rgb.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include "Data/swf_rgb.h"

namespace swf_reader::gradients
{
    class GradientRecordRgb
    {
    public:
        u8 ratio;
        data::SwfRgb color;
    };
}
