/*
 * @file    i_filter_visitor.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
namespace swf_reader::filters
{
    // Forward declaration
    //class DropShadowFilter;
    //class BlurFilter;
    //class GlowFilter;
    //class BevelFilter;
    //class GradientGlowFilter;
    //class ConvolutionFilter;
    //class ColorMatrixFilter;
    //class GradientBevelFilter;
    template<typename TArg, typename TResult>
    class IFilterVisitor
    {
    public:

        //virtual TResult& visit(DropShadowFilter& filter, TArg& arg) = 0;
        //virtual TResult& visit(BlurFilter& filter, TArg& arg) = 0;
        //virtual TResult& visit(GlowFilter& filter, TArg& arg) = 0;
        //virtual TResult& visit(BevelFilter& filter, TArg& arg) = 0;
        //virtual TResult& visit(GradientGlowFilter& filter, TArg& arg) = 0;
        //virtual TResult& visit(ConvolutionFilter& filter, TArg& arg) = 0;
        //virtual TResult& visit(ColorMatrixFilter& filter, TArg& arg) = 0;
        //virtual TResult& visit(GradientBevelFilter& filter, TArg& arg) = 0;
    };
}