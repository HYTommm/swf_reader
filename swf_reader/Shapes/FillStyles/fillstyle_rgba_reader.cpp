/**
 * @file    fillstyle_rgba_reader.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "fillstyle_rgba_reader.h"

namespace swf_reader::shapes::fillstyles {
    inline FillStyleRgba& FillStyleRgbaReader::visit(SolidFillStyleRgba& fillstyle, ISwfStreamReader& reader)
    {
        fillstyle.color = data::ColorStreamExt::read_rgba(reader);
        return fillstyle;
    }
}
