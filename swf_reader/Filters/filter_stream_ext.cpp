/**
 * @file    filter_stream_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#include "filter_stream_ext.h"
#include "i_swf_stream_reader.h"
namespace swf_reader::filters
{
    void FilterStreamExt::read_filter_list(ISwfStreamReader& reader, Vec<Box<BaseFilter>>& filters)
    {
        u8 count = reader.read_byte();
        for (u8 i = 0; i < count; i++)
        {
            Box<BaseFilter> filter = read_filter(reader);
            filters.push_back(std::move(filter));
        }
    }
    Box<BaseFilter> FilterStreamExt::read_filter(ISwfStreamReader& reader)
    {
        return _reader.read(reader);
    }
}