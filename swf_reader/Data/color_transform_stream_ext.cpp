/**
 * @file    color_transform_stream_ext.cpp
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */
#include "color_transform_stream_ext.h"

#include "cpp_base_type.h"
namespace swf_reader::data {
    ColorTransformRGB ColorTransformStreamExt::read_color_transform_rgb(ISwfStreamReader& reader)
    {
        ColorTransformRGB transform;
        const bool has_add_terms = reader.read_bit();
        const bool has_mult_terms = reader.read_bit();
        const u32 bits = reader.read_ub(4);

        if (has_mult_terms)
        {
            transform.red_mult_term = static_cast<i16>(reader.read_sb(bits));
            transform.green_mult_term = static_cast<i16>(reader.read_sb(bits));
            transform.blue_mult_term = static_cast<i16>(reader.read_sb(bits));
            transform.has_mult_terms = true;
        }
        else
        {
            transform.red_mult_term = 0;
            transform.green_mult_term = 0;
            transform.blue_mult_term = 0;
            transform.has_mult_terms = false;
        }

        if (has_add_terms)
        {
            transform.red_add_term = static_cast<i16>(reader.read_sb(bits));
            transform.green_add_term = static_cast<i16>(reader.read_sb(bits));
            transform.blue_add_term = static_cast<i16>(reader.read_sb(bits));
            transform.has_add_terms = true;
        }
        else
        {
            transform.red_add_term = 0;
            transform.green_add_term = 0;
            transform.blue_add_term = 0;
            transform.has_add_terms = false;
        }

        reader.align_to_byte();
        return transform;
    }

    ColorTransformRGBA ColorTransformStreamExt::read_color_transform_rgba(ISwfStreamReader& reader)
    {
        ColorTransformRGBA transform;
        const bool has_add_terms = reader.read_bit();
        const bool has_mult_terms = reader.read_bit();
        const u32 bits = reader.read_ub(4);

        if (has_mult_terms)
        {
            transform.red_mult_term = static_cast<i16>(reader.read_sb(bits));
            transform.green_mult_term = static_cast<i16>(reader.read_sb(bits));
            transform.blue_mult_term = static_cast<i16>(reader.read_sb(bits));
            transform.alpha_mult_term = static_cast<i16>(reader.read_sb(bits));
            transform.has_mult_terms = true;
        }
        else
        {
            transform.red_mult_term = 0;
            transform.green_mult_term = 0;
            transform.blue_mult_term = 0;
            transform.alpha_mult_term = 0;
            transform.has_mult_terms = false;
        }

        if (has_add_terms)
        {
            transform.red_add_term = static_cast<i16>(reader.read_sb(bits));
            transform.green_add_term = static_cast<i16>(reader.read_sb(bits));
            transform.blue_add_term = static_cast<i16>(reader.read_sb(bits));
            transform.alpha_add_term = static_cast<i16>(reader.read_sb(bits));
            transform.has_add_terms = true;
        }
        else
        {
            transform.red_add_term = 0;
            transform.green_add_term = 0;
            transform.blue_add_term = 0;
            transform.alpha_add_term = 0;
            transform.has_add_terms = false;
        }

        reader.align_to_byte();
        return transform;
    }
}