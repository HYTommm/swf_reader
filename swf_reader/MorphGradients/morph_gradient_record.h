/**
 * @file    morph_gradient_record.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "Data/swf_rgba.h"

namespace swf_reader::morph_gradients
{
    class MorphGradientRecord
    {
    public:
        u8 start_ratio;
        data::SwfRgba start_color;
        u8 end_ratio;
        data::SwfRgba end_color;
    };
}