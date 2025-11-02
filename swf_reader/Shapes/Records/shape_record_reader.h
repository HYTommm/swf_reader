/**
 * @file    shape_record_reader.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "i_shape_record_visitor.h"
#include "Tags/swf_tag_types.h"
#include "i_swf_stream_reader.h"
#include "i_shape_record.h"
#include "style_change_shape_record.h"

#include "end_shape_record.h"
#include "straight_edge_shape_record.h"
#include "curved_edge_shape_record.h"
#include "style_change_shape_record_ex.h"
#include "style_change_shape_record_rgb.h"
#include "style_change_shape_record_rgba.h"
namespace swf_reader::shapes::records
{
    class ShapeRecordReader : public IShapeRecordVisitor<ISwfStreamReader, IShapeRecord&>
    {
    public:

        template<std::derived_from<StyleChangeShapeRecord> T>
        Box<T> read(ISwfStreamReader& reader, bool allowBigArray, u32& fillBitsCount, u32& lineBitsCount);

        IShapeRecord& visit(
            EndShapeRecord& record,
            ISwfStreamReader& reader,
            bool allow_big_array,
            u32& fill_bits_count,
            u32& line_bits_count) override;

        IShapeRecord& visit(
            StraightEdgeShapeRecord& record,
            ISwfStreamReader& reader,
            bool allow_big_array,
            u32& fill_bits_count,
            u32& line_bits_count) override;

        IShapeRecord& visit(
            CurvedEdgeShapeRecord& record,
            ISwfStreamReader& reader,
            bool allow_big_array,
            u32& fill_bits_count,
            u32& line_bits_count) override;

        IShapeRecord& visit(
            StyleChangeShapeRecordEx& record,
            ISwfStreamReader& reader,
            bool allow_big_array,
            u32& fill_bits_count,
            u32& line_bits_count) override;

        IShapeRecord& visit(
            StyleChangeShapeRecordRgb& record,
            ISwfStreamReader& reader,
            bool allow_big_array,
            u32& fill_bits_count,
            u32& line_bits_count) override;
        IShapeRecord& visit(
            StyleChangeShapeRecordRgba& record,
            ISwfStreamReader& reader,
            bool allow_big_array,
            u32& fill_bits_count,
            u32& line_bits_count) override;

        static inline Box<StyleChangeShapeRecordRgb> create_style_change_record_rgb()
        {
            return boxed<StyleChangeShapeRecordRgb>();
        }
        static inline Box<StyleChangeShapeRecordRgba> create_style_change_record_rgba()
        {
            return boxed<StyleChangeShapeRecordRgba>();
        }
        static inline Box<StyleChangeShapeRecordEx> create_style_change_record_ex()
        {
            return boxed<StyleChangeShapeRecordEx>();
        }

        //virtual void read_fillstyles(ISwfStreamReader& reader, IShapeRecord& record, bool allowBigArray) = 0;
        //virtual void read_linestyles(ISwfStreamReader& reader, IShapeRecord& record, bool allowBigArray) = 0;
    };
}