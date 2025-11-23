/**
 * @file    swf_zip.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

#include <memory>

#include "cpp_base_type.h"
#include "swf_format.h"

namespace swf_reader
{
    class SwfZip
    {
    public:
        // 流式解压接口 - 与 C# 原版保持一致
        static void decompress(std::istream& source, std::ostream& target, SwfFormat format);

        // 字节数组解压接口
        static std::vector<u8> decompress(const std::vector<u8>& compressed, SwfFormat format);

    private:
        static void decompress_zlib(std::istream& source, std::ostream& target);
        static void decompress_lzma(std::istream& source, std::ostream& target);
        static void validate_compression_format(SwfFormat format);
    };
}