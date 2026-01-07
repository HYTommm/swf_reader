/*
 * @file    bitmap_base_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "Tags/swf_tag_base.h"

namespace swf_reader::tags::bitmap_tags
{
    class BitmapBaseTag : public SwfTagBase
    {
    public:
        u16 character_id;
    };
}
