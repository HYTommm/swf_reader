/*
 * @file    bevel_filter.h
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
    class BevelFilter : public BaseFilter
    {
    public:

        data::SwfRgba shadow_color{};
        data::SwfRgba highlight_color{};

        f32 blur_x;
        f32 blur_y;
        f32 angle;
        f32 distance;
        f32 strength;

        bool inner_shadow{ false };
        bool knockout{ false };
        bool composite_source{ false };
        bool on_top{ false };

        u8 passes;

        // Gets type of filter.
        FilterType get_type() const override { return FilterType::Bevel; }
        BaseFilter& accept_visitor(IFilterVisitor<ISwfStreamReader, BaseFilter&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
} // namespace swf_reader::filters
