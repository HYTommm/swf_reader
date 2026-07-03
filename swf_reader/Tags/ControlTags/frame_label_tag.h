/**
 * @file    frame_label_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once
#include <optional>
#include <string>

#include "i_swf_stream_reader.h"
#include "primitive_types.h"
#include "Tags/i_swf_tag_visitor.h"
#include "Tags/swf_tag_base.h"
#include "Tags/swf_tag_types.h"

namespace swf_reader::tags::control_tags
{
    class FrameLabelTag : public SwfTagBase
    {
    public:
        std::string name;  ///< 标签名称
        Option<u8> anchor_flag;  ///< 可选的锚点标志
        [[nodiscard]] SwfTagType get_type() const override
        {
            return SwfTagType::FrameLabel;
        }
        SwfTagBase& accept_visitor(ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}