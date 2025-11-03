/**
 * @file focal_gradient_fillstyle_rgb.h
 *
 * Original C# implementation: Copyright (c)2018 Sergey Savchuk
 * C++ port: Copyright (c)2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "fillstyle_rgb.h"
#include "Data/swf_matrix.h"
#include "Gradients/focal_gradient_rgb.h"

namespace swf_reader::shapes::fillstyles
{
    class FocalGradientFillStyleRgb : public FillStyleRgb
    {
    public:
        data::SwfMatrix gradient_matrix = data::SwfMatrix::identity();
        Box<gradients::FocalGradientRgb> gradient;

        FillStyleType get_type() const override
        {
            return FillStyleType::FocalGradient;
        }

        FillStyleRgb& accept_visitor(IFillStyleRgbVisitor<ISwfStreamReader, FillStyleRgb&>& visitor, ISwfStreamReader& arg) override
        {
            return visitor.visit(*this, arg);
        }
    };
}
