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
#include "DisplayListTags/remove_object_tag.h"
#include "DisplayListTags/remove_object2_tag.h"
#include "DisplayListTags/show_frame_tag.h"

#include "ControlTags/end_tag.h"

#include "ControlTags/set_background_color_tag.h"
#include "ControlTags/file_attributes_tag.h"
#include "ControlTags/define_scene_and_frame_label_data_tag.h"
#include "ControlTags/symbol_class_tag.h"

#include "ShapeTags/define_shape_tag.h"
#include "ShapeTags/define_shape2_tag.h"
#include "ShapeTags/define_shape3_tag.h"
#include "ShapeTags/define_shape4_tag.h"
#include "define_sprite_tag.h"
#include "ShapeMorphingTags/define_morph_shape2_tag.h"
#include "ShapeMorphingTags/define_morph_shape_tag.h"

#include "BitmapTags/define_bits_tag.h"
#include "BitmapTags/jpeg_tables_tag.h"
#include "BitmapTags/define_bits_jpeg2_tag.h"
#include "BitmapTags/define_bits_jpeg3_tag.h"
#include "BitmapTags/define_bits_lossless_tag.h"
#include "BitmapTags/define_bits_lossless2_tag.h"
#include "BitmapTags/define_bits_jpeg4_tag.h"

