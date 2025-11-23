/**
 * @file    swf_rgb.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "cpp_base_type.h"

namespace swf_reader::data
{
    struct SwfRgb
    {
        u8 red{ 0 };
        u8 green{ 0 };
        u8 blue{ 0 };

        SwfRgb() = default;
        SwfRgb(const u8 red, const u8 green, const u8 blue) : red(red), green(green), blue(blue)
        {
        }
    };
}
