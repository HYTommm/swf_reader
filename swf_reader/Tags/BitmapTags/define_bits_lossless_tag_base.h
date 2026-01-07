/*
 * @file    define_bits_lossless_tag_base.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "bitmap_base_tag.h"

namespace swf_reader::tags::bitmap_tags
{
    class DefineBitsLosslessTagBase : public BitmapBaseTag
    {
    public:
        u8 bitmap_format;
        u16 bitmap_width;
        u16 bitmap_height;
        u8 bitmap_color_table_size;
        Vec<u8> zlib_bitmap_data;
    };
}
