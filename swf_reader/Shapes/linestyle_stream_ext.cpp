#include "linestyle_stream_ext.h"
/**
 * @file    linestyle_stream_ext.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "Data/color_stream_ext.h"
#include "fillstyle_stream_ext.h"
namespace swf_reader::shapes
{
    void LineStyleStreamExt::read_to_linestyles_rgb(ISwfStreamReader& reader, Vec<linestyles::LineStyleRgb>& lineStyles, bool allowBigArray)
    {
        u16 count = reader.read_byte();
        if (allowBigArray && count == 255)
            count = reader.read_ui16();
        for (i32 i = 0; i < count; i++)
        {
            lineStyles.push_back(read_linestyle_rgb(reader));
        }
    }
    void LineStyleStreamExt::read_to_linestyles_rgba(ISwfStreamReader& reader, Vec<linestyles::LineStyleRgba>& lineStyles)
    {
        u16 count = reader.read_byte();
        if (count == 255)
            count = reader.read_ui16();
        for (i32 i = 0; i < count; i++)
        {
            lineStyles.push_back(read_linestyle_rgba(reader));
        }
    }
    void LineStyleStreamExt::read_to_linestyles_ex(ISwfStreamReader& reader, Vec<linestyles::LineStyleEx>& lineStyles)
    {
        u16 count = reader.read_byte();
        if (count == 255)
            count = reader.read_ui16();
        for (i32 i = 0; i < count; i++)
        {
            lineStyles.push_back(read_linestyle_ex(reader));
        }
    }
    linestyles::LineStyleRgb LineStyleStreamExt::read_linestyle_rgb(ISwfStreamReader& reader)
    {
        linestyles::LineStyleRgb line_style;
        line_style.width = reader.read_ui16();
        line_style.color = data::ColorStreamExt::read_rgb(reader);
        return line_style;
    }
    linestyles::LineStyleRgba LineStyleStreamExt::read_linestyle_rgba(ISwfStreamReader& reader)
    {
        linestyles::LineStyleRgba line_style;
        line_style.width = reader.read_ui16();
        line_style.color = data::ColorStreamExt::read_rgba(reader);
        return line_style;
    }
    linestyles::LineStyleEx LineStyleStreamExt::read_linestyle_ex(ISwfStreamReader& reader)
    {
        linestyles::LineStyleEx line_style;
        line_style.width = reader.read_ui16();
        line_style.start_cap_style = static_cast<linestyles::CapStyle>(reader.read_ub(2));
        line_style.join_style = static_cast<linestyles::JoinStyle>(reader.read_ub(2));
        line_style.flags.set(linestyles::LineStyleExFlag::HasFill, reader.read_bit());
        line_style.flags.set(linestyles::LineStyleExFlag::NoHScale, reader.read_bit());
        line_style.flags.set(linestyles::LineStyleExFlag::NoVScale, reader.read_bit());
        line_style.flags.set(linestyles::LineStyleExFlag::PixelHinting, reader.read_bit());
        line_style.reserved = static_cast<u8>(reader.read_ub(5));
        line_style.flags.set(linestyles::LineStyleExFlag::NoClose, reader.read_bit());
        line_style.end_cap_style = static_cast<linestyles::CapStyle>(reader.read_ub(2));

        if (line_style.join_style == linestyles::JoinStyle::Miter)
            line_style.miter_limit_factor = reader.read_fixed8();
        if (line_style.flags.get(linestyles::LineStyleExFlag::HasFill))
            line_style.fillstyle = FillStyleStreamExt::read_fillstyle_rgba(reader);
        else line_style.color = data::ColorStreamExt::read_rgba(reader);
        return line_style;
    }
}