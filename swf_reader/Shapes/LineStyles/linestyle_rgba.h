/**
 * @file    linestyle_rgba.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "cpp_base_type.h"
#include "Data/swf_rgba.h"
namespace swf_reader::shapes::linestyles
{
	struct LineStyleRgba
	{
		u16 width;
		data::SwfRgba color;
	};
}