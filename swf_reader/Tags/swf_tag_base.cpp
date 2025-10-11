/**
 * @file    swf_tag_base.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "swf_tag_base.h"

#include "iswf_stream_reader.h"
#include "DisplayListTags/place_object2_tag.h"
#include "DisplayListTags/place_object_tag.h"

namespace swf_reader::tags {
	template <typename TArg, typename TResult>
	TResult& SwfTagBase::accept_visitor(ISwfTagVisitor<TArg, TResult&>& visitor, TArg& arg)
	{
		switch (tag_type)
		{
			case SwfTagType::PlaceObject:
				return visitor.visit(*static_cast<display_list_tags::PlaceObjectTag*>(this), arg);
			case SwfTagType::PlaceObject2:
				return visitor.visit(*static_cast<display_list_tags::PlaceObject2Tag*>(this), arg);
			default:
				throw std::runtime_error("Unhandled tag type in accept_visitor");
		}
	}

	template SwfTagBase& SwfTagBase::accept_visitor<ISwfStreamReader, SwfTagBase>(
		ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>&,
		ISwfStreamReader&);
}
