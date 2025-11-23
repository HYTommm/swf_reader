/**
 * @file    tag_stream_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include "i_swf_stream_reader.h"

namespace swf_reader::tags
{
    class TagStreamExt
    {
    public:
        static SwfTagData read_tag_data(ISwfStreamReader& reader);
        // 注意：我们只移植读取部分，所以不实现写入方法
    };
}
