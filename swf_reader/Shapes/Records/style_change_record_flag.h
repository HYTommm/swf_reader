/**
 * @file    style_change_record_flag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "cpp_base_type.h"

namespace swf_reader::shapes::records
{
    enum class StyleChangeRecordFlag : u8
    {
        StateMoveTo = 1 << 0,  ///< 是否包含移动坐标信息
        StateFillStyle0 = 1 << 1,  ///< 是否包含填充样式0信息
        StateFillStyle1 = 1 << 2,  ///< 是否包含填充样式1信息
        StateLineStyle = 1 << 3,  ///< 是否包含线条样式信息
        StateNewStyles = 1 << 4,  ///< 是否包含新样式信息
        Reserved5 = 1 << 5,  ///< 保留位5
        Reserved6 = 1 << 6,  ///< 保留位6
        Reserved7 = 1 << 7,  ///< 保留位7
        NoFlags = 0        ///< 无标志
    };

    constexpr StyleChangeRecordFlag operator|(StyleChangeRecordFlag a, const StyleChangeRecordFlag b) noexcept
    {
        return static_cast<StyleChangeRecordFlag>(static_cast<u8>(a) | static_cast<u8>(b));
    }

    constexpr StyleChangeRecordFlag operator&(StyleChangeRecordFlag a, const StyleChangeRecordFlag b) noexcept
    {
        return static_cast<StyleChangeRecordFlag>(static_cast<u8>(a) & static_cast<u8>(b));
    }

    constexpr StyleChangeRecordFlag operator~(const StyleChangeRecordFlag a) noexcept
    {
        return static_cast<StyleChangeRecordFlag>(~static_cast<u8>(a));
    }

    constexpr StyleChangeRecordFlag operator&=(StyleChangeRecordFlag& a, const StyleChangeRecordFlag b) noexcept
    {
        a = a & b;
        return a;
    }

    constexpr StyleChangeRecordFlag operator|=(StyleChangeRecordFlag& a, const StyleChangeRecordFlag b) noexcept
    {
        a = a | b;
        return a;
    }

    struct StyleChangeRecordFlags
    {
        StyleChangeRecordFlag flags;

        /// <summary>
        /// 检查指定标志位是否设置
        /// </summary>
        /// <param name="mask">要检查的标志位掩码</param>
        /// <returns>如果标志位设置则返回true，否则返回false</returns>
        [[nodiscard]] inline bool get(const StyleChangeRecordFlag mask) const noexcept
        {
            return static_cast<bool>(flags & mask);
        }

        /// <summary>
        /// 设置或清除指定标志位
        /// </summary>
        /// <param name="mask">要设置的标志位掩码</param>
        /// <param name="value">要设置的值（true表示设置，false表示清除）</param>
        inline void set(const StyleChangeRecordFlag mask, const bool value) noexcept
        {
            if (value) flags |= mask;
            else flags &= ~mask;
        }
    };
}