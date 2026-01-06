/**
 * @file    morph_fillstyle.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "i_morph_fillstyle_visitor.h"
#include "morph_fillstyle_type.h"

namespace swf_reader
{
    class ISwfStreamReader;
}

namespace swf_reader::shape_morphing::morph_fillstyles
{
    class MorphFillStyle
    {
    public:
        MorphFillStyle() = default;
        virtual ~MorphFillStyle() = default;
        [[nodiscard]] virtual MorphFillStyleType get_type() const = 0;
        virtual MorphFillStyle& accept_visitor(IMorphFillStyleVisitor<ISwfStreamReader, MorphFillStyle&>& visitor, ISwfStreamReader& arg) = 0;
    };
}
