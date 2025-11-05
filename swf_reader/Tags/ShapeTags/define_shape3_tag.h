/**
 * @file define_shape3_tag.h
 *
 * Original C# implementation: Copyright (c)2018 Sergey Savchuk
 * C++ port: Copyright (c)2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "shape_base_tag.h"
#include "Shapes/FillStyles/fillstyle_rgba.h"
#include "Shapes/LineStyles/linestyle_rgba.h"
#include "Shapes/Records/i_shape_record_rgba.h"
namespace swf_reader::tags::shape_tags
{
    class DefineShape3Tag : public ShapeBaseTag
    {
    public:
        Vec<Box<shapes::fillstyles::FillStyleRgba>> fill_styles;
        Vec<Box<shapes::linestyles::LineStyleRgba>> line_styles;
        Vec<Box<shapes::records::IShapeRecordRgba>> shape_records;

        //Í¨¹ý ShapeBaseTag¼Ì³Ð
        SwfTagBase& accept_visitor(ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& args) override
        {
            return visitor.visit(*this, args);
        }

        SwfTagType get_type() const override
        {
            return SwfTagType::DefineShape3;
        }
    };
}
