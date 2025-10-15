/**
 * @file    swf_rgba.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "cpp_base_type.h"
#include "swf_rgb.h"

namespace swf_reader::data {
	struct SwfRgba {
		u8 red{ 0 };
		u8 green{ 0 };
		u8 blue{ 0 };
		u8 alpha{ 255 };  // 默认不透明

		SwfRgba() = default;
		SwfRgba(const u8 red, const u8 green, const u8 blue, const u8 alpha = 255)
			: red(red), green(green), blue(blue), alpha(alpha)
		{
		}

		// 从 SwfRgb 转换的构造函数
		explicit SwfRgba(const SwfRgb& rgb, const u8 alpha = 255)
			: red(rgb.red), green(rgb.green), blue(rgb.blue), alpha(alpha)
		{
		}
	};
}