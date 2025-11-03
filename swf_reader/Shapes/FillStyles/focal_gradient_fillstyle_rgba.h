/**
 * @file focal_gradient_fillstyle_rgba.h
 *
 * Original C# implementation: Copyright (c)2018 Sergey Savchuk
 * C++ port: Copyright (c)2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "fillstyle_rgba.h"
#include "Data/swf_matrix.h"
#include "Gradients/focal_gradient_rgba.h"

namespace swf_reader::shapes::fillstyles
{
    class FocalGradientFillStyleRgba : public FillStyleRgba
    {
    public:
        data::SwfMatrix gradient_matrix = data::SwfMatrix::identity();
        Box<gradients::FocalGradientRgba> gradient;

        FillStyleType get_type() const override
        {
            return FillStyleType::FocalGradient;
        }

        FillStyleRgba& accept_visitor(IFillStyleRgbaVisitor<ISwfStreamReader, FillStyleRgba&>& visitor, ISwfStreamReader& arg) override
        {
            return visitor.visit(*this, arg);
        }
    };
}
