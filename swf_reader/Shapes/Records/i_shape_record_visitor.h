/**
 * @file   i_shape_record_visitor.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
 //#include "end_shape_record.h"
#include "cpp_base_type.h"
namespace swf_reader::shapes::records
{
    class EndShapeRecord;
    class StyleChangeShapeRecordEx;
    class StraightEdgeShapeRecord;
    class CurvedEdgeShapeRecord;
    template<typename TArg, typename TResult>
    class IShapeRecordVisitor
    {
    public:
        virtual TResult& visit(
            EndShapeRecord& record,
            TArg& arg,
            bool allow_big_array,
            u32& fill_bits_count,
            u32& line_bits_count) = 0;
        //virtual TResult visit(StyleChangeShapeRecordRGB& record, TArg& arg) = 0;
        //virtual TResult visit(StyleChangeShapeRecordRGBA& record, TArg& arg) = 0;
        virtual TResult visit(
            StyleChangeShapeRecordEx& record,
            TArg& arg,
            bool allow_big_array,
            u32& fill_bits_count,
            u32& line_bits_count) = 0;
        virtual TResult visit(
            StraightEdgeShapeRecord& record,
            TArg& arg,
            bool allow_big_array,
            u32& fill_bits_count,
            u32& line_bits_count) = 0;
        virtual TResult visit(
            CurvedEdgeShapeRecord& record,
            TArg& arg,
            bool allow_big_array,
            u32& fill_bits_count,
            u32& line_bits_count) = 0;
        virtual ~IShapeRecordVisitor() = default;
    };
}
