/**
 * @file    filter_factory.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include <stdexcept>
#include "cpp_base_type.h"
#include "base_filter.h"

#pragma once

namespace swf_reader::filters
{
    class FilterFactory
    {
    public:
        Box<BaseFilter> create(FilterType type);
    };
}
