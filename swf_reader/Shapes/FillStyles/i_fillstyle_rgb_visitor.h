/**
 * @file    i_fillstyle_rgb_visitor.h
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
    class SolidFillStyleRgb;
    class LinearGradientFillStyleRgb;
    class RadialGradientFillStyleRgb;
    class FocalGradientFillStyleRgb;
    class BitmapFillStyleRgb;

    template<typename TArg, typename TResult>
    class IFillStyleRgbVisitor
    {
    public:
        virtual TResult& visit(SolidFillStyleRgb& fillStyle, TArg& arg) = 0;
        virtual TResult& visit(LinearGradientFillStyleRgb& fillStyle, TArg& arg) = 0;
        virtual TResult& visit(RadialGradientFillStyleRgb& fillStyle, TArg& arg) = 0;
        virtual TResult& visit(FocalGradientFillStyleRgb& fillStyle, TArg& arg) = 0;
        //virtual TResult& visit(BitmapFillStyleRgb& fillStyle, TArg& arg) = 0;
        virtual ~IFillStyleRgbVisitor() = default;
    };
}