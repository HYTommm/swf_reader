/**
 * @file    shape_record_reader.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#include "shape_record_reader.h"
#include "style_change_record_flag.h"
#include "../fillstyle_stream_ext.h"
#include "../linestyle_stream_ext.h"

namespace swf_reader::shapes::records
{
    template<std::derived_from<StyleChangeShapeRecord> T>
    Box<T> ShapeRecordReader::read(
        ISwfStreamReader& reader,
        bool allow_big_array,
        u32& fill_bits_count,
        u32& line_bits_count)
    {
        bool is_edge = reader.read_bit();
        if (is_edge)
        {
            bool straight = reader.read_bit();
            if (straight)
            {
                Box<StraightEdgeShapeRecord> straight_edge = boxed<StraightEdgeShapeRecord>();
                straight_edge->accept_visitor(*this, reader, allow_big_array, fill_bits_count, line_bits_count);
                return straight_edge;
            }
            else
            {
                Box<CurvedEdgeShapeRecord> curved_edge = boxed<CurvedEdgeShapeRecord>();
                curved_edge->accept_visitor(*this, reader, allow_big_array, fill_bits_count, line_bits_count);
                return curved_edge;
            }
        }
        else
        {
            StyleChangeRecordFlags flags{};
            flags.set(StyleChangeRecordFlag::StateNewStyles, reader.read_bit());
            flags.set(StyleChangeRecordFlag::StateLineStyle, reader.read_bit());
            flags.set(StyleChangeRecordFlag::StateFillStyle1, reader.read_bit());
            flags.set(StyleChangeRecordFlag::StateFillStyle0, reader.read_bit());
            flags.set(StyleChangeRecordFlag::StateMoveTo, reader.read_bit());

            if (static_cast<u8>(flags.flags))
            {
                Box<StyleChangeShapeRecord> style_change = boxed<T>();
                style_change->flags = flags;
                style_change->accept_visitor(*this, reader, allow_big_array, fill_bits_count, line_bits_count);
                return style_change;
            }
            else
            {
                Box<EndShapeRecord> end_shape = boxed<EndShapeRecord>();
                end_shape->accept_visitor(*this, reader, allow_big_array, fill_bits_count, line_bits_count);
                return end_shape;
            }
        }
    }

    IShapeRecord& ShapeRecordReader::visit(
        EndShapeRecord& record,
        ISwfStreamReader& reader,
        bool allow_big_array,
        u32& fill_bits_count,
        u32& line_bits_count)
    {
        return record;
    }

    IShapeRecord& ShapeRecordReader::visit(
        StraightEdgeShapeRecord& record,
        ISwfStreamReader& reader,
        bool allow_big_array,
        u32& fill_bits_count,
        u32& line_bits_count)
    {
        u32 num_bits = reader.read_ub(4) + 2;
        bool general_line_flag = reader.read_bit();
        bool vert_line_flag = false;
        if (!general_line_flag)    vert_line_flag = reader.read_bit();
        if (general_line_flag || !vert_line_flag)    record.delta_x = reader.read_sb(num_bits);
        if (general_line_flag || vert_line_flag)    record.delta_y = reader.read_sb(num_bits);
        return record;
    }

    IShapeRecord& ShapeRecordReader::visit(
        CurvedEdgeShapeRecord& record,
        ISwfStreamReader& reader,
        bool allow_big_array,
        u32& fill_bits_count,
        u32& line_bits_count)
    {
        u32 num_bits = reader.read_ub(4) + 2;
        record.control_delta_x = reader.read_sb(num_bits);
        record.control_delta_y = reader.read_sb(num_bits);
        record.anchor_delta_x = reader.read_sb(num_bits);
        record.anchor_delta_y = reader.read_sb(num_bits);
        return record;
    }

    void record_read_helper(
        StyleChangeShapeRecord& record,
        ISwfStreamReader& reader,
        u32& fill_bits_count,
        u32& line_bits_count)
    {
        if (record.flags.get(StyleChangeRecordFlag::StateMoveTo))
        {
            u32 move_bit = reader.read_ub(5);
            record.move_delta_x = reader.read_sb(move_bit);
            record.move_delta_y = reader.read_sb(move_bit);
        }
        if (record.flags.get(StyleChangeRecordFlag::StateFillStyle0))    record.fillstyle0 = reader.read_ub(fill_bits_count);
        if (record.flags.get(StyleChangeRecordFlag::StateFillStyle1))    record.fillstyle1 = reader.read_ub(fill_bits_count);
        if (record.flags.get(StyleChangeRecordFlag::StateLineStyle))     record.linestyle = reader.read_ub(line_bits_count);
    }

    IShapeRecord& ShapeRecordReader::visit(
        StyleChangeShapeRecordEx& record,
        ISwfStreamReader& reader,
        bool allow_big_array,
        u32& fill_bits_count,
        u32& line_bits_count)
    {
        record_read_helper(record, reader, fill_bits_count, line_bits_count);
        if (record.flags.get(StyleChangeRecordFlag::StateNewStyles))
        {
            FillStyleStreamExt::read_to_fillstyles_rgba(reader, record.FillStyles);
            LineStyleStreamExt::read_to_linestyles_ex(reader, record.LineStyles);
            fill_bits_count = reader.read_ub(4);
            line_bits_count = reader.read_ub(4);
        }
        return record;
    }
    IShapeRecord& ShapeRecordReader::visit(
        StyleChangeShapeRecordRgb& record,
        ISwfStreamReader& reader,
        bool allow_big_array,
        u32& fill_bits_count,
        u32& line_bits_count)
    {
        record_read_helper(record, reader, fill_bits_count, line_bits_count);
        if (record.flags.get(StyleChangeRecordFlag::StateNewStyles))
        {
            FillStyleStreamExt::read_to_fillstyles_rgb(reader, record.FillStyles, allow_big_array);
            LineStyleStreamExt::read_to_linestyles_rgb(reader, record.LineStyles, allow_big_array);
            fill_bits_count = reader.read_ub(4);
            line_bits_count = reader.read_ub(4);
        }
        return record;
    }

    IShapeRecord& ShapeRecordReader::visit(
        StyleChangeShapeRecordRgba& record,
        ISwfStreamReader& reader,
        bool allow_big_array,
        u32& fill_bits_count,
        u32& line_bits_count)
    {
        record_read_helper(record, reader, fill_bits_count, line_bits_count);
        if (record.flags.get(StyleChangeRecordFlag::StateNewStyles))
        {
            FillStyleStreamExt::read_to_fillstyles_rgba(reader, record.FillStyles);
            LineStyleStreamExt::read_to_linestyles_rgba(reader, record.LineStyles);
            fill_bits_count = reader.read_ub(4);
            line_bits_count = reader.read_ub(4);
        }
        return record;
    }
} // namespace swf_reader::shapes::records