/**
 * @file    clip_action_record.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "clip_event_flags.h"
#include "Actions/action_base.h"
#include "cpp_base_type.h"
namespace swf_reader::clip_actions
{
    class ClipActionRecord
    {
    public:
        ClipEventFlags flags;
        u32 offset;
        u8 key_code;
        Vec<Box<actions::ActionBase>> actions;
        ClipActionRecord() = default;
        ~ClipActionRecord() = default;

        // 移动语义支持
        ClipActionRecord(ClipActionRecord&&) = default;
        // 禁止拷贝（因为unique_ptr不可拷贝）
        ClipActionRecord(const ClipActionRecord&) = delete;
        ClipActionRecord& operator=(const ClipActionRecord&) = delete;
    };
}
