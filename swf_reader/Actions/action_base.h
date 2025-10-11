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
#include "iaction_visitor.h"


namespace swf_reader::actions {
	enum class ActionCode : u8;

	class ActionBase {
    public:
        ActionCode action_code;

        template<typename TArg, typename TResult>
        TResult& accept_visitor(IActionVisitor<TArg, TResult&>& visitor, TArg& arg);
    };
}
