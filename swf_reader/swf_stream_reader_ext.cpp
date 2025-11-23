/**
 * @file    swf_stream_reader_ext.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#include "swf_stream_reader_ext.h"

#include <stdexcept>

#include "i_swf_stream_reader.h"
#include "Data/swf_header.h"
#include "Data/swf_matrix.h"
#include "Data/swf_symbol_reference.h"

namespace swf_reader
{
    SwfFileInfo SwfStreamReaderExt::read_swf_file_info(ISwfStreamReader& reader)
    {
        SwfFileInfo header;

        std::string sig;
        sig += static_cast<char>(reader.read_byte());
        sig += static_cast<char>(reader.read_byte());
        sig += static_cast<char>(reader.read_byte());

        if (sig == "FWS") header.format = SwfFormat::FWS;
        else if (sig == "CWS") header.format = SwfFormat::CWS;
        else if (sig == "ZWS") header.format = SwfFormat::ZWS;
        else throw std::runtime_error("Unsupported File Format: " + sig);

        header.version = reader.read_byte();

        u32 len = 0;
        len |= (static_cast<u32>(reader.read_byte()) << 0);
        len |= (static_cast<u32>(reader.read_byte()) << 8);
        len |= (static_cast<u32>(reader.read_byte()) << 16);
        len |= (static_cast<u32>(reader.read_byte()) << 24);

        header.file_length = len;
        return header;
    }

    data::SwfHeader SwfStreamReaderExt::read_swf_header(ISwfStreamReader& reader)
    {
        data::SwfHeader header;
        header.frame_size = read_rect(reader);
        header.frame_rate = reader.read_fixed8();
        header.frame_count = reader.read_ui16();
        return header;
    }

    data::SwfRect SwfStreamReaderExt::read_rect(ISwfStreamReader& reader)
    {
        data::SwfRect rect;
        read_rect(reader, rect);
        return rect;
    }

    void SwfStreamReaderExt::read_rect(ISwfStreamReader& reader, data::SwfRect& rect)
    {
        const auto bits = reader.read_ub(5);
        rect.x_min = reader.read_sb(bits);
        rect.x_max = reader.read_sb(bits);
        rect.y_min = reader.read_sb(bits);
        rect.y_max = reader.read_sb(bits);
        reader.align_to_byte();
    }

    data::SwfMatrix SwfStreamReaderExt::read_matrix(ISwfStreamReader& reader)
    {
        auto matrix = data::SwfMatrix::identity();

        if (reader.read_bit())
        {
            const u8 bits = static_cast<u8>(reader.read_ub(5));
            matrix.scale_x = reader.read_fb(bits);
            matrix.scale_y = reader.read_fb(bits);
        }

        if (reader.read_bit())
        {
            const u8 bits = static_cast<u8>(reader.read_ub(5));
            matrix.rotate_skew_0 = reader.read_fb(bits);
            matrix.rotate_skew_1 = reader.read_fb(bits);
        }

        const u8 translate_bits = static_cast<u8>(reader.read_ub(5));
        matrix.translate_x = reader.read_sb(translate_bits);
        matrix.translate_y = reader.read_sb(translate_bits);

        reader.align_to_byte();
        return matrix;
    }

    data::SwfSymbolReference SwfStreamReaderExt::read_symbol_reference(ISwfStreamReader& reader)
    {
        data::SwfSymbolReference ref;
        ref.symbol_id = reader.read_ui16();
        ref.symbol_name = reader.read_string();
        return ref;
    }
}