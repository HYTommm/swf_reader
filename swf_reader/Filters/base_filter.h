/*
 * @file    base_filter.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include "filter_type.h"
#include "i_filter_visitor.h"

namespace swf_reader
{
    class ISwfStreamReader;
}
namespace swf_reader::filters
{
    class BaseFilter
    {
    public:

        virtual FilterType get_type() const = 0;
        virtual BaseFilter& accept_visitor(IFilterVisitor<ISwfStreamReader, BaseFilter&>& visitor, ISwfStreamReader& reader) = 0;
    };
}