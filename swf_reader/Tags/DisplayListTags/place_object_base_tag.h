/**
 * @file    place_object_base_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "display_list_base_tag.h"
#include "Data/swf_matrix.h"

namespace swf_reader::tags::display_list_tags
{
    class PlaceObjectBaseTag : public DisplayListBaseTag
    {
    public:
        u16 depth;
        u16 character_id;
        data::SwfMatrix matrix = data::SwfMatrix::identity();
    };
}
