/**
 * @file    swf_vector.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "cpp_base_type.h"

namespace swf_reader::data
{
	struct SwfVector {
		i32 x{ 0 };
		i32 y{ 0 };

		SwfVector() = default;
		SwfVector(i32 x, i32 y) : x(x), y(y)
		{
		}
	};
}
