/**
 * @file    fillstyle_rgb_reader.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "fillstyle_rgb_reader.h"
#include "Data/color_stream_ext.h"

#include "Gradients/gradient_stream_ext.h"

namespace swf_reader::shapes::fillstyles
{
    Box<FillStyleRgb> FillStyleRgbReader::read(ISwfStreamReader& reader, FillStyleType type)
    {
        Box<FillStyleRgb> fillstyle = _factory.create_rgb(type);
        if (!fillstyle)
            return nullptr;
        fillstyle->accept_visitor(*this, reader);
        return fillstyle;
    }
    FillStyleRgb& FillStyleRgbReader::visit(SolidFillStyleRgb& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.color = data::ColorStreamExt::read_rgb(reader);
        return fillstyle;
    }
    FillStyleRgb& FillStyleRgbReader::visit(LinearGradientFillStyleRgb& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.gradient_matrix = SwfStreamReaderExt::read_matrix(reader);
        fillstyle.gradient = gradients::GradientStreamExt::read_linear_gradient_rgb(reader);
        return fillstyle;
    }
    FillStyleRgb& FillStyleRgbReader::visit(RadialGradientFillStyleRgb& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.gradient_matrix = SwfStreamReaderExt::read_matrix(reader);
        fillstyle.gradient = gradients::GradientStreamExt::read_linear_gradient_rgb(reader);
        return fillstyle;
    }
    FillStyleRgb& FillStyleRgbReader::visit(FocalGradientFillStyleRgb& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.gradient_matrix = SwfStreamReaderExt::read_matrix(reader);
        fillstyle.gradient = gradients::GradientStreamExt::read_focal_gradient_rgb(reader);
        return fillstyle;
    }
    FillStyleRgb& FillStyleRgbReader::visit(BitmapFillStyleRgb& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.bitmap_id = reader.read_ui16();
        fillstyle.bitmap_matrix = SwfStreamReaderExt::read_matrix(reader);
        return fillstyle;
    }
}