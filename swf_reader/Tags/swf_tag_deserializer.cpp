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
#include <print>
#include <sstream>

#include "swf_stream_reader.h"
#include "swf_tag_base.h"
#include "swf_tag_types.h"

#include "ClipActions/clip_actions_stream_ext.h"
#include "Data/color_transform_stream_ext.h"
#include "Filters/filter_stream_ext.h"
#include "DisplayListTags/place_object_tag.h"
#include "DisplayListTags/place_object2_tag.h"
#include "DisplayListTags/place_object3_tag.h"
#include "DisplayListTags/remove_object_tag.h"
#include "DisplayListTags/remove_object2_tag.h"
#include "DisplayListTags/show_frame_tag.h"
#include "ControlTags/end_tag.h"
#include "ControlTags/file_attributes_tag.h"
#include "ControlTags/set_background_color_tag.h"
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
#include "ShapeMorphing/morph_fillstyle_stream_ext.h"
#include "ShapeMorphing/morph_linestyle_stream_ext.h"
#include "ShapeMorphingTags/define_morph_shape2_tag.h"
#include "ShapeMorphingTags/define_morph_shape_tag.h"

namespace swf_reader::tags
{
    Box<SwfTagBase> SwfTagDeserializer::read_tag(const SwfTagData& tag_data)
    {
        const std::string data = std::string(reinterpret_cast<const char*>(tag_data.data.data()), tag_data.data.size());
        const Box<std::istringstream> stream = boxed<std::istringstream>(data);
        const Box<SwfStreamReader> reader = boxed<SwfStreamReader>(*stream);
        //const SwfTagType type = tag_data.type;
        return read_tag(tag_data, *reader);
    }

