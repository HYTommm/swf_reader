/**
 * @file    action_reader.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#include "action_reader.h"

 //#include "action_base.h"
#include "action_end.h"

namespace swf_reader::actions
{
	ActionBase& ActionReader::visit (ActionEnd& action, u8 arg)
	{
		return action;
	}
}