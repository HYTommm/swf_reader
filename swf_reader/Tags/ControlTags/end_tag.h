/**
 * @file    end_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "Tags/swf_tag_base.h"

namespace swf_reader::tags::control_tags
{
    class EndTag : public SwfTagBase

    {
    public:

        SwfTagBase& accept_visitor(ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
        SwfTagType get_type() const override
        {
            return SwfTagType::End;
        }
    };
}