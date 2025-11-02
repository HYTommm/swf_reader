/*
 * @file    shape_record_stream_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "Records/shape_record_reader.h"
#include "Records/i_shape_record_rgb.h"
#include "Records/style_change_shape_record_rgb.h"
#include "Records/style_change_shape_record_rgba.h"
#include "Records/style_change_shape_record_ex.h"
namespace swf_reader::shapes
{
    class ShapeRecordStreamExt
    {
    public:
        static records::ShapeRecordReader _shape_record_reader;
        static void ReadToShapeRecordsRgb(ISwfStreamReader& reader, Vec<Box<records::IShapeRecordRgb>>& shapeRecords);

        static void ReadToShapeRecordsRgba(ISwfStreamReader& reader, Vec<Box<records::IShapeRecordRgba>>& shapeRecords);

        static void ReadToShapeRecordsEx(ISwfStreamReader& reader, Vec<Box<records::IShapeRecordEx>>& shapeRecords);
    };
}
