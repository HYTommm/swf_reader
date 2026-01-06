/**
 * @file    morph_fillstyle_type.h
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
    enum class MorphFillStyleType : u8
    {
        SolidColor = 0x00,
        LinearGradient = 0x10,
        RadialGradient = 0x12,
        FocalGradient = 0x13,
        RepeatingBitmap = 0x40,
        ClippedBitmap = 0x41,
        NonSmoothedRepeatingBitmap = 0x42,
        NonSmoothedClippedBitmap = 0x43,
    };
}
