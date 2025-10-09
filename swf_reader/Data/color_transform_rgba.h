/**
 * @file    color_transform_rgba.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "cpp_base_type.h"

namespace swf_reader::data {
	class ColorTransformRGBA {
	public:
		i16 red_mult_term;
		i16 green_mult_term;
		i16 blue_mult_term;
		i16 alpha_mult_term;

		i16 red_add_term;
		i16 green_add_term;
		i16 blue_add_term;
		i16 alpha_add_term;

		bool has_add_terms;
		bool has_mult_terms;
	};
}