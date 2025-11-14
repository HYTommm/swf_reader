/**
 * @file    show_frame_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include "display_list_base_tag.h"
namespace swf_reader::tags::display_list_tags
{
    class ShowFrameTag : public DisplayListBaseTag
    {
    public:
        SwfTagType get_type() const override { return SwfTagType::ShowFrame; }
        SwfTagBase& accept_visitor(ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}
