/**
 * @file    morph_bitmap_mode.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "primitive_types.h"
namespace swf_reader::shape_morphing::morph_fillstyles
{
    enum class MorphBitmapMode : u8
    {
        Repeat = 0,
        Clip = 1
    };
}
