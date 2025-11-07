/**
 * @file    filter_reader.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "i_filter_visitor.h"
#include "filter_factory.h"
#include "base_filter.h"
namespace swf_reader::filters
{
    class FilterReader : public IFilterVisitor<ISwfStreamReader, BaseFilter>
    {
    private:
        FilterFactory factory_;
    public:
        Box<BaseFilter> read(ISwfStreamReader& reader);
    };
}