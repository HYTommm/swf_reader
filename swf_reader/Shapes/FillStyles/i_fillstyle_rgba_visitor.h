/**
 * @file    i_fillstyle_rgba_visitor.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

namespace swf_reader::shapes::fillstyles
{
    // Forward declaration
    class SolidFillStyleRgba;
    class LinearGradientFillStyleRgba;
    class RadialGradientFillStyleRgba;
    class FocalGradientFillStyleRgba;
    class BitmapFillStyleRgba;

    template<typename TArg, typename TResult>
    class IFillStyleRgbaVisitor
    {
    public:
        virtual TResult& visit(SolidFillStyleRgba& fillStyle, TArg& arg) = 0;
        virtual TResult& visit(LinearGradientFillStyleRgba& fillStyle, TArg& arg) = 0;
        virtual TResult& visit(RadialGradientFillStyleRgba& fillStyle, TArg& arg) = 0;
        virtual TResult& visit(FocalGradientFillStyleRgba& fillStyle, TArg& arg) = 0;
        //virtual TResult& visit(BitmapFillStyleRgba& fillStyle, TArg& arg) = 0;
        virtual ~IFillStyleRgbaVisitor() = default;
    };
}
