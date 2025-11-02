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
    void FillStyleStreamExt::read_to_fillstyles_rgb(ISwfStreamReader& reader, Vec<Box<fillstyles::FillStyleRgb>>& fillStyles, bool allowBigArray)
    {
        u16 count = reader.read_byte();
        if (allowBigArray && count == 255)
            count = reader.read_ui16();
        for (u16 i = 0; i < count; i++)
        {
            fillStyles.push_back(read_fillstyle_rgb(reader));
        }
    }

    void FillStyleStreamExt::read_to_fillstyles_rgba(ISwfStreamReader& reader, Vec<Box<fillstyles::FillStyleRgba>>& fillStyles)
    {
        u16 count = reader.read_byte();
        if (count == 255)
            count = reader.read_ui16();
        for (u16 i = 0; i < count; i++)
        {
            fillStyles.push_back(read_fillstyle_rgba(reader));
        }
    }

    Box<fillstyles::FillStyleRgb> FillStyleStreamExt::read_fillstyle_rgb(ISwfStreamReader& reader)
    {
        fillstyles::FillStyleType type = static_cast<fillstyles::FillStyleType>(reader.read_byte());
        return _reader_rgb.read(reader, type);
    }
    Box<fillstyles::FillStyleRgba> FillStyleStreamExt::read_fillstyle_rgba(ISwfStreamReader& reader)
    {
        //return Box<fillstyles::FillStyleRgba>();
        fillstyles::FillStyleType type = static_cast<fillstyles::FillStyleType>(reader.read_byte());
        return _reader_rgba.read(reader, type);
    }
}