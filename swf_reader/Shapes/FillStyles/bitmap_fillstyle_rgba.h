/**
 * @file    bitmap_fillstyle_rgba.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "fillstyle_rgba.h"
#include "fillstyle_type.h"
#include "i_fillstyle_rgba_visitor.h"
#include "Data/swf_matrix.h"

#include "bitmap_mode.h"

namespace swf_reader::shapes::fillstyles
{
    class BitmapFillStyleRgba : public FillStyleRgba
    {
    public:
        BitmapFillStyleRgba() = default;
        BitmapFillStyleRgba(bool smoothing, BitmapMode mode) : smoothing{ smoothing }, mode{ mode } {}
        ~BitmapFillStyleRgba() = default;
        bool smoothing{ false };
        BitmapMode mode{ BitmapMode::Repeat };
        u16 bitmap_id{ 0 };
        data::SwfMatrix bitmap_matrix{ data::SwfMatrix::identity() };

        FillStyleType get_type() const override
        {
            switch (mode)
            {
                case BitmapMode::Clip:
                    return smoothing ? FillStyleType::ClippedBitmap : FillStyleType::NonSmoothedClippedBitmap;
                case BitmapMode::Repeat:
                    return smoothing ? FillStyleType::RepeatingBitmap : FillStyleType::NonSmoothedRepeatingBitmap;
                default:
                    throw std::runtime_error("Unsupported bitmap mode");
            }
        }

        FillStyleRgba& accept_visitor(IFillStyleRgbaVisitor<ISwfStreamReader, FillStyleRgba&>& visitor, ISwfStreamReader& arg) override
        {
            return visitor.visit(*this, arg);
        }
    };
}
