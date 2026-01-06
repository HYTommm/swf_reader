/**
 * @file    morph_linestyle.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "cpp_base_type.h"
#include "Data/swf_rgba.h"
namespace swf_reader::shape_morphing::morph_linestyles
{
    struct MorphLineStyle
    {
        u16 start_width;
        u16 end_width;
        data::SwfRgba start_color;
        data::SwfRgba end_color;
    };
}