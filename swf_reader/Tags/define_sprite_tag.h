/**
 * @file    define_sprite_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "swf_tag_base.h"

namespace swf_reader::tags
{
    class DefineSpriteTag : public SwfTagBase
    {
    public:
        u16 sprite_id;
        u16 frames_count;
        Vec<Box<SwfTagBase>> tags;

        // Í¨¹ý SwfTagBase ¼Ì³Ð
        SwfTagBase& accept_visitor(ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
        SwfTagType get_type() const override
        {
            return SwfTagType::DefineSprite;
        }
    };
}