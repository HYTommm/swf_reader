/*
 * @file    define_bits_jpeg_alpha_base.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "define_bits_jpeg_tag_base.h"

namespace swf_reader::tags::bitmap_tags
{
    class DefineBitsJpegAlphaBase : public DefineBitsJpegTagBase
    {
    public:
        Vec<u8> alpha_data;
    };
}
