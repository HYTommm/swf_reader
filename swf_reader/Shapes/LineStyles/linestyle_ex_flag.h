/**
 * @file    linestyle_ex_flag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "cpp_base_type.h"

namespace swf_reader::shapes::linestyles
{
	enum class LineStyleExFlag : u8
	{
		HasFill = 1 << 0,  ///< 是否有填充样式
		NoHScale = 1 << 1,  ///< 是否禁止水平缩放
		NoVScale = 1 << 2,  ///< 是否禁止垂直缩放
		PixelHinting = 1 << 3,  ///< 是否有像素提示
		NoClose = 1 << 4,  ///< 是否不闭合路径
		Reserved5 = 1 << 5,  ///< 保留位5
		Reserved6 = 1 << 6,  ///< 保留位6
		Reserved7 = 1 << 7,  ///< 保留位7
		NoFlags = 0        ///< 无标志
	};

	constexpr LineStyleExFlag operator|(LineStyleExFlag a, const LineStyleExFlag b) noexcept
	{
		return static_cast<LineStyleExFlag>(static_cast<u8>(a) | static_cast<u8>(b));
	}

	constexpr LineStyleExFlag operator&(LineStyleExFlag a, const LineStyleExFlag b) noexcept
	{
		return static_cast<LineStyleExFlag>(static_cast<u8>(a) & static_cast<u8>(b));
	}

	constexpr LineStyleExFlag operator~(const LineStyleExFlag a) noexcept
	{
		return static_cast<LineStyleExFlag>(~static_cast<u8>(a));
	}

	constexpr LineStyleExFlag operator&=(LineStyleExFlag& a, const LineStyleExFlag b) noexcept
	{
		a = a & b;
		return a;
	}

	constexpr LineStyleExFlag operator|=(LineStyleExFlag& a, const LineStyleExFlag b) noexcept
	{
		a = a | b;
		return a;
	}

	struct LineStyleExFlags
	{
		LineStyleExFlag flags;

		/// <summary>
		/// 检查指定标志位是否设置
		/// </summary>
		/// <param name="mask">要检查的标志位掩码</param>
		/// <returns>如果标志位设置则返回true，否则返回false</returns>
		[[nodiscard]] constexpr bool get(const LineStyleExFlag mask) const noexcept
		{
			return static_cast<bool>(flags & mask);
		}

		/// <summary>
		/// 设置或清除指定标志位
		/// </summary>
		/// <param name="mask">要设置的标志位掩码</param>
		/// <param name="value">要设置的值（true表示设置，false表示清除</param>
		constexpr void set(const LineStyleExFlag mask, const bool value) noexcept
		{
			if (value) flags |= mask;
			else flags &= ~mask;
		}

		//// 属性访问器方法
		//[[nodiscard]] constexpr bool hasFill() const noexcept { return get(LineStyleExFlag::HasFill); }
		//constexpr void setHasFill(const bool value) noexcept { set(LineStyleExFlag::HasFill, value); }

		//[[nodiscard]] constexpr bool noHScale() const noexcept { return get(LineStyleExFlag::NoHScale); }
		//constexpr void setNoHScale(const bool value) noexcept { set(LineStyleExFlag::NoHScale, value); }

		//[[nodiscard]] constexpr bool noVScale() const noexcept { return get(LineStyleExFlag::NoVScale); }
		//constexpr void setNoVScale(const bool value) noexcept { set(LineStyleExFlag::NoVScale, value); }

		//[[nodiscard]] constexpr bool pixelHinting() const noexcept { return get(LineStyleExFlag::PixelHinting); }
		//constexpr void setPixelHinting(const bool value) noexcept { set(LineStyleExFlag::PixelHinting, value); }

		//[[nodiscard]] constexpr bool noClose() const noexcept { return get(LineStyleExFlag::NoClose); }
		//constexpr void setNoClose(const bool value) noexcept { set(LineStyleExFlag::NoClose, value); }
	};
}