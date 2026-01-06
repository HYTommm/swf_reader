/**
 * @file    morph_solid_fillstyle.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "morph_fillstyle.h"
#include "Data/swf_rgba.h"
namespace swf_reader::shape_morphing::morph_fillstyles
{
    class MorphSolidFillStyle : public MorphFillStyle
    {
    public:
        data::SwfRgba start_color;
        data::SwfRgba end_color;

        [[nodiscard]] MorphFillStyleType get_type() const override
        {
            return MorphFillStyleType::SolidColor;
        }

        MorphFillStyle& accept_visitor(IMorphFillStyleVisitor<ISwfStreamReader, MorphFillStyle&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}
