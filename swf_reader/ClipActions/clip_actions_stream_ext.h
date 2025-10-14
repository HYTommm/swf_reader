/**
 * @file    clip_actions_stream_ext.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "clip_actions_list.h"
#include "clip_event_flags.h"
#include "cpp_base_type.h"
#include "i_swf_stream_reader.h"

namespace swf_reader
{
	class ISwfStreamReader;
}

namespace swf_reader::clip_actions {
	class ClipActionRecord;
	class ClipActionsList;

	class ClipActionsStreamExt {
	public:
		static void read_clip_actions(ISwfStreamReader& reader, u8 swf_version, ClipActionsList& clip_actions);
		static void read_clip_action_records(ISwfStreamReader& reader, u8 swf_version, Vec<Box<ClipActionRecord>>& target);
		static void read_clip_action_record(ISwfStreamReader& reader, u8 swf_version, Box<ClipActionRecord>& record);
		static ClipEventFlags read_clip_event_flags(ISwfStreamReader& reader, u8 swf_version);
	};
}
