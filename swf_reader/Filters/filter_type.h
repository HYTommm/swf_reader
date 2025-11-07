/*
 * @file    filter_type.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "primitive_types.h"
namespace swf_reader::filters
{
    enum class FilterType : u8
    {
        DropShadow = 0,
        Blur = 1,
        Glow = 2,
        Bevel = 3,
        GradientGlow = 4,
        Convolution = 5,
        ColorMatrix = 6,
        GradientBevel = 7
    };
}
