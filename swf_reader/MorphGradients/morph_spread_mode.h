/**
 * @file    morph_spread_mode.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "cpp_base_type.h"
namespace swf_reader::morph_gradients
{
    enum class MorphSpreadMode : u8
    {
        Pad = 0x00,
        Reflect = 0x01,
        Repeat = 0x02,
        Reserve3 = 0x03
    };
}