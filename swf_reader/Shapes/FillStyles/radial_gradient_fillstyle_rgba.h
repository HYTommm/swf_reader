/**
 * @file    radial_gradient_fillstyle_rgba.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "fillstyle_rgba.h"
#include "Gradients/linear_gradient_rgba.h"

namespace swf_reader::shapes::fillstyles
{
    class RadialGradientFillStyleRgba : public FillStyleRgba
    {
    public:
        data::SwfMatrix gradient_matrix;
        Box<gradients::LinearGradientRgba> gradient;

        FillStyleType get_type() const override { return FillStyleType::RadialGradient; }

        FillStyleRgba& accept_visitor(IFillStyleRgbaVisitor<ISwfStreamReader, FillStyleRgba&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}
