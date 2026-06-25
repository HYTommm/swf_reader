/**
 * @file    swf_zip.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include "primitive_types.h"
#include "cpp_base_type.h"

#include "swf_format.h"

namespace swf_reader
{
    class SwfZip
    {
    public:
        // 流式解压接口
        static bool decompress(std::istream& source, std::ostream& target, SwfFormat format);

        // 字节数组解压接口
        static Vec<u8> decompress(const Vec<u8>& compressed, SwfFormat format);

    private:
        static bool decompress_zlib(std::istream& source, std::ostream& target);
        static bool decompress_lzma(std::istream& source, std::ostream& target);
    };
}