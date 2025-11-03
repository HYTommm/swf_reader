/**
 * @file    gradient_stream_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "linear_gradient_rgb.h"
#include "linear_gradient_rgba.h"
#include "focal_gradient_rgb.h"
#include "focal_gradient_rgba.h"
#include "i_swf_stream_reader.h"
#include "Data/color_stream_ext.h"
namespace swf_reader::gradients
{
    class GradientStreamExt
    {
    public:
#pragma region Linear Gradient
        static Box<LinearGradientRgb> read_linear_gradient_rgb(ISwfStreamReader& reader)
        {
            Box<LinearGradientRgb> gradient = boxed<LinearGradientRgb>();
            gradient->spread_mode = static_cast<SpreadMode>(reader.read_ub(2));
            gradient->interpolation_mode = static_cast<InterpolationMode>(reader.read_ub(2));
            const u32 count = reader.read_ub(4);
            for (u32 i = 0; i < count; i++)
            {
                gradient->gradient_records.push_back(GradientStreamExt::read_gradient_record_rgb(reader));
            }
            return gradient;
        }

        static Box<LinearGradientRgba> read_linear_gradient_rgba(ISwfStreamReader& reader)
        {
            Box<LinearGradientRgba> gradient = boxed<LinearGradientRgba>();
            gradient->spread_mode = static_cast<SpreadMode>(reader.read_ub(2));
            gradient->interpolation_mode = static_cast<InterpolationMode>(reader.read_ub(2));
            const u32 count = reader.read_ub(4);
            for (u32 i = 0; i < count; i++)
            {
                gradient->gradient_records.push_back(GradientStreamExt::read_gradient_record_rgba(reader));
            }
            return gradient;
        }

#pragma endregion

#pragma region Focal Gradient

        static Box<FocalGradientRgb> read_focal_gradient_rgb(ISwfStreamReader& reader)
        {
            Box<FocalGradientRgb> gradient = boxed<FocalGradientRgb>();
            gradient->spread_mode = static_cast<SpreadMode>(reader.read_ub(2));
            gradient->interpolation_mode = static_cast<InterpolationMode>(reader.read_ub(2));

            const u32 count = reader.read_ub(4);
            for (u32 i = 0; i < count; i++)
            {
                gradient->gradient_records.push_back(GradientStreamExt::read_gradient_record_rgb(reader));
            }
            gradient->focal_point = reader.read_fixed8();
            return gradient;
        }

        static Box<FocalGradientRgba> read_focal_gradient_rgba(ISwfStreamReader& reader)
        {
            Box<FocalGradientRgba> gradient = boxed<FocalGradientRgba>();
            gradient->spread_mode = static_cast<SpreadMode>(reader.read_ub(2));
            gradient->interpolation_mode = static_cast<InterpolationMode>(reader.read_ub(2));
            const u32 count = reader.read_ub(4);
            for (u32 i = 0; i < count; i++)
            {
                gradient->gradient_records.push_back(GradientStreamExt::read_gradient_record_rgba(reader));
            }
            gradient->focal_point = reader.read_fixed8();
            return gradient;
        }

#pragma endregion

#pragma region Gradient records

        static Box<GradientRecordRgb> read_gradient_record_rgb(ISwfStreamReader& reader)
        {
            Box<GradientRecordRgb> record = boxed<GradientRecordRgb>();
            record->ratio = reader.read_ui16();
            record->color = data::ColorStreamExt::read_rgb(reader);
            return record;
        }

        static Box<GradientRecordRgba> read_gradient_record_rgba(ISwfStreamReader& reader)
        {
            Box<GradientRecordRgba> record = boxed<GradientRecordRgba>();
            record->ratio = reader.read_ui16();
            record->color = data::ColorStreamExt::read_rgba(reader);
            return record;
        }

#pragma endregion
    };
}
