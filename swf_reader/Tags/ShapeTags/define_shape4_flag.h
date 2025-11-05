/**
 * @file define_shape4_flag.h
 *
 * Original C# implementation: Copyright (c)2018 Sergey Savchuk
 * C++ port: Copyright (c)2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "cpp_base_type.h"

namespace swf_reader::tags::shape_tags
{
    enum class DefineShape4Flag : u8
    {
        UsesScalingStrokes = 1 << 0,
        UsesNonScalingStrokes = 1 << 1,
        UsesFillWindingRule = 1 << 2,
        Reserved3 = 1 << 3,
        Reserved4 = 1 << 4,
        Reserved5 = 1 << 5,
        Reserved6 = 1 << 6,
        Reserved7 = 1 << 7,
        NoFlags = 0
    };

    constexpr DefineShape4Flag operator|(DefineShape4Flag a, const DefineShape4Flag b) noexcept
    {
        return static_cast<DefineShape4Flag>(static_cast<u8>(a) | static_cast<u8>(b));
    }

    constexpr DefineShape4Flag operator&(DefineShape4Flag a, const DefineShape4Flag b) noexcept
    {
        return static_cast<DefineShape4Flag>(static_cast<u8>(a) & static_cast<u8>(b));
    }

    constexpr DefineShape4Flag operator~(const DefineShape4Flag a) noexcept
    {
        return static_cast<DefineShape4Flag>(~static_cast<u8>(a));
    }

    constexpr DefineShape4Flag operator&=(DefineShape4Flag& a, const DefineShape4Flag b) noexcept
    {
        a = a & b;
        return a;
    }

    constexpr DefineShape4Flag operator|=(DefineShape4Flag& a, const DefineShape4Flag b) noexcept
    {
        a = a | b;
        return a;
    }

    struct DefineShape4Flags
    {
        DefineShape4Flag flags{ DefineShape4Flag::NoFlags };

        [[nodiscard]] inline bool get(const DefineShape4Flag mask) const noexcept
        {
            return static_cast<bool>(flags & mask);
        }

        inline void set(const DefineShape4Flag mask, const bool value) noexcept
        {
            if (value) flags |= mask;
            else flags &= ~mask;
        }

        inline void set(u8 rawFlags) noexcept
        {
            flags = static_cast<DefineShape4Flag>(rawFlags);
        }

        [[nodiscard]] inline u8 raw() const noexcept
        {
            return static_cast<u8>(flags);
        }

        // Returns only reserved bits (Reserved3..Reserved7) as DefineShape4Flag
        [[nodiscard]] inline DefineShape4Flag reserved() const noexcept
        {
            constexpr DefineShape4Flag reservedMask =
                DefineShape4Flag::Reserved3 |
                DefineShape4Flag::Reserved4 |
                DefineShape4Flag::Reserved5 |
                DefineShape4Flag::Reserved6 |
                DefineShape4Flag::Reserved7;

            return flags & reservedMask;
        }
    };
}
