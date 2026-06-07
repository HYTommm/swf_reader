/**
 * @file    define_scene_and_frame_label_data_tag.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "Data/frame_label_data.h"
#include "Data/scene_offset_data.h"
#include "Tags/swf_tag_base.h"

namespace swf_reader::tags::control_tags
{
    class DefineSceneAndFrameLabelDataTag : public SwfTagBase
    {
    public:
        Vec<data::SceneOffsetData> scenes;
        Vec<data::FrameLabelData> frames;
        SwfTagType get_type() const override
        {
            return SwfTagType::DefineSceneAndFrameLabelData;
        }
        SwfTagBase& accept_visitor(ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>& visitor, ISwfStreamReader& reader) override
        {
            return visitor.visit(*this, reader);
        }
    };
}
