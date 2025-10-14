#pragma once

#include "cpp_base_type.h"

namespace swf_reader::shapes::fillstyles
{
	enum class FillStyleType : u8
	{
		SolidColor = 0x00,
		LinearGradient = 0x10,
		RadialGradient = 0x12,
		FocalGradient = 0x13,
		RepeatingBitmap = 0x40,
		ClippedBitmap = 0x41,
		NonSmoothedRepeatingBitmap = 0x42,
		NonSmoothedClippedBitmap = 0x43
	};
}
