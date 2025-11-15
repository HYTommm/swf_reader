/**
 * @file    file_attributes_flag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "cpp_base_type.h"

namespace swf_reader::tags::control_tags
{
    enum class FileAttributesFlag : u8
    {
        Reserved0 = 1 << 7,
        UseDirectBlit = 1 << 6,
        UseGPU = 1 << 5,
        HasMetadata = 1 << 4,
        ActionScript3 = 1 << 3,
        SuppressCrossDomainCaching = 1 << 2,
        SwfRelativeUrls = 1 << 1,
        UseNetwork = 1 << 0,
        NoFlags = 0
    };

    constexpr FileAttributesFlag operator|(FileAttributesFlag a, const FileAttributesFlag b) noexcept
    {
        return static_cast<FileAttributesFlag>(static_cast<u8>(a) | static_cast<u8>(b));
    }

    constexpr FileAttributesFlag operator&(FileAttributesFlag a, const FileAttributesFlag b) noexcept
    {
        return static_cast<FileAttributesFlag>(static_cast<u8>(a) & static_cast<u8>(b));
    }

    constexpr FileAttributesFlag operator~(const FileAttributesFlag a) noexcept
    {
        return static_cast<FileAttributesFlag>(~static_cast<u8>(a));
    }

    constexpr FileAttributesFlag operator&=(FileAttributesFlag& a, const FileAttributesFlag b) noexcept
    {
        a = a & b;
        return a;
    }

    constexpr FileAttributesFlag operator|=(FileAttributesFlag& a, const FileAttributesFlag b) noexcept
    {
        a = a | b;
        return a;
    }

    struct FileAttributesFlags
    {
        FileAttributesFlag flags{ FileAttributesFlag::NoFlags };

        [[nodiscard]] constexpr bool get(const FileAttributesFlag mask) const noexcept
        {
            return static_cast<bool>(flags & mask);
        }

        constexpr void set(const FileAttributesFlag mask, const bool value) noexcept
        {
            if (value) flags |= mask;
            else flags &= ~mask;
        }

        constexpr void set(const u8 value) noexcept
        {
            flags = static_cast<FileAttributesFlag>(value);
        }

        [[nodiscard]] constexpr bool is_empty() const noexcept
        {
            return flags == FileAttributesFlag::NoFlags;
        }
    };
}
