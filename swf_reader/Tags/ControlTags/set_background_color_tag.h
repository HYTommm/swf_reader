/**
 * @file     set_background_color_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include "Tags/swf_tag_base.h"
#include "Data/swf_rgb.h"
namespace swf_reader::tags::control_tags
{
    class SetBackgroundColorTag : public SwfTagBase
    {
    public:
        data::SwfRgb color;
        SwfTagType get_type() const override
        {
            return SwfTagType::SetBackgroundColor;
        }
        SwfTagBase& accept_visitor(ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}
