/**
 * @file    swf_tag_base.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "cpp_base_type.h"
#include "iswf_tag_visitor.h"
#include "swf_tag_types.h"

namespace swf_reader::tags
{
	
	class SwfTagBase {
	public:
		SwfTagBase() = default;
		virtual ~SwfTagBase() = default;

		// 删除拷贝操作（多态基类通常不应该被拷贝）
		SwfTagBase(const SwfTagBase&) = delete;
		SwfTagBase& operator=(const SwfTagBase&) = delete;

		// 允许移动操作
		SwfTagBase(SwfTagBase&&) = default;
		SwfTagBase& operator=(SwfTagBase&&) = default;

		/// <summary>
            /// Gets swf tag type.
            /// </summary>
		SwfTagType tag_type;

		/// <summary>
            /// Gets or sets rest data that is not parsed into properties.
            /// </summary>
		Option<Vec<u8>> rest_data;

		/// <summary>
            /// Accept visitor.
            /// </summary>
		template<typename TArg, typename TResult>
		TResult& accept_visitor(ISwfTagVisitor<TArg, TResult&>& visitor, TArg& arg);
		
	};

}
