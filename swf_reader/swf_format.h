/**
 * @file    swf_format.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include <iostream>

namespace swf_reader
{
    enum class SwfFormat
    {
        Unknown = 0,
        FWS = 1,  // Uncompressed SWF
        CWS = 2,  // Zlib compressed SWF
        ZWS = 3   // LZMA compressed SWF
    };

    // 重载运算符<<
    inline std::ostream& operator<<(std::ostream& os, const SwfFormat& format)
    {
        switch (format)
        {
            case SwfFormat::Unknown:
                os << "Unknown";
                break;
            case SwfFormat::FWS:
                os << "FWS";
                break;
            case SwfFormat::CWS:
                os << "CWS";
                break;
            case SwfFormat::ZWS:
                os << "ZWS";
                break;
        }
        return os;
    }
}