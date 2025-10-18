/**
 * @file    shape_base_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "Tags/swf_tag_base.h"
#include "Data/swf_rect.h"

namespace swf_reader::tags::shape_tags
{
	class ShapeBaseTag : public SwfTagBase
	{
	public:
		u16 shape_id;
		data::SwfRect shape_bounds;

		ShapeBaseTag() = default;
		virtual ~ShapeBaseTag() = default;
	};
}