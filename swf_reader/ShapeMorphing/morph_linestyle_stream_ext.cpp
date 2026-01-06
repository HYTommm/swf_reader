/**
 * @file    morph_linestyle_stream_ext.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "morph_linestyle_stream_ext.h"
#include "Data/color_stream_ext.h"
#include "morph_fillstyle_stream_ext.h"

namespace swf_reader::shape_morphing
{
    using namespace morph_linestyles;

    void MorphLineStyleStreamExt::read_to_linestyles(ISwfStreamReader& reader, Vec<Box<MorphLineStyle>>& line_styles)
    {
        u16 count = reader.read_byte();
        if (count == 255)
            count = reader.read_ui16();
        for (u32 i = 0; i < count; i++)
        {
            line_styles.push_back(read_linestyle(reader));
        }
    }

    void MorphLineStyleStreamExt::read_to_linestyles_ex(ISwfStreamReader& reader, Vec<Box<MorphLineStyleEx>>& line_styles)
    {
        u16 count = reader.read_byte();
        if (count == 255)
            count = reader.read_ui16();
        for (u32 i = 0; i < count; i++)
        {
            line_styles.push_back(read_linestyle_ex(reader));
        }
    }

    Box<MorphLineStyle> MorphLineStyleStreamExt::read_linestyle(ISwfStreamReader& reader)
    {
        Box<MorphLineStyle> line_style = boxed<MorphLineStyle>();
        line_style->start_width = reader.read_ui16();
        line_style->end_width = reader.read_ui16();
        line_style->start_color = data::ColorStreamExt::read_rgba(reader);
        line_style->end_color = data::ColorStreamExt::read_rgba(reader);
        return line_style;
    }

    Box<MorphLineStyleEx> MorphLineStyleStreamExt::read_linestyle_ex(ISwfStreamReader& reader)
    {
        Box<MorphLineStyleEx> line_style = boxed<MorphLineStyleEx>();
        line_style->start_width = reader.read_ui16();
        line_style->end_width = reader.read_ui16();
        line_style->start_cap_style = static_cast<MorphCapStyle>(reader.read_ub(2));
        line_style->join_style = static_cast<MorphJoinStyle>(reader.read_ub(2));
        line_style->flags.set(MorphLineStyleExFlag::HasFill, reader.read_bit());
        line_style->flags.set(MorphLineStyleExFlag::NoHScale, reader.read_bit());
        line_style->flags.set(MorphLineStyleExFlag::NoVScale, reader.read_bit());
        line_style->flags.set(MorphLineStyleExFlag::PixelHinting, reader.read_bit());
        line_style->reserved = static_cast<u8>(reader.read_ub(5));
        line_style->flags.set(MorphLineStyleExFlag::NoClose, reader.read_bit());
        line_style->end_cap_style = static_cast<MorphCapStyle>(reader.read_ub(2));

        if (line_style->join_style == MorphJoinStyle::Miter)
            line_style->miter_limit_factor = reader.read_fixed8();
        if (line_style->flags.get(MorphLineStyleExFlag::HasFill))
            line_style->fillstyle = MorphFillStyleStreamExt::read_fillstyle(reader);
        else
        {
            line_style->start_color = data::ColorStreamExt::read_rgba(reader);
            line_style->end_color = data::ColorStreamExt::read_rgba(reader);
        }
        return line_style;
    }
}