/**
 * @file    style_change_shape_record_rgba.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "style_change_shape_record.h"
#include "i_shape_record_rgba.h"
#include "../FillStyles/fillstyle_rgba.h"
#include "../LineStyles/linestyle_rgba.h"

namespace swf_reader::shapes::records
{
    class StyleChangeShapeRecordRgba : public StyleChangeShapeRecord, public IShapeRecordRgba
    {
    public:
        Vec<Box<fillstyles::FillStyleRgba>> FillStyles;
        Vec<Box<linestyles::LineStyleRgba>> LineStyles;

        IShapeRecord& accept_visitor(
            IShapeRecordVisitor<ISwfStreamReader, IShapeRecord&>& visitor,
            ISwfStreamReader& reader,
            bool allow_big_array,
            u32& fill_bits_count,
            u32& line_bits_count) override
        {
            return visitor.visit(*this, reader, allow_big_array, fill_bits_count, line_bits_count);
        }
    };
}
