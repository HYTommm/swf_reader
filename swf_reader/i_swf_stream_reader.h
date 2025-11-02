/**
 * @file    i_swf_stream_reader.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "cpp_base_type.h"
#include <string>
#include <vector>

#include "Data/swf_matrix.h"
#include "Tags/swf_tag_data.h"
#include "swf_stream_reader_ext.h"

namespace swf_reader
{
    class ISwfStreamReader
    {
    public:
        ISwfStreamReader() = default;
        virtual ~ISwfStreamReader() = default;

        // 删除拷贝操作
        ISwfStreamReader(const ISwfStreamReader&) = delete;
        ISwfStreamReader& operator=(const ISwfStreamReader&) = delete;

        // 允许移动操作
        ISwfStreamReader(ISwfStreamReader&&) = default;
        ISwfStreamReader& operator=(ISwfStreamReader&&) = default;

        [[nodiscard]] virtual bool is_eof() const = 0;
        [[nodiscard]] virtual usize position() const = 0;
        [[nodiscard]] virtual usize bytes_left() const = 0;

        virtual f64 read_fixed8() = 0;
        virtual f64 read_fixed() = 0;
        virtual f64 read_fb(u32 bits) = 0;

        virtual u16 read_ui16() = 0;
        virtual i16 read_si16() = 0;

        virtual u32 read_ui32() = 0;
        virtual i32 read_si32() = 0;

        virtual u64 read_ui64() = 0;
        virtual u32 read_encoded_u32() = 0;

        virtual u8 read_byte() = 0;
        virtual Vec<u8> read_bytes(usize count) = 0;
        virtual Vec<u8> read_rest() = 0;

        virtual std::string read_string() = 0;

        virtual f32 read_float() = 0;
        virtual f64 read_double() = 0;
        virtual f32 read_f16() = 0;

        virtual bool read_bit() = 0;
        virtual i32 read_sb(u32 count) = 0;
        virtual u32 read_ub(u32 count) = 0;
        virtual void align_to_byte() = 0;
    };
}
