/**
 * @file    clip_event_flags.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "primitive_types.h"
#include <type_traits>

namespace swf_reader::clip_actions
{
    enum class ClipEventFlag : u32
    {
        None = 0,
        KeyUp = 1 << 0,
        KeyDown = 1 << 1,
        MouseUp = 1 << 2,
        MouseDown = 1 << 3,
        MouseMove = 1 << 4,
        Unload = 1 << 5,
        EnterFrame = 1 << 6,
        Load = 1 << 7,

        DragOver = 1 << 8,
        RollOut = 1 << 9,
        RollOver = 1 << 10,
        ReleaseOutside = 1 << 11,
        Release = 1 << 12,
        Press = 1 << 13,
        Initialize = 1 << 14,
        Data = 1 << 15,

        Construct = 1 << 16,
        KeyPress = 1 << 17,
        DragOut = 1 << 18
    };

    // 位或操作符
    constexpr ClipEventFlag operator|(const ClipEventFlag lhs, const ClipEventFlag rhs) noexcept
    {
        return static_cast<ClipEventFlag>(
            static_cast<std::underlying_type_t<ClipEventFlag>>(lhs) |
            static_cast<std::underlying_type_t<ClipEventFlag>>(rhs)
            );
    }

    // 位与操作符
    constexpr ClipEventFlag operator&(const ClipEventFlag lhs, const ClipEventFlag rhs) noexcept
    {
        return static_cast<ClipEventFlag>(
            static_cast<std::underlying_type_t<ClipEventFlag>>(lhs) &
            static_cast<std::underlying_type_t<ClipEventFlag>>(rhs)
            );
    }

    // 复合位或操作符
    constexpr ClipEventFlag& operator|=(ClipEventFlag& lhs, const ClipEventFlag rhs) noexcept
    {
        lhs = lhs | rhs;
        return lhs;
    }

    // 复合位与操作符
    constexpr ClipEventFlag& operator&=(ClipEventFlag& lhs, const ClipEventFlag rhs) noexcept
    {
        lhs = lhs & rhs;
        return lhs;
    }

    // 定义位非操作符
    constexpr ClipEventFlag operator~(const ClipEventFlag flag) noexcept
    {
        return static_cast<ClipEventFlag>(~static_cast<u32>(flag));
    }

    struct ClipEventFlags
    {
        ClipEventFlag flags{ ClipEventFlag::None };
        u8 reserved{ 0 };
        u8 reserved2{ 0 };

        // 简洁的位操作接口
        [[nodiscard]] bool get(const ClipEventFlag mask) const noexcept
        {
            return static_cast<bool>(flags & mask);
        }
        void set(const ClipEventFlag mask, const bool value) noexcept
        {
            if (value) flags |= mask;
            else flags &= ~mask;
        }

        // 检查是否为空的属性
        [[nodiscard]] bool is_empty() const noexcept
        {
            return flags == ClipEventFlag::None
                && reserved == 0
                && reserved2 == 0;
        }
    };
}
