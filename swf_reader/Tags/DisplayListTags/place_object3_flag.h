/**
 * @file    place_object3_flag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "cpp_base_type.h"

namespace swf_reader::tags::display_list_tags
{
    enum class PlaceObject3Flag : u16
    {
        HasClipActions = 1 << 15,
        HasClipDepth = 1 << 14,
        HasName = 1 << 13,
        HasRatio = 1 << 12,
        HasColorTransform = 1 << 11,
        HasMatrix = 1 << 10,
        HasCharacter = 1 << 9,
        Move = 1 << 8,
        Reserved = 1 << 7,
        HasOpaqueBackground = 1 << 6,
        HasVisible = 1 << 5,
        HasImage = 1 << 4,
        HasClassName = 1 << 3,
        HasCacheAsBitmap = 1 << 2,
        HasBlendMode = 1 << 1,
        HasFilterList = 1 << 0,
        NoFlags = 0
    };

    constexpr PlaceObject3Flag operator|(PlaceObject3Flag a, const PlaceObject3Flag b) noexcept
    {
        return static_cast<PlaceObject3Flag>(static_cast<u16>(a) | static_cast<u16>(b));
    }

    constexpr PlaceObject3Flag operator&(PlaceObject3Flag a, const PlaceObject3Flag b) noexcept
    {
        return static_cast<PlaceObject3Flag>(static_cast<u16>(a) & static_cast<u16>(b));
    }

    constexpr PlaceObject3Flag operator~(const PlaceObject3Flag a) noexcept
    {
        return static_cast<PlaceObject3Flag>(~static_cast<u16>(a));
    }

    constexpr PlaceObject3Flag operator&=(PlaceObject3Flag& a, const PlaceObject3Flag b) noexcept
    {
        a = a & b;
        return a;
    }

    constexpr PlaceObject3Flag operator|=(PlaceObject3Flag& a, const PlaceObject3Flag b) noexcept
    {
        a = a | b;
        return a;
    }

    struct PlaceObject3Flags
    {
        PlaceObject3Flag flags;

        [[nodiscard]] constexpr bool get(const PlaceObject3Flag mask) const noexcept
        {
            return static_cast<bool>(flags & mask);
        }
        constexpr void set(const PlaceObject3Flag mask, const bool value) noexcept
        {
            if (value) flags |= mask;
            else flags &= ~mask;
        }
        constexpr void set(const u16 value) noexcept
        {
            flags = static_cast<PlaceObject3Flag>(value);

            //(u16)(PlaceObject3Flag::HasMatrix |
            //    PlaceObject3Flag::HasCharacter |
            //    PlaceObject3Flag::HasBlendMode |
            //    PlaceObject3Flag::HasFilterList)
            //    == 0x0603u;
        }
    };
}