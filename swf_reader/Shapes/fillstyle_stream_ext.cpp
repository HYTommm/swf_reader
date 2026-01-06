/**
 * @file    fillstyle_stream_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "fillstyle_stream_ext.h"
#include "FillStyles/fillstyle_type.h"
namespace swf_reader::shapes
{
    fillstyles::FillStyleRgbReader FillStyleStreamExt::_reader_rgb;
    fillstyles::FillStyleRgbaReader FillStyleStreamExt::_reader_rgba;
    void FillStyleStreamExt::read_to_fillstyles_rgb(ISwfStreamReader& reader, Vec<Box<fillstyles::FillStyleRgb>>& fillstyles, const bool allow_big_array)
    {
        u16 count = reader.read_byte();
        if (allow_big_array && count == 255)
            count = reader.read_ui16();
        fillstyles.reserve(count);
        for (u16 i = 0; i < count; i++)
        {
            fillstyles.push_back(read_fillstyle_rgb(reader));
        }
    }

    void FillStyleStreamExt::read_to_fillstyles_rgba(ISwfStreamReader& reader, Vec<Box<fillstyles::FillStyleRgba>>& fillstyles)
    {
        u16 count = reader.read_byte();
        if (count == 255)
            count = reader.read_ui16();
        fillstyles.reserve(count);
        for (u16 i = 0; i < count; i++)
        {
            fillstyles.push_back(read_fillstyle_rgba(reader));
        }
    }

    Box<fillstyles::FillStyleRgb> FillStyleStreamExt::read_fillstyle_rgb(ISwfStreamReader& reader)
    {
        const fillstyles::FillStyleType type = static_cast<fillstyles::FillStyleType>(reader.read_byte());
        return _reader_rgb.read(reader, type);
    }
    Box<fillstyles::FillStyleRgba> FillStyleStreamExt::read_fillstyle_rgba(ISwfStreamReader& reader)
    {
        //return Box<fillstyles::FillStyleRgba>();
        const fillstyles::FillStyleType type = static_cast<fillstyles::FillStyleType>(reader.read_byte());
        return _reader_rgba.read(reader, type);
    }
}