/**
 * @file    gradient_record_rgba.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "Data/swf_rgba.h"

namespace swf_reader::gradients
{
    class GradientRecordRgba
    {
    public:
        u8 ratio;
        data::SwfRgba color;
    };
}