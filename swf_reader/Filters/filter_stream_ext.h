/**
 * @file filter_stream_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "filter_reader.h"
namespace swf_reader::filters
{
    class FilterStreamExt
    {
    public:
        FilterStreamExt() = delete; // 此类为静态类

        static inline FilterReader _reader;

        static void read_filter_list(ISwfStreamReader& reader, Vec<Box<BaseFilter>>& filters);
        static Box<BaseFilter> read_filter(ISwfStreamReader& reader);
    };
}
