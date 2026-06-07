/**
 * @file    frame_label_data.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include <string>

#include "primitive_types.h"

namespace swf_reader::data
{
    struct FrameLabelData
    {
        std::string label;
        u32 frame_number{ 0 };
    };
}
