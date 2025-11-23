/**
 * @file    color_stream_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

 //#include "i_swf_stream_reader.h"
 //#include "swf_rgb.h"
namespace swf_reader
{
    class ISwfStreamReader;
}
namespace swf_reader::data
{
    struct SwfRgb;
    struct SwfRgba;
    class ColorStreamExt
    {
    public:
        static SwfRgb read_rgb(ISwfStreamReader& reader);

        static void read_rgb(ISwfStreamReader& reader, SwfRgb& color);

        static SwfRgba read_rgba(ISwfStreamReader& reader);

        static SwfRgba read_argb(ISwfStreamReader& reader);
    };
}