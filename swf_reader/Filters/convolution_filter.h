/**
 * @file    convolution_filter.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include "base_filter.h"
#include "cpp_base_type.h"
#include "Data/swf_rgba.h"
namespace swf_reader::filters
{
    class ConvolutionFilter : public BaseFilter
    {
    public:
        u8 matrix_x;
        u8 matrix_y;
        f32 divider;
        f32 bias;
        Vec<f32> matrix;
        data::SwfRgba default_color;
        u8 reserved;
        bool clamp;
        bool preserve_alpha;

        FilterType get_type() const override { return FilterType::Convolution; }
        BaseFilter& accept_visitor(IFilterVisitor<ISwfStreamReader, BaseFilter&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}
