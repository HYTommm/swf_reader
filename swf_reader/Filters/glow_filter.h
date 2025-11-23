/**
 * @file    glow_filter.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include "base_filter.h"
#include "Data/swf_rgba.h"
#include "primitive_types.h"
namespace swf_reader::filters
{
    class GlowFilter : public BaseFilter
    {
    public:

        data::SwfRgba color;
        f64 blur_x;
        f64 blur_y;
        f64 strength;
        bool inner_glow;
        bool knockout;
        bool composite_source;
        u32 passes;

        FilterType get_type() const override
        {
            return FilterType::Glow;
        }
        BaseFilter& accept_visitor(IFilterVisitor<ISwfStreamReader, BaseFilter&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}