    Box<SwfTagBase> SwfTagDeserializer::read_tag(const SwfTagData& tag_data, ISwfStreamReader& reader)
    {
        Box<SwfTagBase> tag = factory_.create(tag_data.type);
        if (tag->get_type() == SwfTagType::Unknown)
        {
            return tag;
        }
        tag->tag_length = tag_data.data.size();
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
        if (tag.flags.get(PlaceObject2Flag::HasColorTransform)) tag.color_transform = boxed<data::ColorTransformRgba>(data::ColorTransformStreamExt::read_color_transform_rgba(reader));
        if (tag.flags.get(PlaceObject2Flag::HasRatio))          tag.ratio = reader.read_ui16();
        if (tag.flags.get(PlaceObject2Flag::HasName))           tag.name = reader.read_string();
        if (tag.flags.get(PlaceObject2Flag::HasClipDepth))      tag.clip_depth = reader.read_ui16();
        if (tag.flags.get(PlaceObject2Flag::HasClipActions))    clip_actions::ClipActionsStreamExt::read_clip_actions(reader, file_->file_info.version, *tag.clip_actions);
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(display_list_tags::PlaceObject3Tag& tag, ISwfStreamReader& reader)
    {
        using namespace display_list_tags;
        u8 high_bits = reader.read_byte();
        u8 low_bits = reader.read_byte();
        tag.flags.set(high_bits, low_bits);

        //tag.flags.set(PlaceObject3Flag::HasClipActions, reader.read_bit());
        //tag.flags.set(PlaceObject3Flag::HasClipDepth, reader.read_bit());
        //tag.flags.set(PlaceObject3Flag::HasName, reader.read_bit());
        //tag.flags.set(PlaceObject3Flag::HasRatio, reader.read_bit());
        //tag.flags.set(PlaceObject3Flag::HasColorTransform, reader.read_bit());
        //tag.flags.set(PlaceObject3Flag::HasMatrix, reader.read_bit());
        //tag.flags.set(PlaceObject3Flag::HasCharacter, reader.read_bit());
        //tag.flags.set(PlaceObject3Flag::Move, reader.read_bit());

        //tag.flags.set(PlaceObject3Flag::Reserved, reader.read_bit());
        //tag.flags.set(PlaceObject3Flag::HasOpaqueBackground, reader.read_bit());
        //tag.flags.set(PlaceObject3Flag::HasVisible, reader.read_bit());
        //tag.flags.set(PlaceObject3Flag::HasImage, reader.read_bit());
        //tag.flags.set(PlaceObject3Flag::HasClassName, reader.read_bit());
        //tag.flags.set(PlaceObject3Flag::HasCacheAsBitmap, reader.read_bit());
        //tag.flags.set(PlaceObject3Flag::HasBlendMode, reader.read_bit());
        //tag.flags.set(PlaceObject3Flag::HasFilterList, reader.read_bit());

        tag.depth = reader.read_ui16();
        if (tag.flags.get(PlaceObject3Flag::HasClassName)) tag.class_name = reader.read_string();
        if (tag.flags.get(PlaceObject3Flag::HasCharacter)) tag.character_id = reader.read_ui16();
        if (tag.flags.get(PlaceObject3Flag::HasMatrix)) tag.matrix = SwfStreamReaderExt::read_matrix(reader);
        if (tag.flags.get(PlaceObject3Flag::HasColorTransform)) tag.color_tranform = data::ColorTransformStreamExt::read_color_transform_rgba(reader);
        if (tag.flags.get(PlaceObject3Flag::HasRatio)) tag.ratio = reader.read_ui16();
        if (tag.flags.get(PlaceObject3Flag::HasName)) tag.name = reader.read_string();
        if (tag.flags.get(PlaceObject3Flag::HasClipDepth)) tag.clip_depth = reader.read_ui16();
        if (tag.flags.get(PlaceObject3Flag::HasFilterList)) filters::FilterStreamExt::read_filter_list(reader, tag.filters);
        if (tag.flags.get(PlaceObject3Flag::HasBlendMode)) tag.blend_mode = static_cast<data::BlendMode>(reader.read_byte());
        if (tag.flags.get(PlaceObject3Flag::HasVisible)) tag.visible = reader.read_byte();
        if (tag.flags.get(PlaceObject3Flag::HasOpaqueBackground)) tag.background_color = data::ColorStreamExt::read_rgba(reader);
        if (tag.flags.get(PlaceObject3Flag::HasClipActions)) clip_actions::ClipActionsStreamExt::read_clip_actions(reader, file_->file_info.version, tag.clip_actions);
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(display_list_tags::RemoveObjectTag& tag, ISwfStreamReader& reader)
    {
        tag.character_id = reader.read_ui16();
        tag.depth = reader.read_ui16();
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(display_list_tags::RemoveObject2Tag& tag, ISwfStreamReader& reader)
    {
        tag.depth = reader.read_ui16();
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(display_list_tags::ShowFrameTag& tag, ISwfStreamReader& reader)
    {
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(control_tags::EndTag& tag, ISwfStreamReader& reader)
    {
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(control_tags::FileAttributesTag& tag, ISwfStreamReader& reader)
    {
        tag.flags.set(reader.read_byte());
        //std::print("{:d}", tag.flags.get(control_tags::FileAttributesFlag::ActionScript3));
        tag.reserved = reader.read_ub(24);
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(control_tags::SetBackgroundColorTag& tag, ISwfStreamReader& reader)
    {
        tag.color = data::ColorStreamExt::read_rgb(reader);
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(shape_tags::DefineShapeTag& tag, ISwfStreamReader& reader)
    {
        tag.shape_id = reader.read_ui16();
        tag.shape_bounds = SwfStreamReaderExt::read_rect(reader);
        shapes::FillStyleStreamExt::read_to_fillstyles_rgb(reader, tag.fill_styles, false);
        shapes::LineStyleStreamExt::read_to_linestyles_rgb(reader, tag.line_styles, false);
        tag.shape_records.reserve(tag.tag_length / 2 + 1);
        shapes::ShapeRecordStreamExt::read_to_shape_records_rgb(reader, tag.shape_records);
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(shape_tags::DefineShape2Tag& tag, ISwfStreamReader& reader)
    {
        tag.shape_id = reader.read_ui16();
        tag.shape_bounds = SwfStreamReaderExt::read_rect(reader);
        shapes::FillStyleStreamExt::read_to_fillstyles_rgb(reader, tag.fill_styles, true);
        shapes::LineStyleStreamExt::read_to_linestyles_rgb(reader, tag.line_styles, true);
        tag.shape_records.reserve(tag.tag_length / 2 + 1);
        shapes::ShapeRecordStreamExt::read_to_shape_records_rgb(reader, tag.shape_records);
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(shape_tags::DefineShape3Tag& tag, ISwfStreamReader& reader)
    {
        tag.shape_id = reader.read_ui16();
        tag.shape_bounds = SwfStreamReaderExt::read_rect(reader);
        shapes::FillStyleStreamExt::read_to_fillstyles_rgba(reader, tag.fill_styles);
        shapes::LineStyleStreamExt::read_to_linestyles_rgba(reader, tag.line_styles);
        tag.shape_records.reserve(tag.tag_length / 2 + 1);
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
        tag.shape_records.reserve(tag.tag_length / 2 + 1);
        shapes::ShapeRecordStreamExt::read_to_shape_records_ex(reader, tag.shape_records);

        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(shape_morphing_tags::DefineMorphShapeTag& tag, ISwfStreamReader& reader)
    {
        tag.character_id = reader.read_ui16();
        tag.start_bounds = SwfStreamReaderExt::read_rect(reader);
        tag.end_bounds = SwfStreamReaderExt::read_rect(reader);
        tag.offset = reader.read_ui32();
        shape_morphing::MorphFillStyleStreamExt::read_to_fillstyles(reader, tag.fill_styles);
        shape_morphing::MorphLineStyleStreamExt::read_to_linestyles(reader, tag.line_styles);
        tag.start_edge.reserve(tag.tag_length / 2 + 1);
        tag.end_edge.reserve(tag.tag_length / 2 + 1);
        shapes::ShapeRecordStreamExt::read_to_shape_records_rgb(reader, tag.start_edge);
        shapes::ShapeRecordStreamExt::read_to_shape_records_rgb(reader, tag.end_edge);
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(shape_morphing_tags::DefineMorphShape2Tag& tag, ISwfStreamReader& reader)
    {
        tag.character_id = reader.read_ui16();
        tag.start_bounds = SwfStreamReaderExt::read_rect(reader);
        tag.end_bounds = SwfStreamReaderExt::read_rect(reader);
        tag.start_edge_bounds = SwfStreamReaderExt::read_rect(reader);
        tag.end_edge_bounds = SwfStreamReaderExt::read_rect(reader);
        tag.offset = reader.read_ui32();
        shape_morphing::MorphFillStyleStreamExt::read_to_fillstyles(reader, tag.fill_styles);
        shape_morphing::MorphLineStyleStreamExt::read_to_linestyles_ex(reader, tag.line_styles);
        tag.start_edge.reserve(tag.tag_length / 2 + 1);
        tag.end_edge.reserve(tag.tag_length / 2 + 1);
        shapes::ShapeRecordStreamExt::read_to_shape_records_rgb(reader, tag.start_edge);
        shapes::ShapeRecordStreamExt::read_to_shape_records_rgb(reader, tag.end_edge);
        return tag;
    }

    SwfTagBase& SwfTagDeserializer::visit(DefineSpriteTag& tag, ISwfStreamReader& reader)
    {
        tag.sprite_id = reader.read_ui16();
        tag.frames_count = reader.read_ui16();
        tag.tags.reserve(tag.tag_length / 16 + tag.frames_count * 2);
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

    //template<typename StyleChangeShapeRecord_T>
    //Box<StyleChangeShapeRecord_T> SwfTagDeserializer::read_tag(const SwfTagData& data)
    //{
    //    return Box<StyleChangeShapeRecord_T>(static_cast<StyleChangeShapeRecord_T*>(read_tag(data).release()));
    //}
}