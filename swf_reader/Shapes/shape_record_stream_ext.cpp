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
    records::ShapeRecordReader ShapeRecordStreamExt::_shape_record_reader;
    void ShapeRecordStreamExt::read_to_shape_records_rgb(ISwfStreamReader& reader, Vec<Box<records::IShapeRecord>>& shape_records)
    {
        u32 fillstyle_bits = reader.read_ub(4);
        u32 linestyle_bits = reader.read_ub(4);
        reader.align_to_byte();
        Box<records::IShapeRecord> record;
        bool is_end = false;
        do
        {
            record = _shape_record_reader.read<records::StyleChangeShapeRecordRgb>(reader, true, fillstyle_bits, linestyle_bits);
            is_end = record->get_type() == records::ShapeRecordType::EndRecord;
            shape_records.push_back(std::move(record));
        } while (!is_end);
    }

    void ShapeRecordStreamExt::read_to_shape_records_rgba(ISwfStreamReader& reader, Vec<Box<records::IShapeRecord>>& shape_records)
    {
        u32 fillstyle_bits = reader.read_ub(4);
        u32 linestyle_bits = reader.read_ub(4);
        reader.align_to_byte();
        Box<records::IShapeRecord> record;
        bool is_end = false;
        do
        {
            record = _shape_record_reader.read<records::StyleChangeShapeRecordRgba>(reader, true, fillstyle_bits, linestyle_bits);
            //auto type = record->get_type();
            //printf("type: %d\n", type);
            is_end = record->get_type() == records::ShapeRecordType::EndRecord;
            shape_records.push_back(std::move(record));
        } while (!is_end);
    }

    void ShapeRecordStreamExt::read_to_shape_records_ex(ISwfStreamReader& reader, Vec<Box<records::IShapeRecord>>& shape_records)
    {
        u32 fillstyle_bits = reader.read_ub(4);
        u32 linestyle_bits = reader.read_ub(4);
        reader.align_to_byte();
        Box<records::IShapeRecord> record;
        bool is_end = false;
        do
        {
            record = _shape_record_reader.read<records::StyleChangeShapeRecordEx>(reader, true, fillstyle_bits, linestyle_bits);
            is_end = record->get_type() == records::ShapeRecordType::EndRecord;
            shape_records.push_back(std::move(record));
        } while (!is_end);
    }
}