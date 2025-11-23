/**
 * @file    place_object_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "place_object_base_tag.h"
#include "Data/color_transform_rgb.h"

namespace swf_reader::tags::display_list_tags
{
    class PlaceObjectTag : public PlaceObjectBaseTag
    {
    public:
        Box<data::ColorTransformRGB> color_transform = nullptr;

        //PlaceObjectTag() {
        //	tag_type = SwfTagType::PlaceObject;
        //}

        SwfTagType get_type() const override
        {
            return SwfTagType::PlaceObject;
        }

        SwfTagBase& accept_visitor(ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}
