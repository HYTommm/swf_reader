/**
 * @file    fillstyle_stream_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "i_swf_stream_reader.h"
#include "FillStyles/fillstyle_rgb.h"
#include "FillStyles/fillstyle_rgb_reader.h"
#include "FillStyles/fillstyle_rgba_reader.h"

namespace swf_reader::shapes
{
    class FillStyleStreamExt
    {
    public:
        static fillstyles::FillStyleRgbReader _reader_rgb;
        static fillstyles::FillStyleRgbaReader _reader_rgba;
        static void read_to_fillstyles_rgb(ISwfStreamReader& reader, Vec<Box<fillstyles::FillStyleRgb>>& fillstyles, bool allow_big_array);
        static void read_to_fillstyles_rgba(ISwfStreamReader& reader, Vec<Box<fillstyles::FillStyleRgba>>& fillstyles);
        static Box<fillstyles::FillStyleRgb> read_fillstyle_rgb(ISwfStreamReader& reader);
        static Box<fillstyles::FillStyleRgba> read_fillstyle_rgba(ISwfStreamReader& reader);
    };
}
