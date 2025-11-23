/**
 * @file    solid_fillstyle_rgba.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "fillstyle_rgba.h"
#include "Data/swf_rgba.h"
namespace swf_reader::shapes::fillstyles
{
    class SolidFillStyleRgba : public FillStyleRgba
    {
    public:
        data::SwfRgba color;

        /// <summary>
        /// Gets type of fill style.
        /// </summary>
        FillStyleType get_type() const override
        {
            return FillStyleType::SolidColor;
        }

        FillStyleRgba& accept_visitor(IFillStyleRgbaVisitor<ISwfStreamReader, FillStyleRgba&>& visitor, ISwfStreamReader& arg) override
        {
            return visitor.visit(*this, arg);
        }
    };
}