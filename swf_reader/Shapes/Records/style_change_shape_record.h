/**
 * @file    style_change_shape_record.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#pragma once

#include "i_shape_record.h"
#include "style_change_record_flag.h"
namespace swf_reader::shapes::records
{
    class StyleChangeShapeRecord : public virtual IShapeRecord
    {
    public:

        StyleChangeRecordFlags flags;
        u32 fillstyle0;
        u32 fillstyle1;
        u32 linestyle;
        i32 move_delta_x;
        i32 move_delta_y;

        inline ShapeRecordType get_type() const override { return ShapeRecordType::StyleChangeRecord; }

        // 在C#中，accept_visitor函数在IShapeRecord接口中声明，所以需要在StyleChangeShapeRecord实现
        // 但C++中没有接口，此函数直接继承于IShapeRecord，所以不需要在此处实现
        //virtual IShapeRecord& accept_visitor(IShapeRecordVisitor<ISwfStreamReader, IShapeRecord&>& visitor, ISwfStreamReader& arg) = 0;
    };
}
