/**
 * @file    swf_file_info.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "cpp_base_type.h"
#include "swf_format.h"

namespace swf_reader {

    struct SwfFileInfo {
        SwfFormat format{ SwfFormat::Unknown };
        u8 version{ 0 };
        u32 file_length{ 0 };
    };

}