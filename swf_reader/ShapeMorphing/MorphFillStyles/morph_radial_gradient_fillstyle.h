/**
 * @file    morph_radial_gradient_fillstyle.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "morph_fillstyle.h"
#include "Data/swf_matrix.h"
#include "MorphGradients/morph_linear_gradient.h"

namespace swf_reader::shape_morphing::morph_fillstyles
{
    class MorphRadialGradientFillStyle : public MorphFillStyle
    {
    public:
        data::SwfMatrix start_gradient_matrix = data::SwfMatrix::identity();
        data::SwfMatrix end_gradient_matrix = data::SwfMatrix::identity();
        Box<morph_gradients::MorphLinearGradient> gradient;

        [[nodiscard]] MorphFillStyleType get_type() const override
        {
            return MorphFillStyleType::RadialGradient;
        }

        MorphFillStyle& accept_visitor(IMorphFillStyleVisitor<ISwfStreamReader, MorphFillStyle&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}