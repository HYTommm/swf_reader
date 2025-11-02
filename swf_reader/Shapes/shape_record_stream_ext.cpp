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
    void ShapeRecordStreamExt::ReadToShapeRecordsRgb(ISwfStreamReader& reader, Vec<Box<records::IShapeRecordRgb>>& shapeRecords)
    {
        u32 fillstyle_bits = reader.read_ub(4);
        u32 linestyle_bits = reader.read_ub(4);
        reader.align_to_byte();
        Box<records::IShapeRecordRgb> record;
        do
        {
            record = _shape_record_reader.read<records::StyleChangeShapeRecordRgb>(reader, true, fillstyle_bits, linestyle_bits);
            shapeRecords.push_back(record);
        } while (record->get_type() != records::ShapeRecordType::EndRecord);
    }

    void ShapeRecordStreamExt::ReadToShapeRecordsRgba(ISwfStreamReader& reader, Vec<Box<records::IShapeRecordRgba>>& shapeRecords)
    {
        u32 fillstyle_bits = reader.read_ub(4);
        u32 linestyle_bits = reader.read_ub(4);
        reader.align_to_byte();
        Box<records::IShapeRecordRgba> record;
        do
        {
            record = _shape_record_reader.read<records::StyleChangeShapeRecordRgba>(reader, true, fillstyle_bits, linestyle_bits);
            shapeRecords.push_back(record);
        } while (record->get_type() != records::ShapeRecordType::EndRecord);
    }

    void ShapeRecordStreamExt::ReadToShapeRecordsEx(ISwfStreamReader& reader, Vec<Box<records::IShapeRecordEx>>& shapeRecords)
    {
        u32 fillstyle_bits = reader.read_ub(4);
        u32 linestyle_bits = reader.read_ub(4);
        reader.align_to_byte();
        Box<records::IShapeRecordEx> record;
        do
        {
            record = _shape_record_reader.read<records::StyleChangeShapeRecordEx>(reader, true, fillstyle_bits, linestyle_bits);
            shapeRecords.push_back(record);
        } while (record->get_type() != records::ShapeRecordType::EndRecord);
    }
}