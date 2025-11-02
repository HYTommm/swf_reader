/**
 * @file    straight_edge_shape_record.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "i_shape_record_rgb.h"
#include "i_shape_record_rgba.h"
#include "i_shape_record_ex.h"
namespace swf_reader::shapes::records
{
    class StraightEdgeShapeRecord : public IShapeRecordRgb, public IShapeRecordRgba, public IShapeRecordEx
    {
    public:
        int delta_x;
        int delta_y;

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
