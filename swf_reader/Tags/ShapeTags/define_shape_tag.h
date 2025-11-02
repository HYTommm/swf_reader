/**
 * @file    define_shape_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "shape_base_tag.h"
#include "Shapes/FillStyles/fillstyle_rgb.h"
#include "Shapes/LineStyles/linestyle_rgb.h"
namespace swf_reader::tags::shape_tags
{
    class DefineShapeTag : public ShapeBaseTag
    {
    public:
        Vec<Box<shapes::fillstyles::FillStyleRgb>> fill_styles;
        Vec<Box<shapes::linestyles::LineStyleRgb>> line_styles;

        // 通过 ShapeBaseTag 继承
        SwfTagBase& accept_visitor(ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& args) override
        {
            return visitor.visit(*this, args);
        }

        SwfTagType get_type() const override
        {
            return SwfTagType::DefineShape;
        }
    };
}