/**
 * @file    morph_fillstyle_reader.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "morph_fillstyle_reader.h"

#include "morph_fillstyle_factory.h"
#include "morph_focal_gradient_fillstyle.h"
#include "morph_linear_gradient_fillstyle.h"
#include "morph_radial_gradient_fillstyle.h"
#include "morph_solid_fillstyle.h"
#include "morph_bitmap_fillstyle.h"
#include "Data/color_stream_ext.h"
#include "MorphGradients/morph_gradient_stream_ext.h"

namespace swf_reader::shape_morphing::morph_fillstyles
{
    Box<MorphFillStyle> MorphFillStyleReader::read(ISwfStreamReader& reader, const MorphFillStyleType type)
    {
        Box<MorphFillStyle> fillstyle = MorphFillStyleFactory::create(type);
        fillstyle->accept_visitor(*this, reader);
        return fillstyle;
    }

    MorphFillStyle& MorphFillStyleReader::visit(MorphSolidFillStyle& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.start_color = data::ColorStreamExt::read_rgba(reader);
        fillstyle.end_color = data::ColorStreamExt::read_rgba(reader);
        return fillstyle;
    }
    MorphFillStyle& MorphFillStyleReader::visit(MorphLinearGradientFillStyle& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.start_gradient_matrix = SwfStreamReaderExt::read_matrix(reader);
        fillstyle.end_gradient_matrix = SwfStreamReaderExt::read_matrix(reader);
        fillstyle.gradient = morph_gradients::MorphGradientStreamExt::read_linear_gradient(reader);
        return fillstyle;
    }
    MorphFillStyle& MorphFillStyleReader::visit(MorphRadialGradientFillStyle& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.start_gradient_matrix = SwfStreamReaderExt::read_matrix(reader);
        fillstyle.end_gradient_matrix = SwfStreamReaderExt::read_matrix(reader);
        fillstyle.gradient = morph_gradients::MorphGradientStreamExt::read_linear_gradient(reader);
        return fillstyle;
    }
    MorphFillStyle& MorphFillStyleReader::visit(MorphFocalGradientFillStyle& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.start_gradient_matrix = SwfStreamReaderExt::read_matrix(reader);
        fillstyle.end_gradient_matrix = SwfStreamReaderExt::read_matrix(reader);
        fillstyle.gradient = morph_gradients::MorphGradientStreamExt::read_focal_gradient(reader);
        return fillstyle;
    }

    MorphFillStyle& MorphFillStyleReader::visit(MorphBitmapFillStyle& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.bitmap_id = reader.read_ui16();
        fillstyle.start_bitmap_matrix = SwfStreamReaderExt::read_matrix(reader);
        fillstyle.end_bitmap_matrix = SwfStreamReaderExt::read_matrix(reader);
        return fillstyle;
    }
}