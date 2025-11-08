/**
 * @file    filter_reader.h
 *
 * Original C# implementation: Copyright (c) 2018 Sergey Savchuk
 * C++ port: Copyright (c) 2025 HYTomZ
 *
 * Licensed under the MIT License.
 */

#pragma once
#include "i_filter_visitor.h"
#include "filter_factory.h"
#include "base_filter.h"
namespace swf_reader::filters
{
    class FilterReader : public IFilterVisitor<ISwfStreamReader, BaseFilter&>
    {
    private:
        FilterFactory factory_;
    public:
        Box<BaseFilter> read(ISwfStreamReader& reader);

        // Í¨¹ý IFilterVisitor ¼Ì³Ð
        BaseFilter& visit(DropShadowFilter& filter, ISwfStreamReader& reader) override;
        BaseFilter& visit(BlurFilter& filter, ISwfStreamReader& reader) override;
        BaseFilter& visit(GlowFilter& filter, ISwfStreamReader& reader) override;
        BaseFilter& visit(BevelFilter& filter, ISwfStreamReader& reader) override;
        BaseFilter& visit(GradientGlowFilter& filter, ISwfStreamReader& reader) override;
        BaseFilter& visit(ConvolutionFilter& filter, ISwfStreamReader& reader) override;
        BaseFilter& visit(ColorMatrixFilter& filter, ISwfStreamReader& reader) override;
        BaseFilter& visit(GradientBevelFilter& filter, ISwfStreamReader& reader) override;
    };
}