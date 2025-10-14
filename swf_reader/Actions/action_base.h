/**
 * @file    action_base.h
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
	enum class ActionCode : u8;

	class ActionBase {
	public:
		ActionBase() = default;
		virtual ~ActionBase() = default;

		// 删除拷贝操作
		ActionBase(const ActionBase&) = delete;
		ActionBase& operator=(const ActionBase&) = delete;

		// 可移动
		ActionBase(ActionBase&&) = default;
		ActionBase& operator=(ActionBase&&) = default;

		ActionCode action_code;

		//template<typename TArg, typename TResult>
		//TResult& accept_visitor(IActionVisitor<TArg, TResult&>& visitor, TArg& arg);
		virtual ActionBase& accept_visitor(IActionVisitor<u8, ActionBase&>&, u8) = 0;
	};
}
