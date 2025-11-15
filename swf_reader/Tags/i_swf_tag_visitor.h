/**
 * @file    i_swf_tag_visitor.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "swf_tag_forward_decls.h"

namespace swf_reader::tags
{
    template<typename TArg, typename TResult>
    class ISwfTagVisitor
    {
    public:
        ISwfTagVisitor() = default;
        virtual ~ISwfTagVisitor() = default;

        // 删除拷贝操作（抽象基类通常不应该被拷贝）
        ISwfTagVisitor(const ISwfTagVisitor&) = delete;
        ISwfTagVisitor& operator=(const ISwfTagVisitor&) = delete;

        // 允许移动操作
        ISwfTagVisitor(ISwfTagVisitor&&) = default;
        ISwfTagVisitor& operator=(ISwfTagVisitor&&) = default;

#pragma region Display list tags
        virtual TResult& visit(display_list_tags::PlaceObjectTag& tag, TArg& arg) = 0;
        virtual TResult& visit(display_list_tags::PlaceObject2Tag& tag, TArg& arg) = 0;
        virtual TResult& visit(display_list_tags::PlaceObject3Tag& tag, TArg& arg) = 0;
        virtual TResult& visit(display_list_tags::RemoveObjectTag& tag, TArg& arg) = 0;
        virtual TResult& visit(display_list_tags::RemoveObject2Tag& tag, TArg& arg) = 0;
        virtual TResult& visit(display_list_tags::ShowFrameTag& tag, TArg& arg) = 0;
#pragma endregion

#pragma region Control tags
        virtual TResult& visit(control_tags::SetBackgroundColorTag& tag, TArg& arg) = 0;
        //virtual TResult& visit(FrameLabelTag& tag,                   TArg& arg) = 0;
        //virtual TResult& visit(ProtectTag& tag,                      TArg& arg) = 0;
        virtual TResult& visit(control_tags::EndTag& tag, TArg& arg) = 0;
        //virtual TResult& visit(ExportAssetsTag& tag,                 TArg& arg) = 0;
        //virtual TResult& visit(ImportAssetsTag& tag,                 TArg& arg) = 0;
        //virtual TResult& visit(EnableDebuggerTag& tag,               TArg& arg) = 0;
        //virtual TResult& visit(EnableDebugger2Tag& tag,              TArg& arg) = 0;
        //virtual TResult& visit(ScriptLimitsTag& tag,                 TArg& arg) = 0;
        //virtual TResult& visit(SetTabIndexTag& tag,                  TArg& arg) = 0;
        virtual TResult& visit(control_tags::FileAttributesTag& tag, TArg& arg) = 0;
        //virtual TResult& visit(ImportAssets2Tag& tag,                TArg& arg) = 0;
        //virtual TResult& visit(SymbolClassTag& tag,                  TArg& arg) = 0;
        //virtual TResult& visit(MetadataTag& tag,                     TArg& arg) = 0;
        //virtual TResult& visit(DefineScalingGridTag& tag,            TArg& arg) = 0;
        //virtual TResult& visit(DefineSceneAndFrameLabelDataTag& tag, TArg& arg) = 0;
#pragma endregion

#pragma region Action tags
        //virtual TResult& visit(DoActionTag& tag,     TArg& arg) = 0;
        //virtual TResult& visit(DoInitActionTag& tag, TArg& arg) = 0;
        //virtual TResult& visit(DoABCTag& tag,        TArg& arg) = 0;
        //virtual TResult& visit(DoABCDefineTag& tag,  TArg& arg) = 0;
#pragma endregion

#pragma region Shape tags
        virtual TResult& visit(shape_tags::DefineShapeTag& tag, TArg& arg) = 0;
        virtual TResult& visit(shape_tags::DefineShape2Tag& tag, TArg& arg) = 0;
        virtual TResult& visit(shape_tags::DefineShape3Tag& tag, TArg& arg) = 0;
        virtual TResult& visit(shape_tags::DefineShape4Tag& tag, TArg& arg) = 0;
#pragma endregion

#pragma region Bitmap tags
        //		virtual TResult& visit(DefineBitsTag& tag,          TArg& arg) = 0;
        //		virtual TResult& visit(JPEGTablesTag& tag,          TArg& arg) = 0;
        //		virtual TResult& visit(DefineBitsJPEG2Tag& tag,     TArg& arg) = 0;
        //		virtual TResult& visit(DefineBitsJPEG3Tag& tag,     TArg& arg) = 0;
        //		virtual TResult& visit(DefineBitsLosslessTag& tag,  TArg& arg) = 0;
        //		virtual TResult& visit(DefineBitsLossless2Tag& tag, TArg& arg) = 0;
        //		virtual TResult& visit(DefineBitsJPEG4Tag& tag,     TArg& arg) = 0;
#pragma endregion
        //
#pragma region Shape morphing tags
        //		virtual TResult& visit(DefineMorphShapeTag& tag,    TArg& arg) = 0;
        //		virtual TResult& visit(DefineMorphShape2Tag& tag,   TArg& arg) = 0;
#pragma endregion
        //
        //#pragma region Font tags
        //		virtual TResult& visit(DefineFontTag& tag,           TArg& arg) = 0;
        //		virtual TResult& visit(DefineFontInfoTag& tag,       TArg& arg) = 0;
        //		virtual TResult& visit(DefineFontInfo2Tag& tag,      TArg& arg) = 0;
        //		virtual TResult& visit(DefineFont2Tag& tag,          TArg& arg) = 0;
        //		virtual TResult& visit(DefineFont3Tag& tag,          TArg& arg) = 0;
        //		virtual TResult& visit(DefineFontAlignZonesTag& tag, TArg& arg) = 0;
        //		virtual TResult& visit(DefineFontNameTag& tag,       TArg& arg) = 0;
        //#pragma endregion
        //
        //#pragma region Text tags
        //		virtual TResult& visit(DefineTextTag& tag,      TArg& arg) = 0;
        //		virtual TResult& visit(DefineText2Tag& tag,     TArg& arg) = 0;
        //		virtual TResult& visit(DefineEditTextTag& tag,  TArg& arg) = 0;
        //		virtual TResult& visit(CSMTextSettingsTag& tag, TArg& arg) = 0;
        //		virtual TResult& visit(DefineFont4Tag& tag,     TArg& arg) = 0;
        //#pragma endregion
        //
        //#pragma region Sound tags
        //		virtual TResult& visit(DefineSoundTag& tag,      TArg& arg) = 0;
        //		virtual TResult& visit(StartSoundTag& tag,       TArg& arg) = 0;
        //		virtual TResult& visit(StartSound2Tag& tag,      TArg& arg) = 0;
        //		virtual TResult& visit(SoundStreamHeadTag& tag,  TArg& arg) = 0;
        //		virtual TResult& visit(SoundStreamHead2Tag& tag, TArg& arg) = 0;
        //		virtual TResult& visit(SoundStreamBlockTag& tag, TArg& arg) = 0;
        //#pragma endregion
        //
        //#pragma region Button tags
        //		virtual TResult& visit(DefineButtonTag& tag,       TArg& arg) = 0;
        //		virtual TResult& visit(DefineButton2Tag& tag,      TArg& arg) = 0;
        //		virtual TResult& visit(DefineButtonCxformTag& tag, TArg& arg) = 0;
        //		virtual TResult& visit(DefineButtonSoundTag& tag,  TArg& arg) = 0;
        //#pragma endregion

#pragma region Sprites and movie clips
        virtual TResult& visit(DefineSpriteTag& tag, TArg& arg) = 0;
#pragma endregion

        //#pragma region Video tags
        //		virtual TResult& visit(DefineVideoStreamTag& tag, TArg& arg) = 0;
        //		virtual TResult& visit(VideoFrameTag& tag,        TArg& arg) = 0;
        //#pragma endregion
        //
        //		virtual TResult& visit(DefineBinaryDataTag& tag, TArg& arg) = 0;
        //		virtual TResult& visit(DebugIDTag& tag,          TArg& arg) = 0;
        //		virtual TResult& visit(ProductInfoTag& tag,      TArg& arg) = 0;
        virtual TResult& visit(UnknownTag& tag, TArg& arg) = 0;
    };
}
