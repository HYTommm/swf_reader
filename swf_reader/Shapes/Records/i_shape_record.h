/**
 * @file    i_shape_record.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "i_swf_stream_reader.h"
#include "i_shape_record_visitor.h"
namespace swf_reader::shapes::records
{
    class IShapeRecord
    {
    public:
        //virtual
        virtual ~IShapeRecord() = default;

        virtual IShapeRecord& accept_visitor(
            IShapeRecordVisitor<ISwfStreamReader, IShapeRecord&>& visitor,
            ISwfStreamReader& reader,
            bool allow_big_array,
            u32& fill_bits_count,
            u32& line_bits_count) = 0;
    };
}
