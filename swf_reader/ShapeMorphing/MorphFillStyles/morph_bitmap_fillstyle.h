/**
 * @file    morph_bitmap_fillstyle.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "morph_bitmap_mode.h"
#include "morph_fillstyle.h"
#include "Data/swf_matrix.h"

namespace swf_reader::shape_morphing::morph_fillstyles
{
    class MorphBitmapFillStyle : public MorphFillStyle
    {
    public:
        MorphBitmapFillStyle() = default;
        MorphBitmapFillStyle(const bool smoothing, const MorphBitmapMode mode) : smoothing{ smoothing }, mode{ mode }
        {
        }
        ~MorphBitmapFillStyle() override = default;
        MorphBitmapFillStyle(const MorphBitmapFillStyle&) = default;
        MorphBitmapFillStyle(MorphBitmapFillStyle&&) = default;
        MorphBitmapFillStyle& operator=(const MorphBitmapFillStyle&) = default;
        MorphBitmapFillStyle& operator=(MorphBitmapFillStyle&&) = default;

        bool smoothing;
        MorphBitmapMode mode;
        u16 bitmap_id;
        data::SwfMatrix start_bitmap_matrix;
        data::SwfMatrix end_bitmap_matrix;

        [[nodiscard]] MorphFillStyleType get_type() const override
        {
            switch (mode)
            {
                case MorphBitmapMode::Clip:
                    return smoothing ? MorphFillStyleType::ClippedBitmap : MorphFillStyleType::NonSmoothedClippedBitmap;
                case MorphBitmapMode::Repeat:
                    return smoothing ? MorphFillStyleType::RepeatingBitmap : MorphFillStyleType::NonSmoothedRepeatingBitmap;
            }
        }

        MorphFillStyle& accept_visitor(IMorphFillStyleVisitor<ISwfStreamReader, MorphFillStyle&>& visitor, ISwfStreamReader& arg) override
        {
            return visitor.visit(*this, arg);
        }
    };
}
