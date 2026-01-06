/**
 * @file    define_morph_shape2_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "shape_morphing_base_tag.h"
#include "ShapeMorphing/MorphFillStyles/morph_fillstyle.h"
#include "ShapeMorphing/MorphLineStyles/morph_linestyle_ex.h"

namespace swf_reader::tags::shape_morphing_tags
{
    class DefineMorphShape2Tag : public ShapeMorphingBaseTag
    {
    public:

        data::SwfRect start_edge_bounds;
        data::SwfRect end_edge_bounds;

        bool uses_non_scaling_strokes;
        bool uses_scaling_strokes;

        Vec<Box<shape_morphing::morph_fillstyles::MorphFillStyle>> fill_styles;
        Vec<Box<shape_morphing::morph_linestyles::MorphLineStyleEx>> line_styles;
        Vec<Box<shapes::records::IShapeRecordRgb>> start_edge;
        Vec<Box<shapes::records::IShapeRecordRgb>> end_edge;

        [[nodiscard]] SwfTagType get_type() const override
        {
            return SwfTagType::DefineMorphShape2;
        }
        SwfTagBase& accept_visitor(ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}
