/**
 * @file    symbol_class_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include <vector>

#include "Tags/swf_tag_base.h"
#include "Data/swf_symbol_reference.h"

namespace swf_reader::tags::control_tags
{
    class SymbolClassTag : public SwfTagBase
    {
    public:
        Vec<data::SwfSymbolReference> references;

        SwfTagType get_type() const override
        {
            return SwfTagType::SymbolClass;
        }

        SwfTagBase& accept_visitor(ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}
