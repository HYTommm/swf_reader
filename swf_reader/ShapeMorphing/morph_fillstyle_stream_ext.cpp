/**
 * @file    morph_fillstyle_stream_ext.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#include "morph_fillstyle_stream_ext.h"

#include "i_swf_stream_reader.h"

namespace swf_reader::shape_morphing
{
    morph_fillstyles::MorphFillStyleReader MorphFillStyleStreamExt::_reader;
    void MorphFillStyleStreamExt::read_to_fillstyles(ISwfStreamReader& reader, Vec<Box<morph_fillstyles::MorphFillStyle>>& fillstyles)
    {
        u16 count = reader.read_byte();
        if (count == 255)
            count = reader.read_ui16();
        fillstyles.reserve(count);
        for (u16 i = 0; i < count; i++)
        {
            fillstyles.push_back(read_fillstyle(reader));
        }
    }

    Box<morph_fillstyles::MorphFillStyle> MorphFillStyleStreamExt::read_fillstyle(ISwfStreamReader& reader)
    {
        const morph_fillstyles::MorphFillStyleType type = static_cast<morph_fillstyles::MorphFillStyleType>(reader.read_byte());
        return _reader.read(reader, type);
    }
}