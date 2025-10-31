/**
 * @file    i_shape_record_rgb.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "i_shape_record.h"
namespace swf_reader::shapes::records
{
    class IShapeRecordRgb : public virtual IShapeRecord
    {
    public:
        virtual ~IShapeRecordRgb() = default;
    };
}