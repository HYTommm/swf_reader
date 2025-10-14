/**
 * @file    i_action_visitor.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

namespace swf_reader::actions {
	class ActionEnd;

	template<typename TArg, typename TResult>
	class IActionVisitor {
	public:
		IActionVisitor() = default;
		virtual ~IActionVisitor() = default;

		// 删除拷贝操作（抽象基类通常不应该被拷贝）
		IActionVisitor(const IActionVisitor&) = delete;
		IActionVisitor& operator=(const IActionVisitor&) = delete;
		// 允许移动操作
		IActionVisitor(IActionVisitor&&) = default;
		IActionVisitor& operator=(IActionVisitor&&) = default;

		virtual TResult& visit(ActionEnd& action, TArg arg) = 0;
	};
}