namespace swf_reader::tags
{
    class SwfTagsFactory
    {
    public:
        Box<SwfTagBase> create(SwfTagType tag_type)
        {
            //return boxed<UnknownTag>();
            switch (tag_type)
            {
                case SwfTagType::End:
                    return boxed<control_tags::EndTag>();
                case SwfTagType::ShowFrame:
                    return boxed<display_list_tags::ShowFrameTag>();
                case SwfTagType::DefineShape:
                    return boxed<shape_tags::DefineShapeTag>();
                case SwfTagType::PlaceObject:
                    return boxed<display_list_tags::PlaceObjectTag>();
                case SwfTagType::RemoveObject:
                    return boxed<display_list_tags::RemoveObjectTag>();
                case SwfTagType::DefineBits:
                    return boxed<bitmap_tags::DefineBitsTag>();
                    //case SwfTagType::DefineButton:
                    //	return boxed<DefineButtonTag>();
                case SwfTagType::JPEGTables:
                    return boxed<bitmap_tags::JpegTablesTag>();
                case SwfTagType::SetBackgroundColor:
                    return boxed<control_tags::SetBackgroundColorTag>();
                    //case SwfTagType::DefineFont:
                    //	return boxed<DefineFontTag>();
                    //case SwfTagType::DefineText:
                    //	return boxed<DefineTextTag>();
                    //case SwfTagType::DoAction:
                    //	return boxed<DoActionTag>();
                    //case SwfTagType::DefineFontInfo:
                    //	return boxed<DefineFontInfoTag>();
                    //case SwfTagType::DefineSound:
                    //	return boxed<DefineSoundTag>();
                    //case SwfTagType::StartSound:
                    //	return boxed<StartSoundTag>();
                    //case SwfTagType::DefineButtonSound:
                    //	return boxed<DefineButtonSoundTag>();
                    //case SwfTagType::SoundStreamHead:
                    //	return boxed<SoundStreamHeadTag>();
                    //case SwfTagType::SoundStreamBlock:
                    //	return boxed<SoundStreamBlockTag>();
                case SwfTagType::DefineBitsLossless:
                    return boxed<bitmap_tags::DefineBitsLosslessTag>();
                case SwfTagType::DefineBitsJPEG2:
                    return boxed<bitmap_tags::DefineBitsJpeg2Tag>();
                case SwfTagType::DefineShape2:
                    return boxed<shape_tags::DefineShape2Tag>();
                    //case SwfTagType::DefineButtonCxform:
                    //	return boxed<DefineButtonCxformTag>();
                    //case SwfTagType::Protect:
                    //	return boxed<ProtectTag>();
                case SwfTagType::PlaceObject2:
                    return boxed<display_list_tags::PlaceObject2Tag>();
                case SwfTagType::RemoveObject2:
                    return boxed<display_list_tags::RemoveObject2Tag>();
                case SwfTagType::DefineShape3:
                    return boxed<shape_tags::DefineShape3Tag>();
                    //case SwfTagType::DefineText2:
                    //	return boxed<DefineText2Tag>();
                    //case SwfTagType::DefineButton2:
                    //	return boxed<DefineButton2Tag>();
                case SwfTagType::DefineBitsJPEG3:
                    return boxed<bitmap_tags::DefineBitsJpeg3Tag>();
                case SwfTagType::DefineBitsLossless2:
                    return boxed<bitmap_tags::DefineBitsLossless2Tag>();
                    //case SwfTagType::DefineEditText:
                    //	return boxed<DefineEditTextTag>();
                case SwfTagType::DefineSprite:
                    return boxed<DefineSpriteTag>();
                    //case SwfTagType::FrameLabel:
                    //	return boxed<FrameLabelTag>();
                    //case SwfTagType::SoundStreamHead2:
                    //	return boxed<SoundStreamHead2Tag>();
                case SwfTagType::DefineMorphShape:
                    return boxed<shape_morphing_tags::DefineMorphShapeTag>();
                    //case SwfTagType::DefineFont2:
                    //	return boxed<DefineFont2Tag>();
                    //case SwfTagType::ExportAssets:
                    //	return boxed<ExportAssetsTag>();
                    //case SwfTagType::ImportAssets:
                    //	return boxed<ImportAssetsTag>();
                    //case SwfTagType::EnableDebugger:
                    //	return boxed<EnableDebuggerTag>();
                    //case SwfTagType::DoInitAction:
                    //	return boxed<DoInitActionTag>();
                    //case SwfTagType::DefineVideoStream:
                    //	return boxed<DefineVideoStreamTag>();
                    //case SwfTagType::VideoFrame:
                    //	return boxed<VideoFrameTag>();
                    //case SwfTagType::DefineFontInfo2:
                    //	return boxed<DefineFontInfo2Tag>();
                    //case SwfTagType::EnableDebugger2:
                    //	return boxed<EnableDebugger2Tag>();
                    //case SwfTagType::ScriptLimits:
                    //	return boxed<ScriptLimitsTag>();
                    //case SwfTagType::SetTabIndex:
                    //	return boxed<SetTabIndexTag>();
                case SwfTagType::FileAttributes:
                    return boxed<control_tags::FileAttributesTag>();
                case SwfTagType::PlaceObject3:
                    return boxed<display_list_tags::PlaceObject3Tag>();
                    //case SwfTagType::ImportAssets2:
                    //	return boxed<ImportAssets2Tag>();
                    //case SwfTagType::DoABCDefine:
                    //	return boxed<DoABCDefineTag>();
                    //case SwfTagType::DefineFontAlignZones:
                    //	return boxed<DefineFontAlignZonesTag>();
                    //case SwfTagType::CSMTextSettings:
                    //	return boxed<CSMTextSettingsTag>();
                    //case SwfTagType::DefineFont3:
                    //	return boxed<DefineFont3Tag>();
                case SwfTagType::SymbolClass:
                    return boxed<control_tags::SymbolClassTag>();
                    //case SwfTagType::Metadata:
                    //	return boxed<MetadataTag>();
                    //case SwfTagType::DefineScalingGrid:
                    //	return boxed<DefineScalingGridTag>();
                    //case SwfTagType::DoABC:
                    //	return boxed<DoABCTag>();
                case SwfTagType::DefineShape4:
                    return boxed<shape_tags::DefineShape4Tag>();
                case SwfTagType::DefineMorphShape2:
                    return boxed<shape_morphing_tags::DefineMorphShape2Tag>();
                case SwfTagType::DefineSceneAndFrameLabelData:
                    return boxed<control_tags::DefineSceneAndFrameLabelDataTag>();
                    //case SwfTagType::DefineBinaryData:
                    //	return boxed<DefineBinaryDataTag>();
                    //case SwfTagType::DefineFontName:
                    //	return boxed<DefineFontNameTag>();
                    //case SwfTagType::StartSound2:
                    //	return boxed<StartSound2Tag>();
                case SwfTagType::DefineBitsJPEG4:
                    return boxed<bitmap_tags::DefineBitsJpeg4Tag>();
                    //case SwfTagType::DefineFont4:
                    //	return boxed<DefineFont4Tag>();

                default:
                    return boxed<UnknownTag>();
            }
        }
    };
}
