/**
 * @file    swf_stream_reader.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "i_swf_stream_reader.h"

namespace swf_reader
{
    class SwfStreamReader : public ISwfStreamReader
    {
    public:
        explicit SwfStreamReader(std::istream& stream);
        //explicit SwfStreamReader(u8* data, usize size);

        ~SwfStreamReader() override = default;
        SwfStreamReader(const SwfStreamReader&) = delete;
        SwfStreamReader& operator=(const SwfStreamReader&) = delete;

        SwfStreamReader(SwfStreamReader&&) = default;
        SwfStreamReader& operator=(SwfStreamReader&&) = default;

        [[nodiscard]] bool is_eof() const override;
        [[nodiscard]] usize position() const override;
        [[nodiscard]] usize bytes_left() const override;

        f32 read_fixed8() override;
        f32 read_fixed() override;
        f32 read_fb(u32 bits) override;

        u16 read_ui16() override;
        i16 read_si16() override;

        u32  read_ui32() override;
        i32 read_si32() override;

        u64 read_ui64() override;
        u32 read_encoded_u32() override;

        u8 read_byte() override;
        Vec<u8> read_bytes(usize count) override;
        Vec<u8> read_rest() override;

        std::string read_string() override;

        f32 read_float() override;
        f64 read_double() override;
        f32 read_f16() override;

        bool read_bit() override;
        i32 read_sb(u32 count) override;
        u32 read_ub(u32 count) override;
        void align_to_byte() override;

    private:
        struct BitContext
        {
            u8 cached_byte{ 0 };
            u8 bit_index{ 0 };
        };

        std::istream* stream_;
        BitContext bit_context_;
        std::streampos end_pos;

        //Vec<u8> my_buffer = Vec<u8>(buffer_size);
    };
}
