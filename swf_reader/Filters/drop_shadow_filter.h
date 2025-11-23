/*
 * @file    drop_shadow_filter.h
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
    class DropShadowFilter : public BaseFilter
    {
    public:

        data::SwfRgba color;
        f32 blur_x;
        f32 blur_y;
        f32 angle;
        f32 distance;
        f32 strength;
        bool inner_shadow;
        bool knockout;
        bool composite_source;
        u8 passes;

        FilterType get_type() const override
        {
            return FilterType::DropShadow;
        }
        BaseFilter& accept_visitor(IFilterVisitor<ISwfStreamReader, BaseFilter&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}
