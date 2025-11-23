/**
 * @file    radial_gradient_fillstyle_rgb.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "fillstyle_rgb.h"
#include "Gradients/linear_gradient_rgb.h"

namespace swf_reader::shapes::fillstyles
{
    class RadialGradientFillStyleRgb : public FillStyleRgb
    {
    public:
        data::SwfMatrix gradient_matrix;
        Box<gradients::LinearGradientRgb> gradient;

        FillStyleType get_type() const override
        {
            return FillStyleType::RadialGradient;
        }

        FillStyleRgb& accept_visitor(IFillStyleRgbVisitor<ISwfStreamReader, FillStyleRgb&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}
