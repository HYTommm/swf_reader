/**
 * @file    shape_record_type.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "cpp_base_type.h"
namespace swf_reader::shapes::records
{
    enum class ShapeRecordType : u8
    {
        EndRecord,
        StyleChangeRecord,
        StraightEdge,
        CurvedEdgeRecord
    };
}
