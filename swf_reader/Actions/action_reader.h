/**
 * @file    action_reader.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "cpp_base_type.h"
#include "i_action_visitor.h"

namespace swf_reader::actions {
	class ActionBase;

	class ActionReader : IActionVisitor<u8, ActionBase&> {
	public:
		ActionBase& visit(ActionEnd& action, u8 arg) override;
	};
}
