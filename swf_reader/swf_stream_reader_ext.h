/**
 * @file    swf_stream_reader_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

//#include "iswf_stream_reader.h"
#include "swf_file_info.h"
#include "Data/swf_header.h"
#include "Data/swf_matrix.h"
#include "Data/swf_symbol_reference.h"

namespace swf_reader {
	class ISwfStreamReader;

	class SwfStreamReaderExt {
    public:
        static SwfFileInfo read_swf_file_info(ISwfStreamReader& reader);
        static data::SwfHeader read_swf_header(ISwfStreamReader& reader);
        static data::SwfRect read_rect(ISwfStreamReader& reader);
        static void read_rect(ISwfStreamReader& reader, data::SwfRect& rect);
        static data::SwfMatrix read_matrix(ISwfStreamReader& reader);
        static data::SwfSymbolReference read_symbol_reference(ISwfStreamReader& reader);
    };

}
