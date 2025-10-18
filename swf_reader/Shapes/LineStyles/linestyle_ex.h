/**
 * @file    linestyle_ex.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "cpp_base_type.h"
#include "cap_style.h"
#include "join_style.h"
#include "linestyle_ex_flag.h"
#include "Data/swf_rgba.h"
#include "Shapes/FillStyles/fillstyle_rgba.h"
namespace swf_reader::shapes::linestyles
{
    struct LineStyleEx
    {
        u16 width;
        CapStyle start_cap_style;
        JoinStyle join_style;
        LineStyleExFlags flags;
        CapStyle end_cap_style;
        f64 miter_limit_factor;

        u8 reserved;

        data::SwfRgba color;
        Box<fillstyles::FillStyleRgba> fillstyle;
    };
}