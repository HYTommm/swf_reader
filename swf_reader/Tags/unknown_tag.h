/**
 * @file    unknown_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "swf_tag_base.h"

namespace swf_reader::tags {

	class UnknownTag : public SwfTagBase {
	public:
		UnknownTag()
		{
			tag_type = SwfTagType::Unknown;
		}
	};
}
