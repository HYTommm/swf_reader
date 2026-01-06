/**
 * @file    morph_gradient_stream_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include "morph_linear_gradient.h"
#include "morph_focal_gradient.h"
#include "morph_gradient_record.h"
#include "i_swf_stream_reader.h"
#include "Data/color_stream_ext.h"

namespace swf_reader::morph_gradients
{
    class MorphGradientStreamExt
    {
    public:
#pragma region Linear Gradient
        static Box<MorphLinearGradient> read_linear_gradient(ISwfStreamReader& reader)
        {
            Box<MorphLinearGradient> gradient = boxed<MorphLinearGradient>();
            gradient->spread_mode = static_cast<MorphSpreadMode>(reader.read_ub(2));
            gradient->interpolation_mode = static_cast<MorphInterpolationMode>(reader.read_ub(2));
            const u32 count = reader.read_ub(4);
            gradient->gradient_records.reserve(count);
            for (u32 i = 0; i < count; i++)
            {
                gradient->gradient_records.push_back(read_gradient_record(reader));
            }
            return gradient;
        }
#pragma endregion

#pragma region Focal Gradient
        static Box<MorphFocalGradient> read_focal_gradient(ISwfStreamReader& reader)
        {
            Box<MorphFocalGradient> gradient = boxed<MorphFocalGradient>();
            gradient->spread_mode = static_cast<MorphSpreadMode>(reader.read_ub(2));
            gradient->interpolation_mode = static_cast<MorphInterpolationMode>(reader.read_ub(2));
            const u32 count = reader.read_ub(4);
            gradient->gradient_records.reserve(count);
            for (u32 i = 0; i < count; i++)
            {
                gradient->gradient_records.push_back(read_gradient_record(reader));
            }
            gradient->start_focal_point = reader.read_fixed8();
            gradient->end_focal_point = reader.read_fixed8();
            return gradient;
        }
#pragma endregion

#pragma region Gradient records
        static Box<MorphGradientRecord> read_gradient_record(ISwfStreamReader& reader)
        {
            Box<MorphGradientRecord> record = boxed<MorphGradientRecord>();
            record->start_ratio = reader.read_byte();
            record->start_color = data::ColorStreamExt::read_rgba(reader);
            record->end_ratio = reader.read_byte();
            record->end_color = data::ColorStreamExt::read_rgba(reader);
            return record;
        }
#pragma endregion
    };
}