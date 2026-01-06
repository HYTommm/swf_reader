/**
 * @file    define_morph_shape_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "shape_morphing_base_tag.h"

#include "ShapeMorphing/MorphFillStyles/morph_fillstyle.h"
#include "ShapeMorphing/MorphLineStyles/morph_linestyle.h"

namespace swf_reader::tags::shape_morphing_tags
{
    class DefineMorphShapeTag : public ShapeMorphingBaseTag
    {
    public:

        Vec<Box<shape_morphing::morph_fillstyles::MorphFillStyle>> fill_styles;
        Vec<Box<shape_morphing::morph_linestyles::MorphLineStyle>> line_styles;
        Vec<Box<shapes::records::IShapeRecordRgb>> start_edge;
        Vec<Box<shapes::records::IShapeRecordRgb>> end_edge;

        [[nodiscard]] SwfTagType get_type() const override
        {
            return SwfTagType::DefineMorphShape;
        }
        SwfTagBase& accept_visitor(ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}
