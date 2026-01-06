/**
 * @file    shape_morphing_base_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "Tags/swf_tag_base.h"

namespace swf_reader::tags::shape_morphing_tags
{
    class ShapeMorphingBaseTag : public SwfTagBase
    {
    public:
        u16 character_id;
        data::SwfRect start_bounds;
        data::SwfRect end_bounds;
        u32 offset;
    };
}
