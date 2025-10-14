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