/**
 * @file    fillstyle_rgba_reader.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include "fillstyle_rgba.h"
#include "i_fillstyle_rgba_visitor.h"
#include "fillstyle_factory.h"
#include "Data/color_stream_ext.h"
namespace swf_reader::shapes::fillstyles
{
    class FillStyleRgbaReader : IFillStyleRgbaVisitor<ISwfStreamReader, FillStyleRgba&>
    {
    private:
        FillStyleFactory _factory;
    public:
        Box<FillStyleRgba> read(ISwfStreamReader& reader, FillStyleType type);
        FillStyleRgba& visit(SolidFillStyleRgba& fillstyle, ISwfStreamReader& reader) override;
        FillStyleRgba& visit(LinearGradientFillStyleRgba& fillstyle, ISwfStreamReader& reader) override;
        FillStyleRgba& visit(RadialGradientFillStyleRgba& fillstyle, ISwfStreamReader& reader) override;
        FillStyleRgba& visit(FocalGradientFillStyleRgba& fillstyle, ISwfStreamReader& reader) override;
    };
}