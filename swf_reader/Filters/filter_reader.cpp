#include "filter_reader.h"
#include "i_swf_stream_reader.h"
#include "drop_shadow_filter.h"
#include "blur_filter.h"
#include "glow_filter.h"
#include "bevel_filter.h"
#include "gradient_glow_filter.h"
#include "convolution_filter.h"
#include "color_matrix_filter.h"
#include "gradient_bevel_filter.h"
#include "Data/color_stream_ext.h"

namespace swf_reader::filters
{
    Box<BaseFilter> FilterReader::read(ISwfStreamReader& reader)
    {
        FilterType type = static_cast<FilterType>(reader.read_byte());
        Box<BaseFilter> filter = factory_.create(type);
        if (filter != nullptr)
            filter->accept_visitor(*this, reader);
        return filter;
    }
    BaseFilter& FilterReader::visit(DropShadowFilter& filter, ISwfStreamReader& reader)
    {
        filter.color = data::ColorStreamExt::read_rgba(reader);
        filter.blur_x = reader.read_fixed();
        filter.blur_y = reader.read_fixed();
        filter.angle = reader.read_fixed();
        filter.distance = reader.read_fixed();
        filter.strength = reader.read_fixed8();
        filter.inner_shadow = reader.read_bit();
        filter.knockout = reader.read_bit();
        filter.composite_source = reader.read_bit();
        filter.passes = static_cast<u8>(reader.read_ub(5));
        return filter;
    }
    BaseFilter& FilterReader::visit(BlurFilter& filter, ISwfStreamReader& reader)
    {
        filter.blur_x = reader.read_fixed();
        filter.blur_y = reader.read_fixed();
        filter.passes = static_cast<u8>(reader.read_ub(5));
        filter.reserved = static_cast<u8>(reader.read_ub(3));
        return filter;
    }

    BaseFilter& FilterReader::visit(GlowFilter& filter, ISwfStreamReader& reader)
    {
        filter.color = data::ColorStreamExt::read_rgba(reader);
        filter.blur_x = reader.read_fixed();
        filter.blur_y = reader.read_fixed();
        filter.strength = reader.read_fixed8();
        filter.inner_glow = reader.read_bit();
        filter.knockout = reader.read_bit();
        filter.composite_source = reader.read_bit();
        filter.passes = static_cast<u8>(reader.read_ub(5));
        return filter;
    }

    BaseFilter& FilterReader::visit(BevelFilter& filter, ISwfStreamReader& reader)
    {
        filter.shadow_color = data::ColorStreamExt::read_rgba(reader);
        filter.highlight_color = data::ColorStreamExt::read_rgba(reader);

        filter.blur_x = reader.read_fixed();
        filter.blur_y = reader.read_fixed();
        filter.angle = reader.read_fixed();
        filter.distance = reader.read_fixed();
        filter.strength = reader.read_fixed8();
        filter.inner_shadow = reader.read_bit();
        filter.knockout = reader.read_bit();
        filter.composite_source = reader.read_bit();
        filter.on_top = reader.read_bit();
        filter.passes = static_cast<u8>(reader.read_ub(4));
        return filter;
    }
    BaseFilter& FilterReader::visit(GradientGlowFilter& filter, ISwfStreamReader& reader)
    {
        u8 count = reader.read_byte();
        for (i32 i = 0; i < count; i++)
        {
            Box<gradients::GradientRecordRgba> gradient_record = boxed<gradients::GradientRecordRgba>();
            gradient_record->color = data::ColorStreamExt::read_rgba(reader);
            filter.gradient_records.push_back(std::move(gradient_record));
        }
        for (i32 i = 0; i < count; i++)
        {
            filter.gradient_records[i]->ratio = reader.read_byte();
        }
        filter.blur_x = reader.read_fixed();
        filter.blur_y = reader.read_fixed();
        filter.angle = reader.read_fixed();
        filter.distance = reader.read_fixed();
        filter.strength = reader.read_fixed8();
        filter.inner_shadow = reader.read_bit();
        filter.knockout = reader.read_bit();
        filter.composite_source = reader.read_bit();
        filter.on_top = reader.read_bit();
        filter.passes = static_cast<u8>(reader.read_ub(4));
        return filter;
    }
    BaseFilter& FilterReader::visit(ConvolutionFilter& filter, ISwfStreamReader& reader)
    {
        u8 matrix_x = reader.read_byte();
        u8 matrix_y = reader.read_byte();
        filter.matrix_x = matrix_x;
        filter.matrix_y = matrix_y;
        filter.divider = reader.read_float();
        filter.bias = reader.read_float();
        u32 size = matrix_x * matrix_y;
        filter.matrix.reserve(size);
        for (u32 i = 0; i < size; i++)
        {
            filter.matrix.push_back(reader.read_float());
        }
        filter.default_color = data::ColorStreamExt::read_rgba(reader);
        filter.reserved = static_cast<u8>(reader.read_ub(6));
        filter.clamp = reader.read_bit();
        filter.preserve_alpha = reader.read_bit();
        return filter;
    }
    BaseFilter& FilterReader::visit(ColorMatrixFilter& filter, ISwfStreamReader& reader)
    {
        filter.r[0] = reader.read_float();
        filter.r[1] = reader.read_float();
        filter.r[2] = reader.read_float();
        filter.r[3] = reader.read_float();
        filter.r[4] = reader.read_float();

        filter.g[0] = reader.read_float();
        filter.g[1] = reader.read_float();
        filter.g[2] = reader.read_float();
        filter.g[3] = reader.read_float();
        filter.g[4] = reader.read_float();

        filter.b[0] = reader.read_float();
        filter.b[1] = reader.read_float();
        filter.b[2] = reader.read_float();
        filter.b[3] = reader.read_float();
        filter.b[4] = reader.read_float();

        filter.a[0] = reader.read_float();
        filter.a[1] = reader.read_float();
        filter.a[2] = reader.read_float();
        filter.a[3] = reader.read_float();
        filter.a[4] = reader.read_float();

        return filter;
    }
    BaseFilter& FilterReader::visit(GradientBevelFilter& filter, ISwfStreamReader& reader)
    {
        u8 count = reader.read_byte();
        for (i32 i = 0; i < count; i++)
        {
            Box<gradients::GradientRecordRgba> gradient_record = boxed<gradients::GradientRecordRgba>();
            gradient_record->color = data::ColorStreamExt::read_rgba(reader);
            filter.gradient_records.push_back(std::move(gradient_record));
        }
        for (i32 i = 0; i < count; i++)
        {
            filter.gradient_records[i]->ratio = reader.read_byte();
        }
        filter.blur_x = reader.read_fixed();
        filter.blur_y = reader.read_fixed();
        filter.angle = reader.read_fixed();
        filter.distance = reader.read_fixed();
        filter.strength = reader.read_fixed8();
        filter.inner_shadow = reader.read_bit();
        filter.knockout = reader.read_bit();
        filter.composite_source = reader.read_bit();
        filter.on_top = reader.read_bit();
        filter.passes = static_cast<u8>(reader.read_ub(4));
        return filter;
    }
}