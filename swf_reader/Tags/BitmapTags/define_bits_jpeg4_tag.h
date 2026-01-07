/*
 * @file    define_bits_jpeg4_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "define_bits_jpeg_alpha_base.h"

namespace swf_reader::tags::bitmap_tags
{
    class DefineBitsJpeg4Tag : public DefineBitsJpegAlphaBase
    {
    public:
        u16 deblock_param;

        [[nodiscard]] SwfTagType get_type() const override
        {
            return SwfTagType::DefineBitsJPEG3;
        }

        SwfTagBase& accept_visitor(ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}
