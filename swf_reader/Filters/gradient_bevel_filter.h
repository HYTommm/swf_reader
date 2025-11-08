/**
 * @file    gradient_bevel_filter.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include "base_filter.h"
#include "cpp_base_type.h"
#include "Gradients/gradient_record_rgba.h"

namespace swf_reader::filters
{
    class GradientBevelFilter : public BaseFilter
    {
    public:
        Vec<Box<gradients::GradientRecordRgba>> gradient_records;
        f32 blur_x;
        f32 blur_y;
        f32 angle;

        f32 distance;
        f32 strength;
        bool inner_shadow;
        bool knockout;
        bool composite_source;
        bool on_top;
        u8 passes;
        FilterType get_type() const override { return FilterType::GradientBevel; }
        BaseFilter& accept_visitor(IFilterVisitor<ISwfStreamReader, BaseFilter&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}