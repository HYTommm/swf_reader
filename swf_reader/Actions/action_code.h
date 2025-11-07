/**
 * @file    action_code.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "primitive_types.h"

namespace swf_reader::actions
{
    /**
     * 表示 ActionScript 2.0 的动作代码
     */
    enum class ActionCode : u8
    {
        End = 0x00,

        /// <summary>
        /// ActionNextFrame 指示 Flash Player 转到当前文件中的下一帧
        /// </summary>
        NextFrame = 0x04,

        /// <summary>
        /// ActionPreviousFrame 指示 Flash Player 转到当前文件的上一帧
        /// </summary>
        PreviousFrame = 0x05,

        /// <summary>
        /// ActionPlay 指示 Flash Player 从当前帧开始播放
        /// </summary>
        Play = 0x06,

        /// <summary>
        /// ActionStop 指示 Flash Player 在当前帧停止播放文件
        /// </summary>
        Stop = 0x07,

        /// <summary>
        /// ActionToggleQuality 在高质量和低质量显示之间切换
        /// </summary>
        ToggleQuality = 0x08,

        /// <summary>
        /// ActionStopSounds 指示 Flash Player 停止播放所有声音
        /// </summary>
        StopSounds = 0x09,

        /// <summary>
        /// ActionAdd 将两个数字相加并将结果推回堆栈
        /// </summary>
        Add = 0x0a,

        /// <summary>
        /// ActionSubtract 将两个数字相减并将结果推回堆栈
        /// </summary>
        Subtract = 0x0b,

        /// <summary>
        /// ActionMultiply 将两个数字相乘并将结果推回堆栈
        /// </summary>
        Multiply = 0x0c,

        /// <summary>
        /// ActionDivide 将两个数字相除并将结果推回堆栈
        /// </summary>
        Divide = 0x0d,

        /// <summary>
        /// ActionEquals 测试两个数字是否相等
        /// </summary>
        Equals = 0x0e,

        /// <summary>
        /// ActionLess 测试一个数字是否小于另一个数字
        /// </summary>
        Less = 0x0f,

        /// <summary>
        /// ActionAnd 对两个数字执行逻辑 AND 运算
        /// </summary>
        And = 0x10,

        /// <summary>
        /// ActionOr 对两个数字执行逻辑 OR 运算
        /// </summary>
        Or = 0x11,

        /// <summary>
        /// ActionNot 对数字执行逻辑 NOT 运算
        /// </summary>
        Not = 0x12,

        /// <summary>
        /// ActionStringEquals 测试两个字符串是否相等
        /// </summary>
        StringEquals = 0x13,

        /// <summary>
        /// ActionStringLength 计算字符串的长度
        /// </summary>
        StringLength = 0x14,

        /// <summary>
        /// ActionStringExtract 从字符串中提取子字符串
        /// </summary>
        StringExtract = 0x15,

        /// <summary>
        /// ActionPop 从堆栈中弹出一个值并丢弃它
        /// </summary>
        Pop = 0x17,

        /// <summary>
        /// ActionToInteger 将值转换为整数
        /// </summary>
        ToInteger = 0x18,

        /// <summary>
        /// ActionGetVariable 获取变量的值
        /// </summary>
        GetVariable = 0x1c,

        /// <summary>
        /// ActionSetVariable 设置变量
        /// </summary>
        SetVariable = 0x1d,

        /// <summary>
        /// ActionSetTarget2 设置当前上下文，基于堆栈
        /// </summary>
        SetTarget2 = 0x20,

        /// <summary>
        /// ActionStringAdd 连接两个字符串
        /// </summary>
        StringAdd = 0x21,

        /// <summary>
        /// ActionGetProperty 获取文件属性
        /// </summary>
        GetProperty = 0x22,

        /// <summary>
        /// ActionSetProperty 设置文件属性
        /// </summary>
        SetProperty = 0x23,

        /// <summary>
        /// ActionCloneSprite 克隆精灵
        /// </summary>
        CloneSprite = 0x24,

        /// <summary>
        /// ActionRemoveSprite 移除克隆精灵
        /// </summary>
        RemoveSprite = 0x25,

        /// <summary>
        /// ActionTrace 发送调试输出字符串
        /// </summary>
        Trace = 0x26,

        /// <summary>
        /// ActionStartDrag 开始拖动影片剪辑
        /// </summary>
        StartDrag = 0x27,

        /// <summary>
        /// ActionEndDrag 结束当前正在进行的拖动操作（如果有）
        /// </summary>
        EndDrag = 0x28,

        Throw = 0x2a,
        CastOp = 0x2b,
        ImplementsOp = 0x2c,

        /// <summary>
        /// ActionStringLess 测试一个字符串是否小于另一个字符串
        /// </summary>
        StringLess = 0x29,

        /// <summary>
        /// ActionRandomNumber 计算随机数
        /// </summary>
        RandomNumber = 0x30,

        /// <summary>
        /// ActionMBStringLength 计算字符串的长度，支持多字节字符
        /// </summary>
        MBStringLength = 0x31,

        /// <summary>
        /// ActionCharToAscii 将字符代码转换为 ASCII
        /// </summary>
        CharToAscii = 0x32,

        /// <summary>
        /// ActionAsciiToChar 将值转换为 ASCII 字符代码
        /// </summary>
        AsciiToChar = 0x33,

        /// <summary>
        /// ActionGetTime 报告自 Adobe Flash Player 启动以来的毫秒数
        /// </summary>
        GetTime = 0x34,

        /// <summary>
        /// ActionMBStringExtract 从字符串中提取子字符串，支持多字节字符
        /// </summary>
        MBStringExtract = 0x35,

        /// <summary>
        /// ActionMBCharToAscii 将字符代码转换为 ASCII，支持多字节字符
        /// </summary>
        MBCharToAscii = 0x36,

        /// <summary>
        /// ActionMBAsciiToChar 将 ASCII 转换为字符代码，支持多字节字符
        /// </summary>
        MBAsciiToChar = 0x37,

        Delete = 0x3a,
        Delete2 = 0x3b,
        DefineLocal = 0x3c,
        CallFunction = 0x3d,

        /// <summary>
        /// ActionReturn 强制将返回项从堆栈中弹出并返回。如果不适合返回，则丢弃返回项
        /// </summary>
        Return = 0x3e,
        Modulo = 0x3f,
        NewObject = 0x40,
        DefineLocal2 = 0x41,
        InitArray = 0x42,
        InitObject = 0x43,
        TypeOf = 0x44,
        TargetPath = 0x45,
        Enumerate = 0x46,
        Add2 = 0x47,
        Less2 = 0x48,
        Equals2 = 0x49,
        ToNumber = 0x4a,
        ToString = 0x4b,
        PushDuplicate = 0x4c,
        StackSwap = 0x4d,
        GetMember = 0x4e,

        /// <summary>
        /// ActionSetMember 设置对象的属性。如果该属性尚不存在，则创建它。属性中的任何现有值都会被覆盖
        /// </summary>
        SetMember = 0x4f,
        Increment = 0x50,
        Decrement = 0x51,
        CallMethod = 0x52,
        NewMethod = 0x53,
        InstanceOf = 0x54,
        Enumerate2 = 0x55,
        BitAnd = 0x60,
        BitOr = 0x61,
        BitXor = 0x62,
        BitLShift = 0x63,
        BitRShift = 0x64,
        BitURShift = 0x65,
        StrictEquals = 0x66,
        Greater = 0x67,
        StringGreater = 0x68,
        Extends = 0x69,

        /// <summary>
        /// ActionGotoFrame 指示 Flash Player 转到当前文件中的指定帧
        /// </summary>
        GotoFrame = 0x81,

        /// <summary>
        /// ActionGetURL 指示 Flash Player 获取 UrlString 指定的 URL。URL 可以是任何类型，包括 HTML 文件、图像或其他 SWF 文件。如果文件在浏览器中播放，URL 将显示在 TargetString 指定的框架中。特殊目标名称 "_level0" 和 "_level1" 分别用于将其他 SWF 文件加载到级别 0 和 1 中
        /// </summary>
        GetURL = 0x83,
        StoreRegister = 0x87,

        /// <summary>
        /// ActionConstantPool 创建一个新的常量池，如果已存在常量池，则替换旧的常量池
        /// </summary>
        ConstantPool = 0x88,

        /// <summary>
        /// ActionWaitForFrame 指示 Flash Player 等待直到指定的帧；否则跳过指定数量的动作
        /// </summary>
        WaitForFrame = 0x8a,

        /// <summary>
        /// ActionSetTarget 指示 Flash Player 更改后续动作的上下文，使它们应用于命名对象（TargetName）而不是当前文件
        /// </summary>
        SetTarget = 0x8b,

        /// <summary>
        /// ActionGoToLabel 指示 Flash Player 转到与指定标签关联的帧。您可以使用 FrameLabel 标签将标签附加到帧
        /// </summary>
        GoToLabel = 0x8c,

        /// <summary>
        /// ActionWaitForFrame2 等待帧加载，基于堆栈
        /// </summary>
        WaitForFrame2 = 0x8d,
        DefineFunction2 = 0x8e,
        Try = 0x8f,
        With = 0x94,

        /// <summary>
        /// ActionPush 将一个或多个值推送到堆栈
        /// </summary>
        Push = 0x96,

        /// <summary>
        /// ActionJump 创建无条件分支
        /// </summary>
        Jump = 0x99,

        /// <summary>
        /// ActionGetURL2 获取 URL，基于堆栈
        /// </summary>
        GetURL2 = 0x9a,

        /// <summary>
        /// ActionDefineFunction 定义具有给定名称和主体大小的函数
        /// </summary>
        DefineFunction = 0x9b,

        /// <summary>
        /// ActionIf 创建条件测试和分支
        /// </summary>
        If = 0x9d,

        /// <summary>
        /// ActionCall 调用子程序
        /// </summary>
        Call = 0x9e,

        /// <summary>
        /// ActionGotoFrame2 转到帧，基于堆栈
        /// </summary>
        GotoFrame2 = 0x9f
    };
}