/**
 * @file    swf_header.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "cpp_base_type.h"
#include "swf_rect.h"

namespace swf_reader::data
{
    struct SwfHeader
    {
        SwfRect frame_size;
        f64 frame_rate{ 0.0 };
        u16 frame_count{ 0 };
    };
}
