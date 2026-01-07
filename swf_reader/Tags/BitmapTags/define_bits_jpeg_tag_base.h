/*
 * @file    define_bits_jpeg_tag_base.h
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
    class DefineBitsJpegTagBase : public BitmapBaseTag
    {
    public:
        Vec<u8> image_data;
    };
}
