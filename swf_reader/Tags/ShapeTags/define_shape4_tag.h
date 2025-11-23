/**
 * @file define_shape4_tag.h
 *
 * Original C# implementation: Copyright (c)2018 Sergey Savchuk
 * C++ port: Copyright (c)2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "shape_base_tag.h"
#include "Data/swf_rect.h"
#include "Shapes/FillStyles/fillstyle_rgba.h"
#include "Shapes/LineStyles/linestyle_ex.h"
#include "Shapes/Records/i_shape_record_ex.h"
#include "define_shape4_flag.h"

namespace swf_reader::tags::shape_tags
{
    class DefineShape4Tag : public ShapeBaseTag
    {
    public:
        data::SwfRect edge_bounds;

        Vec<Box<shapes::fillstyles::FillStyleRgba>> fill_styles;
        Vec<Box<shapes::linestyles::LineStyleEx>> line_styles;
        Vec<Box<shapes::records::IShapeRecordEx>> shape_records;

        DefineShape4Flags flags;

        //通过 ShapeBaseTag继承
        SwfTagBase& accept_visitor(ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& args) override
        {
            return visitor.visit(*this, args);
        }

        SwfTagType get_type() const override
        {
            return SwfTagType::DefineShape4;
        }

        bool uses_fill_winding_rule() const
        {
            return flags.get(DefineShape4Flag::UsesFillWindingRule);
        }
        bool uses_non_scaling_strokes() const
        {
            return flags.get(DefineShape4Flag::UsesNonScalingStrokes);
        }
        bool uses_scaling_strokes() const
        {
            return flags.get(DefineShape4Flag::UsesScalingStrokes);
        }
        u8 reserved_flags() const
        {
            return static_cast<u8>(flags.reserved());
        }
    };
}
