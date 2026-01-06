/**
 * @file    morph_fillstyle_stream_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "MorphFillStyles/morph_fillstyle_reader.h"

namespace swf_reader::shape_morphing
{
    class MorphFillStyleStreamExt
    {
        static morph_fillstyles::MorphFillStyleReader _reader;
    public:

        static void read_to_fillstyles(ISwfStreamReader& reader, Vec<Box<morph_fillstyles::MorphFillStyle>>& fillstyles);
        static Box<morph_fillstyles::MorphFillStyle> read_fillstyle(ISwfStreamReader& reader);
    };
}
