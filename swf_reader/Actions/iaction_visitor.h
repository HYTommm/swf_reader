#pragma once

namespace swf_reader::actions {
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

		virtual TResult visit(ActionGotoFrame& action, TArg arg);

	};
}