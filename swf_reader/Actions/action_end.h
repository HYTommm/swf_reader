/**
 * @file    action_end.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include "action_base.h"
#include "action_code.h"

namespace swf_reader::actions {
	class ActionEnd : public ActionBase
	{
		ActionEnd()
		{
			action_code	= ActionCode::End;
		}

	public:
		ActionBase& accept_visitor(IActionVisitor<u8, ActionBase&>& visitor, u8 arg) override
		{
			return visitor.visit(*this, arg);
		}
	};
}
