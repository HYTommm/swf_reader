/**
 * @file    morph_linestyle_ex.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "cpp_base_type.h"
#include "morph_cap_style.h"
#include "morph_join_style.h"
#include "morph_linestyle_ex_flag.h"
#include "Data/swf_rgba.h"
#include "ShapeMorphing/MorphFillStyles/morph_fillstyle.h"
namespace swf_reader::shape_morphing::morph_linestyles
{
    struct MorphLineStyleEx
    {
        u16 start_width;
        u16 end_width;
        MorphCapStyle start_cap_style;
        MorphJoinStyle join_style;
        MorphLineStyleExFlags flags;
        MorphCapStyle end_cap_style;
        f64 miter_limit_factor;

        u8 reserved;

        data::SwfRgba start_color;
        data::SwfRgba end_color;
        Box<morph_fillstyles::MorphFillStyle> fillstyle;
    };
}