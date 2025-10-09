/**
 * @file    place_object2_flag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "cpp_base_type.h"

namespace swf_reader::tags::display_list_tags {

    enum class PlaceObject2Flag : u8 {
        HasClipActions    = 1 << 7,
        HasClipDepth      = 1 << 6,
        HasName           = 1 << 5,
        HasRatio          = 1 << 4,
        HasColorTransform = 1 << 3,
        HasMatrix         = 1 << 2,
        HasCharacter      = 1 << 1,
        HasMove           = 1 << 0,
        NoFlags           = 0
    };

    constexpr PlaceObject2Flag operator|(PlaceObject2Flag a, const PlaceObject2Flag b) noexcept {
        return static_cast<PlaceObject2Flag>(static_cast<u8>(a) | static_cast<u8>(b));
    }

    constexpr PlaceObject2Flag operator&(PlaceObject2Flag a, const PlaceObject2Flag b) noexcept {
        return static_cast<PlaceObject2Flag>(static_cast<u8>(a) & static_cast<u8>(b));
    }

    constexpr PlaceObject2Flag operator~(const PlaceObject2Flag a) noexcept {
        return static_cast<PlaceObject2Flag>(~static_cast<u8>(a));
    }

    constexpr PlaceObject2Flag operator&=(PlaceObject2Flag& a, const PlaceObject2Flag b) noexcept {
        a = a & b;
        return a;
    }

    constexpr PlaceObject2Flag operator|=(PlaceObject2Flag& a, const PlaceObject2Flag b) noexcept {
        a = a | b;
        return a;
    }

    struct PlaceObject2Flags {
        PlaceObject2Flag flags;

        [[nodiscard]] bool get(const PlaceObject2Flag mask) const noexcept
        {
            return static_cast<bool>(flags & mask);
        }
        void set(const PlaceObject2Flag mask, const bool value) noexcept
        {
            if (value) flags |= mask;
            else flags &= ~mask;
        }
    };
}
