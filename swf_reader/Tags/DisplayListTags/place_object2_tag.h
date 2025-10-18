/**
 * @file    place_object2_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include <string>

#include "place_object2_flag.h"
#include "place_object_base_tag.h"
#include "ClipActions/clip_actions_list.h"
#include "Data/color_transform_rgba.h"

namespace swf_reader::tags::display_list_tags
{
	class PlaceObject2Tag : public PlaceObjectBaseTag
	{
	public:
		PlaceObject2Flags flags;
		Box<data::ColorTransformRGBA> color_transform = nullptr;
		u16 ratio = 0;
		std::string name;
		u16 clip_depth = 0;

		Box<clip_actions::ClipActionsList> clip_actions = nullptr;

		//PlaceObject2Tag() : flags()
		//{
		//	tag_type = SwfTagType::PlaceObject2;
		//}

		SwfTagType get_type () const override
		{
			return SwfTagType::PlaceObject2;
		}

		SwfTagBase& accept_visitor (ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& reader) override
		{
			return visitor.visit (*this, reader);
		}
	};
}
