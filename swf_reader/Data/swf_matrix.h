/**
 * @file    swf_matrix.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "cpp_base_type.h"
#include "swf_vector.h"

namespace swf_reader::data
{
	struct SwfMatrix {
		f64 scale_x{ 1.0 };
		f64 scale_y{ 1.0 };
		f64 rotate_skew_0{ 0.0 };
		f64 rotate_skew_1{ 0.0 };
		i32 translate_x{ 0 };
		i32 translate_y{ 0 };

		SwfMatrix() = default;
		SwfMatrix(const double x, const double x1, const double x2, const double x3, const int i, const int i1)
			: scale_x(x), scale_y(x1), rotate_skew_0(x2), rotate_skew_1(x3), translate_x(i), translate_y(i1)
		{
		}

		static SwfMatrix identity()
		{
			return SwfMatrix{ 1.0, 1.0, 0.0, 0.0, 0, 0 };
		}

		[[nodiscard]] bool has_scale() const
		{
			return scale_x != 1.0 || scale_y != 1.0;
		}

		[[nodiscard]] bool has_rotate() const
		{
			return rotate_skew_0 != 0.0 || rotate_skew_1 != 0.0;
		}

		[[nodiscard]] SwfVector transform(const SwfVector& vector) const
		{
			return SwfVector{
				static_cast<i32>(vector.x * (has_scale() ? scale_x : 1.0) +
					vector.y * (has_rotate() ? rotate_skew_1 : 0.0) +
					translate_x),
				static_cast<i32>(vector.y * (has_scale() ? scale_y : 1.0) +
					vector.x * (has_rotate() ? rotate_skew_0 : 0.0) +
					translate_y)
			};
		}
	};
}
