/**
 * @file    i_morph_fillstyle_visitor.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

namespace swf_reader::shape_morphing::morph_fillstyles
{
    class MorphSolidFillStyle;
    class MorphLinearGradientFillStyle;
    class MorphRadialGradientFillStyle;
    class MorphFocalGradientFillStyle;
    class MorphBitmapFillStyle;

    template<typename TArg, typename TResult>
    class IMorphFillStyleVisitor
    {
    public:
        IMorphFillStyleVisitor() = default;
        virtual ~IMorphFillStyleVisitor() = default;
        IMorphFillStyleVisitor(const IMorphFillStyleVisitor&) = default;
        IMorphFillStyleVisitor(IMorphFillStyleVisitor&&) = default;
        IMorphFillStyleVisitor& operator=(const IMorphFillStyleVisitor&) = default;
        IMorphFillStyleVisitor& operator=(IMorphFillStyleVisitor&&) = default;

        virtual TResult visit(MorphSolidFillStyle& fillstyle, TArg& arg) = 0;
        virtual TResult visit(MorphLinearGradientFillStyle& fillstyle, TArg& arg) = 0;
        virtual TResult visit(MorphRadialGradientFillStyle& fillstyle, TArg& arg) = 0;
        virtual TResult visit(MorphFocalGradientFillStyle& fillstyle, TArg& arg) = 0;
        virtual TResult visit(MorphBitmapFillStyle& fillstyle, TArg& arg) = 0;
    };
}