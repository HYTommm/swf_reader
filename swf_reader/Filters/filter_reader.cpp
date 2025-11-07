#include "filter_reader.h"
#include "i_swf_stream_reader.h"
namespace swf_reader::filters
{
    Box<BaseFilter> FilterReader::read(ISwfStreamReader& reader)
    {
        return nullptr;
    }
}