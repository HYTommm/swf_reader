/**
 * @file    swf_rect.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "swf_vector.h"

namespace swf_reader::data
{
	struct SwfRect
	{
		i32 x_min{ 0 };
		i32 y_min{ 0 };
		i32 x_max{ 0 };
		i32 y_max{ 0 };

		SwfRect() = default;
		SwfRect(const i32 x_min, const i32 y_min, const i32 x_max, const i32 y_max)
			: x_min(x_min), y_min(y_min), x_max(x_max), y_max(y_max)
		{
		}

		[[nodiscard]] SwfVector top_left() const
		{
			return { x_min, y_min };
		}

		[[nodiscard]] SwfVector top_right() const
		{
			return { x_max, y_min };
		}

		[[nodiscard]] SwfVector bottom_left() const
		{
			return { x_min, y_max };
		}

		[[nodiscard]] SwfVector bottom_right() const
		{
			return { x_max, y_max };
		}
	};
}
