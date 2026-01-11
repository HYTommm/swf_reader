/**
 * @file    shape_base_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "Tags/swf_tag_base.h"
#include "Data/swf_rect.h"
#include "Shapes/Records/i_shape_record.h"

namespace swf_reader::tags::shape_tags
{
    class ShapeBaseTag : public SwfTagBase
    {
    public:
        u16 shape_id;
        data::SwfRect shape_bounds;
        Vec<Box<shapes::records::IShapeRecord>> shape_records;
        ShapeBaseTag() = default;
        virtual ~ShapeBaseTag() = default;
    };
}
