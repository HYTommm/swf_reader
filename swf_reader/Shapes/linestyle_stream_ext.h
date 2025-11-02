/**
 * @file    linestyle_stream_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "i_swf_stream_reader.h"
#include "LineStyles/linestyle_rgb.h"
#include "LineStyles/linestyle_rgba.h"
#include "LineStyles/linestyle_ex.h"
namespace swf_reader::shapes
{
    class LineStyleStreamExt
    {
    public:
        static void read_to_linestyles_rgb(ISwfStreamReader& reader, Vec<Box<linestyles::LineStyleRgb>>& lineStyles, bool allowBigArray);
        static void read_to_linestyles_rgba(ISwfStreamReader& reader, Vec<Box<linestyles::LineStyleRgba>>& lineStyles);
        static void read_to_linestyles_ex(ISwfStreamReader& reader, Vec<Box<linestyles::LineStyleEx>>& lineStyles);
        static Box<linestyles::LineStyleRgb> read_linestyle_rgb(ISwfStreamReader& reader);
        static Box<linestyles::LineStyleRgba> read_linestyle_rgba(ISwfStreamReader& reader);
        static Box<linestyles::LineStyleEx> read_linestyle_ex(ISwfStreamReader& reader);
    };
}