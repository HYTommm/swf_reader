/**
 * @file    clip_actions_stream_ext.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#include "clip_actions_stream_ext.h"
#include "i_swf_stream_reader.h"
#include "clip_actions_list.h"

namespace swf_reader::clip_actions
{
    void ClipActionsStreamExt::read_clip_actions(ISwfStreamReader& reader, const u8 swf_version, ClipActionsList& clip_actions)
    {
        clip_actions.reserved = reader.read_ui16();
        clip_actions.flags = read_clip_event_flags(reader, swf_version);
        read_clip_action_records(reader, swf_version, clip_actions.records);
    }

    void ClipActionsStreamExt::read_clip_action_records(ISwfStreamReader& reader, const u8 swf_version, Vec<Box<ClipActionRecord>>& target)
    {
        bool empty;
        do
        {
            Box<ClipActionRecord> record = boxed<ClipActionRecord>();
            read_clip_action_record(reader, swf_version, record);
            empty = record->flags.is_empty();
            target.push_back(std::move(record));
        } while (!empty);
    }

    ClipEventFlags ClipActionsStreamExt::read_clip_event_flags(ISwfStreamReader& reader, const u8 swf_version)
    {
        ClipEventFlags flags;

        // 使用 set 函数 - 更清晰、更安全
        flags.set(ClipEventFlag::KeyUp, reader.read_bit());
        flags.set(ClipEventFlag::KeyDown, reader.read_bit());
        flags.set(ClipEventFlag::MouseUp, reader.read_bit());
        flags.set(ClipEventFlag::MouseDown, reader.read_bit());
        flags.set(ClipEventFlag::MouseMove, reader.read_bit());
        flags.set(ClipEventFlag::Unload, reader.read_bit());
        flags.set(ClipEventFlag::EnterFrame, reader.read_bit());
        flags.set(ClipEventFlag::Load, reader.read_bit());

        flags.set(ClipEventFlag::DragOver, reader.read_bit());
        flags.set(ClipEventFlag::RollOut, reader.read_bit());
        flags.set(ClipEventFlag::RollOver, reader.read_bit());
        flags.set(ClipEventFlag::ReleaseOutside, reader.read_bit());
        flags.set(ClipEventFlag::Release, reader.read_bit());
        flags.set(ClipEventFlag::Press, reader.read_bit());
        flags.set(ClipEventFlag::Initialize, reader.read_bit());
        flags.set(ClipEventFlag::Data, reader.read_bit());

        if (swf_version >= 6)
        {
            flags.reserved = static_cast<u8>(reader.read_ub(5));

            flags.set(ClipEventFlag::Construct, reader.read_bit());
            flags.set(ClipEventFlag::KeyPress, reader.read_bit());
            flags.set(ClipEventFlag::DragOut, reader.read_bit());

            flags.reserved2 = reader.read_byte();
        }

        // TODO: Read clip actions
        return flags;
    }

    void ClipActionsStreamExt::read_clip_action_record(ISwfStreamReader& reader, const u8 swf_version, Box<ClipActionRecord>& record)
    {
        record->flags = read_clip_event_flags(reader, swf_version);
        if (record->flags.is_empty()) return;

        record->offset = reader.read_ui32();

        if (record->flags.get(ClipEventFlag::KeyPress))
        {
            record->key_code = reader.read_byte();
        }
    }
}