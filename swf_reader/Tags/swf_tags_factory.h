/**
 * @file    swf_tags_factory.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
 //#include "swf_tag_base.h"
#include "swf_tag_forward_decls.h"
#include "unknown_tag.h"
#include "DisplayListTags/place_object_tag.h"
#include "DisplayListTags/place_object2_tag.h"
#include "DisplayListTags/place_object3_tag.h"
#include "ShapeTags/define_shape_tag.h"
#include "ShapeTags/define_shape2_tag.h"
#include "ShapeTags/define_shape3_tag.h"
#include "ShapeTags/define_shape4_tag.h"
#include "define_sprite_tag.h"

namespace swf_reader::tags
{
    class SwfTagsFactory
    {
    public:
        Box<SwfTagBase> create(SwfTagType tag_type)
        {
            switch (tag_type)
            {
                //case SwfTagType::End:
                //	return std::make_unique<EndTag>();
                //case SwfTagType::ShowFrame:
                //	return std::make_unique<display_list_tags::ShowFrameTag>();
                case SwfTagType::DefineShape:
                    return boxed<shape_tags::DefineShapeTag>();
                case SwfTagType::PlaceObject:
                    return boxed<display_list_tags::PlaceObjectTag>();
                    //case SwfTagType::RemoveObject:
                    //	return std::make_unique<display_list_tags::RemoveObjectTag>();
                    //case SwfTagType::DefineBits:
                    //	return std::make_unique<DefineBitsTag>();
                    //case SwfTagType::DefineButton:
                    //	return std::make_unique<DefineButtonTag>();
                    //case SwfTagType::JPEGTables:
                    //	return std::make_unique<JPEGTablesTag>();
                    //case SwfTagType::SetBackgroundColor:
                    //	return std::make_unique<SetBackgroundColorTag>();
                    //case SwfTagType::DefineFont:
                    //	return std::make_unique<DefineFontTag>();
                    //case SwfTagType::DefineText:
                    //	return std::make_unique<DefineTextTag>();
                    //case SwfTagType::DoAction:
                    //	return std::make_unique<DoActionTag>();
                    //case SwfTagType::DefineFontInfo:
                    //	return std::make_unique<DefineFontInfoTag>();
                    //case SwfTagType::DefineSound:
                    //	return std::make_unique<DefineSoundTag>();
                    //case SwfTagType::StartSound:
                    //	return std::make_unique<StartSoundTag>();
                    //case SwfTagType::DefineButtonSound:
                    //	return std::make_unique<DefineButtonSoundTag>();
                    //case SwfTagType::SoundStreamHead:
                    //	return std::make_unique<SoundStreamHeadTag>();
                    //case SwfTagType::SoundStreamBlock:
                    //	return std::make_unique<SoundStreamBlockTag>();
                    //case SwfTagType::DefineBitsLossless:
                    //	return std::make_unique<DefineBitsLosslessTag>();
                    //case SwfTagType::DefineBitsJPEG2:
                    //	return std::make_unique<DefineBitsJPEG2Tag>();
                case SwfTagType::DefineShape2:
                    return boxed<shape_tags::DefineShape2Tag>();
                    //case SwfTagType::DefineButtonCxform:
                    //	return std::make_unique<DefineButtonCxformTag>();
                    //case SwfTagType::Protect:
                    //	return std::make_unique<ProtectTag>();
                case SwfTagType::PlaceObject2:
                    return boxed<display_list_tags::PlaceObject2Tag>();
                    //case SwfTagType::RemoveObject2:
                    //	return std::make_unique<display_list_tags::RemoveObject2Tag>();
                case SwfTagType::DefineShape3:
                    return boxed<shape_tags::DefineShape3Tag>();
                    //case SwfTagType::DefineText2:
                    //	return std::make_unique<DefineText2Tag>();
                    //case SwfTagType::DefineButton2:
                    //	return std::make_unique<DefineButton2Tag>();
                    //case SwfTagType::DefineBitsJPEG3:
                    //	return std::make_unique<DefineBitsJPEG3Tag>();
                    //case SwfTagType::DefineBitsLossless2:
                    //	return std::make_unique<DefineBitsLossless2Tag>();
                    //case SwfTagType::DefineEditText:
                    //	return std::make_unique<DefineEditTextTag>();
                case SwfTagType::DefineSprite:
                    return boxed<DefineSpriteTag>();
                    //case SwfTagType::FrameLabel:
                    //	return std::make_unique<FrameLabelTag>();
                    //case SwfTagType::SoundStreamHead2:
                    //	return std::make_unique<SoundStreamHead2Tag>();
                    //case SwfTagType::DefineMorphShape:
                    //	return std::make_unique<DefineMorphShapeTag>();
                    //case SwfTagType::DefineFont2:
                    //	return std::make_unique<DefineFont2Tag>();
                    //case SwfTagType::ExportAssets:
                    //	return std::make_unique<ExportAssetsTag>();
                    //case SwfTagType::ImportAssets:
                    //	return std::make_unique<ImportAssetsTag>();
                    //case SwfTagType::EnableDebugger:
                    //	return std::make_unique<EnableDebuggerTag>();
                    //case SwfTagType::DoInitAction:
                    //	return std::make_unique<DoInitActionTag>();
                    //case SwfTagType::DefineVideoStream:
                    //	return std::make_unique<DefineVideoStreamTag>();
                    //case SwfTagType::VideoFrame:
                    //	return std::make_unique<VideoFrameTag>();
                    //case SwfTagType::DefineFontInfo2:
                    //	return std::make_unique<DefineFontInfo2Tag>();
                    //case SwfTagType::EnableDebugger2:
                    //	return std::make_unique<EnableDebugger2Tag>();
                    //case SwfTagType::ScriptLimits:
                    //	return std::make_unique<ScriptLimitsTag>();
                    //case SwfTagType::SetTabIndex:
                    //	return std::make_unique<SetTabIndexTag>();
                    //case SwfTagType::FileAttributes:
                    //	return std::make_unique<FileAttributesTag>();
                case SwfTagType::PlaceObject3:
                    return boxed<display_list_tags::PlaceObject3Tag>();
                    //case SwfTagType::ImportAssets2:
                    //	return std::make_unique<ImportAssets2Tag>();
                    //case SwfTagType::DoABCDefine:
                    //	return std::make_unique<DoABCDefineTag>();
                    //case SwfTagType::DefineFontAlignZones:
                    //	return std::make_unique<DefineFontAlignZonesTag>();
                    //case SwfTagType::CSMTextSettings:
                    //	return std::make_unique<CSMTextSettingsTag>();
                    //case SwfTagType::DefineFont3:
                    //	return std::make_unique<DefineFont3Tag>();
                    //case SwfTagType::SymbolClass:
                    //	return std::make_unique<SymbolClassTag>();
                    //case SwfTagType::Metadata:
                    //	return std::make_unique<MetadataTag>();
                    //case SwfTagType::DefineScalingGrid:
                    //	return std::make_unique<DefineScalingGridTag>();
                    //case SwfTagType::DoABC:
                    //	return std::make_unique<DoABCTag>();
                case SwfTagType::DefineShape4:
                    return boxed<shape_tags::DefineShape4Tag>();
                    //case SwfTagType::DefineMorphShape2:
                    //	return std::make_unique<DefineMorphShape2Tag>();
                    //case SwfTagType::DefineSceneAndFrameLabelData:
                    //	return std::make_unique<DefineSceneAndFrameLabelDataTag>();
                    //case SwfTagType::DefineBinaryData:
                    //	return std::make_unique<DefineBinaryDataTag>();
                    //case SwfTagType::DefineFontName:
                    //	return std::make_unique<DefineFontNameTag>();
                    //case SwfTagType::StartSound2:
                    //	return std::make_unique<StartSound2Tag>();
                    //case SwfTagType::DefineBitsJPEG4:
                    //	return std::make_unique<DefineBitsJPEG4Tag>();
                    //case SwfTagType::DefineFont4:
                    //	return std::make_unique<DefineFont4Tag>();

                default:
                    return boxed<UnknownTag>();
            }
        }
    };
}
