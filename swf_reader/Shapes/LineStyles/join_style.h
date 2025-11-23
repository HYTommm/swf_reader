/**
 * @file    join_style.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

namespace swf_reader::shapes::linestyles
{
    enum class JoinStyle
    {
        Round = 0,
        Bevel = 1,
        Miter = 2
    };
}