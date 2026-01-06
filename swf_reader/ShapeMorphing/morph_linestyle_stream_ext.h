/**
 * @file    morph_linestyle_stream_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "i_swf_stream_reader.h"
#include "MorphLineStyles/morph_linestyle.h"
#include "MorphLineStyles/morph_linestyle_ex.h"

namespace swf_reader::shape_morphing
{
    class MorphLineStyleStreamExt
    {
    public:
        static void read_to_linestyles(ISwfStreamReader& reader, Vec<Box<morph_linestyles::MorphLineStyle>>& line_styles);
        static void read_to_linestyles_ex(ISwfStreamReader& reader, Vec<Box<morph_linestyles::MorphLineStyleEx>>& line_styles);
        static Box<morph_linestyles::MorphLineStyle> read_linestyle(ISwfStreamReader& reader);
        static Box<morph_linestyles::MorphLineStyleEx> read_linestyle_ex(ISwfStreamReader& reader);
    };
}