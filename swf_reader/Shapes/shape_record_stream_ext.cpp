/**
 * @file    shape_record_stream_ext.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#include "shape_record_stream_ext.h"

namespace swf_reader::shapes
{
    inline void ShapeRecordStreamExt::ReadToShapeRecordsRgb(ISwfStreamReader& reader, Vec<Box<records::IShapeRecordRgb>>& shapeRecords)
    {
        u32 fillstyle_bits = reader.read_ub(4);
        u32 linestyle_bits = reader.read_ub(4);
        reader.align_to_byte();
        Box<records::IShapeRecordRgb> record;
        bool is_end = false;
        do
        {
            record = _shape_record_reader.read<records::StyleChangeShapeRecordRgb>(reader, true, fillstyle_bits, linestyle_bits);
            is_end = record->get_type() == records::ShapeRecordType::EndRecord;
            shapeRecords.push_back(std::move(record));
        } while (!is_end);
    }

    inline void ShapeRecordStreamExt::ReadToShapeRecordsRgba(ISwfStreamReader& reader, Vec<Box<records::IShapeRecordRgba>>& shapeRecords)
    {
        u32 fillstyle_bits = reader.read_ub(4);
        u32 linestyle_bits = reader.read_ub(4);
        reader.align_to_byte();
        Box<records::IShapeRecordRgba> record;
        bool is_end = false;
        do
        {
            record = _shape_record_reader.read<records::StyleChangeShapeRecordRgba>(reader, true, fillstyle_bits, linestyle_bits);
            is_end = record->get_type() == records::ShapeRecordType::EndRecord;
            shapeRecords.push_back(std::move(record));
        } while (!is_end);
    }

    inline void ShapeRecordStreamExt::ReadToShapeRecordsEx(ISwfStreamReader& reader, Vec<Box<records::IShapeRecordEx>>& shapeRecords)
    {
        u32 fillstyle_bits = reader.read_ub(4);
        u32 linestyle_bits = reader.read_ub(4);
        reader.align_to_byte();
        Box<records::IShapeRecordEx> record;
        bool is_end = false;
        do
        {
            record = _shape_record_reader.read<records::StyleChangeShapeRecordEx>(reader, true, fillstyle_bits, linestyle_bits);
            is_end = record->get_type() == records::ShapeRecordType::EndRecord;
            shapeRecords.push_back(std::move(record));
        } while (!is_end);
    }
}