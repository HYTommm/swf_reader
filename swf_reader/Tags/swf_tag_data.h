/**
 * @file    swf_tag_data.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "cpp_base_type.h"
#include "swf_tag_types.h"

namespace swf_reader::tags
{
    // SWF 标签数据结构
    struct SwfTagData
    {
        SwfTagType type{ SwfTagType::Unknown };
        Vec<u8> data;

        SwfTagData() = default;
        SwfTagData(const SwfTagType type, Vec<u8> data) : type(type), data(std::move(data))
        {
        }
    };
}
