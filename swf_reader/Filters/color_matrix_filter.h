/**
 * @file    color_matrix_filter.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "base_filter.h"
#include "primitive_types.h"
namespace swf_reader::filters
{
    class ColorMatrixFilter : public BaseFilter
    {
    public:

        f32 r[5];
        f32 g[5];
        f32 b[5];
        f32 a[5];

        FilterType get_type() const override
        {
            return FilterType::ColorMatrix;
        }
        BaseFilter& accept_visitor(IFilterVisitor<ISwfStreamReader, BaseFilter&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}
