/**
 * @file   swf_tag_forward_decls.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once

namespace swf_reader::tags
{
    // 前向声明所有具体的标签类
    namespace display_list_tags
    {
        class PlaceObjectTag;
        class PlaceObject2Tag;
        class PlaceObject3Tag;
        class RemoveObjectTag;
        class RemoveObject2Tag;
        class ShowFrameTag;
    }
    namespace control_tags
    {
        class SetBackgroundColorTag;
        class FrameLabelTag;
        class ProtectTag;
        class EndTag;
        class ExportAssetsTag;
        class ImportAssetsTag;
        class EnableDebuggerTag;
        class EnableDebugger2Tag;
        class ScriptLimitsTag;
        class SetTabIndexTag;
        class FileAttributesTag;
        class ImportAssets2Tag;
        class SymbolClassTag;
        class MetadataTag;
        class DefineScalingGridTag;
        class DefineSceneAndFrameLabelDataTag;
    }
    class DoActionTag;
    class DoInitActionTag;
    class DoABCTag;
    class DoABCDefineTag;
    namespace shape_tags
    {
        class DefineShapeTag;
        class DefineShape2Tag;
        class DefineShape3Tag;
        class DefineShape4Tag;
    }
    class DefineBitsTag;
    class JPEGTablesTag;
    class DefineBitsJPEG2Tag;
    class DefineBitsJPEG3Tag;
    class DefineBitsLosslessTag;
    class DefineBitsLossless2Tag;
    class DefineBitsJPEG4Tag;
    class DefineMorphShapeTag;
    class DefineMorphShape2Tag;
    class DefineFontTag;
    class DefineFontInfoTag;
    class DefineFontInfo2Tag;
    class DefineFont2Tag;
    class DefineFont3Tag;
    class DefineFontAlignZonesTag;
    class DefineFontNameTag;
    class DefineTextTag;
    class DefineText2Tag;
    class DefineEditTextTag;
    class CSMTextSettingsTag;
    class DefineFont4Tag;
    class DefineSoundTag;
    class StartSoundTag;
    class StartSound2Tag;
    class SoundStreamHeadTag;
    class SoundStreamHead2Tag;
    class SoundStreamBlockTag;
    class DefineButtonTag;
    class DefineButton2Tag;
    class DefineButtonCxformTag;
    class DefineButtonSoundTag;
    class DefineSpriteTag;
    class DefineVideoStreamTag;
    class VideoFrameTag;
    class DefineBinaryDataTag;
    class DebugIDTag;
    class ProductInfoTag;
    class UnknownTag;
}
