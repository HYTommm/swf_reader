/**
 * @file    interpolation_mode.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "cpp_base_type.h"
namespace swf_reader::gradients
{
    enum class InterpolationMode : u8
    {
        Normal = 0x00,
        Linear = 0x01,
        Reserve2 = 0x02,
        Reserve3 = 0x03
    };
}