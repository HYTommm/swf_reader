/**
 * @file    fillstyle_rgba_reader.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "fillstyle_rgba_reader.h"
#include "Data/color_stream_ext.h"
#include "Gradients/gradient_stream_ext.h"

namespace swf_reader::shapes::fillstyles
{
    Box<FillStyleRgba> FillStyleRgbaReader::read(ISwfStreamReader& reader, FillStyleType type)
    {
        Box<FillStyleRgba> fillstyle = _factory.create_rgba(type);
        if (!fillstyle)
            return nullptr;
        fillstyle->accept_visitor(*this, reader);
        return fillstyle;
    }
    FillStyleRgba& FillStyleRgbaReader::visit(SolidFillStyleRgba& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.color = data::ColorStreamExt::read_rgba(reader);
        return fillstyle;
    }
    FillStyleRgba& FillStyleRgbaReader::visit(LinearGradientFillStyleRgba& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.gradient_matrix = SwfStreamReaderExt::read_matrix(reader);
        fillstyle.gradient = gradients::GradientStreamExt::read_linear_gradient_rgba(reader);
        return fillstyle;
    }
    FillStyleRgba& FillStyleRgbaReader::visit(RadialGradientFillStyleRgba& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.gradient_matrix = SwfStreamReaderExt::read_matrix(reader);
        fillstyle.gradient = gradients::GradientStreamExt::read_linear_gradient_rgba(reader);
        return fillstyle;
    }
    FillStyleRgba& FillStyleRgbaReader::visit(FocalGradientFillStyleRgba& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.gradient_matrix = SwfStreamReaderExt::read_matrix(reader);
        fillstyle.gradient = gradients::GradientStreamExt::read_focal_gradient_rgba(reader);
        return fillstyle;
    }
    FillStyleRgba& FillStyleRgbaReader::visit(BitmapFillStyleRgba& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.bitmap_id = reader.read_ui16();
        fillstyle.bitmap_matrix = SwfStreamReaderExt::read_matrix(reader);
        return fillstyle;
    }
}