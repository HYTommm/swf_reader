/**
 * @file    swf_symbol_reference.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include <string>

#include "cpp_base_type.h"

namespace swf_reader::data {
    class SwfSymbolReference {
    public:
        u16 symbol_id;
        std::string symbol_name;
    };
}
