/**
 * @file    swf_stream_reader.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "swf_stream_reader.h"

#include <stdexcept>
#include <sstream>
#include <vector>

#include "Tags/tag_stream_ext.h"

namespace swf_reader
{
    SwfStreamReader::SwfStreamReader(std::istream& stream)
        :stream_(&stream)
    {
        if (!stream_ || !*stream_)
        {
            throw std::invalid_argument("Invalid stream provided to SwfStreamReader");
        }
    }

    bool SwfStreamReader::is_eof() const
    {
        return stream_->eof();
    }

    usize SwfStreamReader::position() const
    {
        return static_cast<usize>(stream_->tellg());
    }

    usize SwfStreamReader::bytes_left() const
    {
        const std::streampos current_pos = stream_->tellg();
        stream_->seekg(0, std::ios::end);
        const std::streampos end_pos = stream_->tellg();
        stream_->seekg(current_pos);
        return static_cast<size_t>(end_pos - current_pos);
    }

    f64 SwfStreamReader::read_fixed8()
    {
        return read_ui16() / 256.0;
    }

    f64 SwfStreamReader::read_fixed()
    {
        return read_ui32() / 65536.0;
    }

    f64 SwfStreamReader::read_fb(const u32 bits)
    {
        const i32 value = read_sb(bits);
        return value / 65536.0;
    }

    u16 SwfStreamReader::read_ui16()
    {
        u16 value;
        stream_->read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    i16 SwfStreamReader::read_si16()
    {
        i16 value;
        stream_->read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    u32 SwfStreamReader::read_ui32()
    {
        u32 value;
        stream_->read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    i32 SwfStreamReader::read_si32()
    {
        i32 value;
        stream_->read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    u64 SwfStreamReader::read_ui64()
    {
        u64 value;
        stream_->read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    u8 SwfStreamReader::read_byte()
    {
        align_to_byte();
        u8 value;
        stream_->read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    Vec<u8> SwfStreamReader::read_bytes(const usize count)
    {
        align_to_byte();
        Vec<u8> buffer(count);
        stream_->read(reinterpret_cast<char*>(buffer.data()), static_cast<std::streamsize>(count));
        return buffer;
    }

    Vec<u8> SwfStreamReader::read_rest()
    {
        return read_bytes(bytes_left());
    }

    u32 SwfStreamReader::read_encoded_u32()
    {
        align_to_byte();
        u32 val = 0;

        auto read_byte_part = [this](u32& value, const int shift) -> bool {
            const u8 bt = read_byte();
            value |= (bt & 0x7fu) << shift;
            return (bt & 0x80) != 0;
            };

        if (read_byte_part(val, 0)) return val;
        if (read_byte_part(val, 7)) return val;
        if (read_byte_part(val, 14)) return val;
        if (read_byte_part(val, 21)) return val;

        const u8 bt = read_byte();
        val |= (bt & 0x7fu) << 28;
        return val;
    }

    std::string SwfStreamReader::read_string()
    {
        align_to_byte();
        std::ostringstream oss;
        u8 bt;

        while ((bt = read_byte()) > 0)
        {
            oss << static_cast<char>(bt);
        }

        return oss.str();
    }

    f32 SwfStreamReader::read_float()
    {
        float value;
        stream_->read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    f64 SwfStreamReader::read_double()
    {
        const u32 high = read_ui32();
        const u32 low = read_ui32();
        const u64 combined = (static_cast<u64>(high) << 32) | low;

        // 安全的方式：使用 memcpy 避免未定义行为
        f64 result;
        std::memcpy(&result, &combined, sizeof(result));
        return result;
    }

    float SwfStreamReader::read_f16()
    {
        const u16 data = read_ui16();
        if (data == 0) return 0.0f;

        const i32 sign = data & 0x8000;
        const i32 exp = (data & 0x7c00) >> 10;
        i32 m = (data & 0x3ff) | 0x400;

        if (sign != 0) m = -m;
        const i32 k = 1 << exp;
        constexpr float bias = static_cast <f32>(1 << 25);

        return static_cast<f32>(m) * static_cast <f32>(k) / bias;
    }

    bool SwfStreamReader::read_bit()
    {
        const u8 bit_index = bit_context_.bit_index & 0x07u;
        if (bit_index == 0)
        {
            bit_context_.cached_byte = read_byte();
        }
        bit_context_.bit_index++;
        return ((bit_context_.cached_byte << bit_index) & 0x80) != 0;
    }

    i32 SwfStreamReader::read_sb(u32 count)
    {
        if (count == 0) return 0;

        const bool sign = read_bit();
        u32 res = sign ? std::numeric_limits<u32>::max() : 0;
        count--;

        for (u32 i = 0; i < count; ++i)
        {
            const bool bit = read_bit();
            res = (res << 1) | (bit ? 1u : 0u);
        }

        return static_cast<i32>(res);
    }

    u32 SwfStreamReader::read_ub(const u32 count)
    {
        if (count == 0) return 0;

        u32 res = 0;
        for (u32 i = 0; i < count; ++i)
        {
            const bool bit = read_bit();
            res = (res << 1) | (bit ? 1u : 0u);
        }

        return res;
    }

    void SwfStreamReader::align_to_byte()
    {
        bit_context_.bit_index = 0;
        bit_context_.cached_byte = 0;
    }
}