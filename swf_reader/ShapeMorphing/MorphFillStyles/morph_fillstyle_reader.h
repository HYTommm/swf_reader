/**
 * @file    morph_fillstyle_reader.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "cpp_base_type.h"
#include "i_morph_fillstyle_visitor.h"
#include "morph_fillstyle.h"

namespace swf_reader::shape_morphing::morph_fillstyles
{
    class MorphFillStyleReader : public IMorphFillStyleVisitor<ISwfStreamReader, MorphFillStyle&>
    {
    public:
        Box<MorphFillStyle> read(ISwfStreamReader& reader, MorphFillStyleType type);
        MorphFillStyle& visit(MorphSolidFillStyle& fillstyle, ISwfStreamReader& reader) override;
        MorphFillStyle& visit(MorphLinearGradientFillStyle& fillstyle, ISwfStreamReader& reader) override;
        MorphFillStyle& visit(MorphRadialGradientFillStyle& fillstyle, ISwfStreamReader& reader) override;
        MorphFillStyle& visit(MorphFocalGradientFillStyle& fillstyle, ISwfStreamReader& reader) override;
        MorphFillStyle& visit(MorphBitmapFillStyle& fillstyle, ISwfStreamReader& reader) override;
    };
}
