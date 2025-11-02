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

        template<std::derived_from<StyleChangeShapeRecord> StyleChangeShapeRecord_T, std::derived_from<IShapeRecord> ReturnType>
        Box<ReturnType> read(ISwfStreamReader& reader, bool allow_big_array, u32& fill_bits_count, u32& line_bits_count)
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
                    Box<StyleChangeShapeRecord_T> style_change = boxed<StyleChangeShapeRecord_T>();
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