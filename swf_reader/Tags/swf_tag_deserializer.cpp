/**
 * @file    swf_tag_deserializer.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "swf_tag_deserializer.h"

#include <optional>
#include <sstream>

#include "swf_stream_reader.h"
#include "swf_tag_base.h"
#include "swf_tag_types.h"

#include "ClipActions/clip_actions_stream_ext.h"
#include "Data/color_transform_stream_ext.h"
#include "DisplayListTags/place_object_tag.h"
#include "DisplayListTags/place_object2_tag.h"
#include "ShapeTags/define_shape_tag.h"
#include "ShapeTags/define_shape2_tag.h"
#include "ShapeTags/define_shape3_tag.h"
#include "ShapeTags/define_shape4_tag.h"
#include "define_sprite_tag.h"
#include "tag_stream_ext.h"
#include "Shapes/fillstyle_stream_ext.h"
#include "Shapes/linestyle_stream_ext.h"
#include "Shapes/shape_record_stream_ext.h"

#include "swf_file.h"

namespace swf_reader::tags
{
    Box<SwfTagBase> SwfTagDeserializer::read_tag(const SwfTagData& tag_data)
    {
        const std::string data = std::string(reinterpret_cast<const char*>(tag_data.data.data()), tag_data.data.size());
        const Box<std::istringstream> stream = boxed<std::istringstream>(data);
        const Box<SwfStreamReader> reader = boxed<SwfStreamReader>(*stream);
        const SwfTagType type = tag_data.type;
        return read_tag(type, *reader);
    }

    Box<SwfTagBase> SwfTagDeserializer::read_tag(const SwfTagType type, ISwfStreamReader& reader)
    {
        Box<SwfTagBase> tag = factory_.create(type);
        if (tag->get_type() == SwfTagType::Unknown)
        {
            return tag;
        }
        tag->accept_visitor(*this, reader);

        if (reader.bytes_left() > 0)
        {
            tag->rest_data = reader.read_rest();
        }
        else
        {
            tag->rest_data = std::nullopt;
        }

        return tag;
    }

    [[nodiscard]] SwfFile& SwfTagDeserializer::swf_file() const
    {
        return *file_;
    }

    SwfTagBase& SwfTagDeserializer::visit(display_list_tags::PlaceObjectTag& tag, ISwfStreamReader& reader)
    {
        tag.character_id = reader.read_ui16();
        tag.depth = reader.read_ui16();
        tag.matrix = SwfStreamReaderExt::read_matrix(reader);
        if (!reader.is_eof())
        {
            tag.color_transform = boxed<data::ColorTransformRGB>(data::ColorTransformStreamExt::read_color_transform_rgb(reader));
        }
        else
        {
            tag.color_transform = nullptr;
        }
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(display_list_tags::PlaceObject2Tag& tag, ISwfStreamReader& reader)
    {
        using namespace display_list_tags;
        tag.flags.set(PlaceObject2Flag::HasClipActions, reader.read_bit());
        tag.flags.set(PlaceObject2Flag::HasClipDepth, reader.read_bit());
        tag.flags.set(PlaceObject2Flag::HasName, reader.read_bit());
        tag.flags.set(PlaceObject2Flag::HasRatio, reader.read_bit());
        tag.flags.set(PlaceObject2Flag::HasColorTransform, reader.read_bit());
        tag.flags.set(PlaceObject2Flag::HasMatrix, reader.read_bit());
        tag.flags.set(PlaceObject2Flag::HasCharacter, reader.read_bit());
        tag.flags.set(PlaceObject2Flag::HasMove, reader.read_bit());

        tag.depth = reader.read_ui16();
        if (tag.flags.get(PlaceObject2Flag::HasCharacter))      tag.character_id = reader.read_ui16();
        if (tag.flags.get(PlaceObject2Flag::HasMatrix))         tag.matrix = SwfStreamReaderExt::read_matrix(reader);
        if (tag.flags.get(PlaceObject2Flag::HasColorTransform)) tag.color_transform = boxed<data::ColorTransformRGBA>(data::ColorTransformStreamExt::read_color_transform_rgba(reader));
        if (tag.flags.get(PlaceObject2Flag::HasRatio))          tag.ratio = reader.read_ui16();
        if (tag.flags.get(PlaceObject2Flag::HasName))           tag.name = reader.read_string();
        if (tag.flags.get(PlaceObject2Flag::HasClipDepth))      tag.clip_depth = reader.read_ui16();
        if (tag.flags.get(PlaceObject2Flag::HasClipActions))    clip_actions::ClipActionsStreamExt::read_clip_actions(reader, file_->file_info.version, *tag.clip_actions);
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(shape_tags::DefineShapeTag& tag, ISwfStreamReader& reader)
    {
        tag.shape_id = reader.read_ui16();
        tag.shape_bounds = SwfStreamReaderExt::read_rect(reader);
        shapes::FillStyleStreamExt::read_to_fillstyles_rgb(reader, tag.fill_styles, false);
        shapes::LineStyleStreamExt::read_to_linestyles_rgb(reader, tag.line_styles, false);
        shapes::ShapeRecordStreamExt::read_to_shape_records_rgb(reader, tag.shape_records);
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(shape_tags::DefineShape2Tag& tag, ISwfStreamReader& reader)
    {
        tag.shape_id = reader.read_ui16();
        tag.shape_bounds = SwfStreamReaderExt::read_rect(reader);
        shapes::FillStyleStreamExt::read_to_fillstyles_rgb(reader, tag.fill_styles, true);
        shapes::LineStyleStreamExt::read_to_linestyles_rgb(reader, tag.line_styles, true);
        shapes::ShapeRecordStreamExt::read_to_shape_records_rgb(reader, tag.shape_records);
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(shape_tags::DefineShape3Tag& tag, ISwfStreamReader& reader)
    {
        tag.shape_id = reader.read_ui16();
        tag.shape_bounds = SwfStreamReaderExt::read_rect(reader);
        shapes::FillStyleStreamExt::read_to_fillstyles_rgba(reader, tag.fill_styles);
        shapes::LineStyleStreamExt::read_to_linestyles_rgba(reader, tag.line_styles);
        shapes::ShapeRecordStreamExt::read_to_shape_records_rgba(reader, tag.shape_records);
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(shape_tags::DefineShape4Tag& tag, ISwfStreamReader& reader)
    {
        tag.shape_id = reader.read_ui16();
        SwfStreamReaderExt::read_rect(reader, tag.shape_bounds);
        SwfStreamReaderExt::read_rect(reader, tag.edge_bounds);
        tag.flags.set(reader.read_byte());
        shapes::FillStyleStreamExt::read_to_fillstyles_rgba(reader, tag.fill_styles);
        shapes::LineStyleStreamExt::read_to_linestyles_ex(reader, tag.line_styles);
        shapes::ShapeRecordStreamExt::read_to_shape_records_ex(reader, tag.shape_records);
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(DefineSpriteTag& tag, ISwfStreamReader& reader)
    {
        /* C#:
        tag.SpriteID = reader.ReadUInt16();
        tag.FramesCount = reader.ReadUInt16();
        SwfTagBase subTag;
        do
        {
        subTag = ReadDefineSpriteSubTag(reader);
        if (subTag != null) tag.Tags.Add(subTag);
        } while (subTag != null && subTag.TagType != SwfTagType.End && reader.BytesLeft > 0);
        return tag;
        */

        // C++:

        tag.sprite_id = reader.read_ui16();
        tag.frames_count = reader.read_ui16();
        Box<SwfTagBase> sub_tag;
        bool is_end_tag;
        do
        {
            sub_tag = read_tag(TagStreamExt::read_tag_data(reader));
            is_end_tag = sub_tag && sub_tag->get_type() != SwfTagType::End && reader.bytes_left() > 0;
            if (sub_tag)    tag.tags.push_back(std::move(sub_tag));
        } while (is_end_tag);
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(UnknownTag& tag, ISwfStreamReader& reader)
    {
        tag.rest_data = reader.read_rest();
        return tag;
    }

    template<typename StyleChangeShapeRecord_T>
    Box<StyleChangeShapeRecord_T> SwfTagDeserializer::read_tag(const SwfTagData& data)
    {
        return Box<StyleChangeShapeRecord_T>(static_cast<StyleChangeShapeRecord_T*>(read_tag(data).release()));
    }
}