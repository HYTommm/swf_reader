/**
 * @file    shape_record_reader.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#include "shape_record_reader.h"

#include "straight_edge_shape_record.h"
#include "curved_edge_shape_record.h"
#include "style_change_record_flag.h"
#include "end_shape_record.h"
#include "style_change_shape_record.h"
#include "style_change_shape_record_ex.h"

namespace swf_reader::shapes::records
{
    Box<IShapeRecord> ShapeRecordReader::read(
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
                Box<StyleChangeShapeRecord> style_change = create_style_change_record();
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
        return {};
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

    IShapeRecord& ShapeRecordReader::visit(
        StyleChangeShapeRecordEx& record,
        ISwfStreamReader& reader,
        bool allow_big_array,
        u32& fill_bits_count,
        u32& line_bits_count)
    {
        if (record.flags.get(StyleChangeRecordFlag::StateMoveTo))
        {
            u32 move_bit = reader.read_ub(5);
            record.move_delta_x = reader.read_sb(move_bit);
            record.move_delta_y = reader.read_sb(move_bit);
        }
        if (record.flags.get(StyleChangeRecordFlag::StateFillStyle0))
            record.fillstyle0 = reader.read_ub(fill_bits_count);
        if (record.flags.get(StyleChangeRecordFlag::StateFillStyle1))
            record.fillstyle1 = reader.read_ub(fill_bits_count);
        if (record.flags.get(StyleChangeRecordFlag::StateLineStyle))
            record.linestyle = reader.read_ub(line_bits_count);
        if (record.flags.get(StyleChangeRecordFlag::StateNewStyles))
        {
            read_fillstyles(reader, record, allow_big_array);
            read_linestyles(reader, record, allow_big_array);
            fill_bits_count = reader.read_ub(4);
            line_bits_count = reader.read_ub(4);
        }
        return record;
    }
} // namespace swf_reader::shapes::records