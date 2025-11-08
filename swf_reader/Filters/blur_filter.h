/*
 * @file    blur_filter.h
 *
 * C# original: BlurFilter
 * C++ port: HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include "base_filter.h"
#include "primitive_types.h"

namespace swf_reader::filters
{
    class BlurFilter : public BaseFilter
    {
    public:

        f32 blur_x;
        f32 blur_y;

        u8 passes;
        u8 reserved;

        // Gets type of filter.
        FilterType get_type() const override { return FilterType::Blur; }

        BaseFilter& accept_visitor(IFilterVisitor<ISwfStreamReader, BaseFilter&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
} // namespace swf_reader::filters
