/**
 * @file    place_object2_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include <string>

#include "place_object3_flag.h"
#include "place_object_base_tag.h"
#include "ClipActions/clip_actions_list.h"
#include "Data/color_transform_rgba.h"
#include "Filters/base_filter.h"
#include "Data/blend_mode.h"
#include "Data/swf_rgba.h"

namespace swf_reader::tags::display_list_tags
{
    class PlaceObject3Tag : public PlaceObjectBaseTag
    {
    public:

        PlaceObject3Tag() = default;
        PlaceObject3Tag(const PlaceObject3Tag&) = default;
        PlaceObject3Flags flags;

        std::string class_name;
        data::ColorTransformRgba color_tranform;
        u16 ratio;
        std::string name;
        u16 clip_depth;
        Vec<Box<filters::BaseFilter>> filters;
        data::BlendMode blend_mode;
        u8 bitmap_cache;
        u8 visible;
        data::SwfRgba background_color;
        clip_actions::ClipActionsList clip_actions;

        SwfTagType get_type() const override { return SwfTagType::PlaceObject3; }
        SwfTagBase& accept_visitor(ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}