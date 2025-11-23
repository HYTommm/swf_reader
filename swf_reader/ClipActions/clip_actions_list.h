/**
 * @file    clip_actions_list.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "clip_action_record.h"
#include "clip_event_flags.h"
#include "cpp_base_type.h"

namespace swf_reader::clip_actions
{
    class ClipActionsList
    {
    public:
        u16 reserved;
        ClipEventFlags flags;
        Vec<Box<ClipActionRecord>> records;
    };
}
