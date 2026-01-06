/**
 * @file   swf_tag_deserializer.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include <sstream>

#include "i_swf_tag_visitor.h"
#include "swf_tag_data.h"
#include "swf_file.h"
#include "swf_tags_factory.h"
#include "swf_stream_reader.h"

namespace swf_reader::tags
{
    class SwfTagDeserializer : public ISwfTagVisitor<ISwfStreamReader, SwfTagBase&>
    {
    public:
        explicit SwfTagDeserializer(SwfFile& file) : file_(&file)
        {
        }

        Box<SwfTagBase> read_tag(const SwfTagData& tag_data);

        Box<SwfTagBase> read_tag(const SwfTagData& tag_data, ISwfStreamReader& reader);

        //template<typename StyleChangeShapeRecord_T>
        //Box<StyleChangeShapeRecord_T> read_tag(const SwfTagData& data);

        [[nodiscard]] SwfFile& swf_file() const;
        SwfTagBase& visit(display_list_tags::PlaceObjectTag& tag, ISwfStreamReader& reader) override;
        SwfTagBase& visit(display_list_tags::PlaceObject2Tag& tag, ISwfStreamReader& reader) override;
        SwfTagBase& visit(display_list_tags::PlaceObject3Tag& tag, ISwfStreamReader& reader) override;
        SwfTagBase& visit(display_list_tags::RemoveObjectTag& tag, ISwfStreamReader& reader) override;
        SwfTagBase& visit(display_list_tags::RemoveObject2Tag& tag, ISwfStreamReader& reader) override;
        SwfTagBase& visit(display_list_tags::ShowFrameTag& tag, ISwfStreamReader& reader) override;

        SwfTagBase& visit(control_tags::EndTag& tag, ISwfStreamReader& reader) override;
        SwfTagBase& visit(control_tags::FileAttributesTag& tag, ISwfStreamReader& reader) override;
        SwfTagBase& visit(control_tags::SetBackgroundColorTag& tag, ISwfStreamReader& reader) override;

        SwfTagBase& visit(shape_tags::DefineShapeTag& tag, ISwfStreamReader& reader) override;
        SwfTagBase& visit(shape_tags::DefineShape2Tag& tag, ISwfStreamReader& reader) override;
        SwfTagBase& visit(shape_tags::DefineShape3Tag& tag, ISwfStreamReader& reader) override;
        SwfTagBase& visit(shape_tags::DefineShape4Tag& tag, ISwfStreamReader& reader) override;

        SwfTagBase& visit(shape_morphing_tags::DefineMorphShapeTag& tag, ISwfStreamReader& reader) override;
        SwfTagBase& visit(shape_morphing_tags::DefineMorphShape2Tag& tag, ISwfStreamReader& reader) override;

        SwfTagBase& visit(DefineSpriteTag& tag, ISwfStreamReader& reader) override;
        SwfTagBase& visit(UnknownTag& tag, ISwfStreamReader& reader) override;

        // ... 其他 Visit 方法的实现将继续

    private:
        SwfFile* file_;
        SwfTagsFactory factory_;
    };
}
