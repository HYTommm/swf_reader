/**
 * @file    morph_linestyle_ex_flag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "cpp_base_type.h"

namespace swf_reader::shape_morphing::morph_linestyles
{
    enum class MorphLineStyleExFlag : u8
    {
        HasFill = 1 << 0,  ///< 是否有填充样式
        NoHScale = 1 << 1,  ///< 是否禁止水平缩放
        NoVScale = 1 << 2,  ///< 是否禁止垂直缩放
        PixelHinting = 1 << 3,  ///< 是否有像素提示
        NoClose = 1 << 4,  ///< 是否不闭合路径
        Reserved5 = 1 << 5,  ///< 保留位5
        Reserved6 = 1 << 6,  ///< 保留位6
        Reserved7 = 1 << 7,  ///< 保留位7
        NoFlags = 0        ///< 无标志
    };

    constexpr MorphLineStyleExFlag operator|(MorphLineStyleExFlag a, const MorphLineStyleExFlag b) noexcept
    {
        return static_cast<MorphLineStyleExFlag>(static_cast<u8>(a) | static_cast<u8>(b));
    }

    constexpr MorphLineStyleExFlag operator&(MorphLineStyleExFlag a, const MorphLineStyleExFlag b) noexcept
    {
        return static_cast<MorphLineStyleExFlag>(static_cast<u8>(a) & static_cast<u8>(b));
    }

    constexpr MorphLineStyleExFlag operator~(const MorphLineStyleExFlag a) noexcept
    {
        return static_cast<MorphLineStyleExFlag>(~static_cast<u8>(a));
    }

    constexpr MorphLineStyleExFlag operator&=(MorphLineStyleExFlag& a, const MorphLineStyleExFlag b) noexcept
    {
        a = a & b;
        return a;
    }

    constexpr MorphLineStyleExFlag operator|=(MorphLineStyleExFlag& a, const MorphLineStyleExFlag b) noexcept
    {
        a = a | b;
        return a;
    }

    struct MorphLineStyleExFlags
    {
        MorphLineStyleExFlag flags;

        [[nodiscard]] constexpr bool get(const MorphLineStyleExFlag mask) const noexcept
        {
            return static_cast<bool>(flags & mask);
        }

        constexpr void set(const MorphLineStyleExFlag mask, const bool value) noexcept
        {
            if (value) flags |= mask;
            else flags &= ~mask;
        }
    };
}