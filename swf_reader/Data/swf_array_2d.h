#pragma once
#include "cpp_base_type.h"
#include <memory>
#include <cassert>

namespace swf_reader::data
{
    template<typename T>
    class SwfArray2D
    {
    private:
        Box<T[]> data_;
        u16 rows_ = 0;
        u16 cols_ = 0;

    public:
        // 构造和析构
        SwfArray2D() = default;

        SwfArray2D(u16 rows, u16 cols)
            : data_{ boxed<T[]>(rows * cols) }
            , rows_{ rows }
            , cols_{ cols }
        {
        }

        // 移动语义
        SwfArray2D(SwfArray2D&&) = default;
        SwfArray2D& operator=(SwfArray2D&&) = default;

        // 禁止拷贝
        SwfArray2D(const SwfArray2D&) = delete;
        SwfArray2D& operator=(const SwfArray2D&) = delete;

        // 重置大小（不保留数据）
        void resize(u16 rows, u16 cols)
        {
            data_ = boxed<T[]>(rows * cols);
            rows_ = rows;
            cols_ = cols;
        }

        // 重置大小并保留数据（如果可能）
        void resize_preserve(u16 new_rows, u16 new_cols)
        {
            if (new_rows == rows_ && new_cols == cols_) return;

            Box<T[]> new_data = boxed<T[]>(new_rows * new_cols);

            // 拷贝重叠部分
            u16 min_rows = std::min(rows_, new_rows);
            u16 min_cols = std::min(cols_, new_cols);

            for (u16 i = 0; i < min_rows; ++i)
                for (u16 j = 0; j < min_cols; ++j)
                    new_data[i * new_cols + j] = data_[i * cols_ + j];

            data_ = std::move(new_data);
            rows_ = new_rows;
            cols_ = new_cols;
        }

        // 快速访问 - 无边界检查
        T& operator()(u16 row, u16 col) noexcept
        {
            return data_[row * cols_ + col];
        }

        T& operator[](u32 index) noexcept
        {
            return data_[index];
        }

        const T& operator()(u16 row, u16 col) const noexcept
        {
            return data_[row * cols_ + col];
        }

        const T& operator[](u32 index) const noexcept
        {
            return data_[index];
        }

        // 安全访问 - 带边界检查
        T& at(u16 row, u16 col)
        {
            assert(row < rows_ && col < cols_);
            return data_[row * cols_ + col];
        }

        T& at(u32 index)
        {
            assert(index < size());
            return data_[index];
        }

        const T& at(u16 row, u16 col) const
        {
            assert(row < rows_ && col < cols_);
            return data_[row * cols_ + col];
        }

        const T& at(u32 index) const
        {
            assert(index < size());
            return data_[index];
        }

        // 原始数据访问
        T* data() noexcept
        {
            return data_.get();
        }
        const T* data() const noexcept
        {
            return data_.get();
        }

        T* row_data(u16 row) noexcept
        {
            return data() + row * cols_;
        }

        const T* row_data(u16 row) const noexcept
        {
            return data() + row * cols_;
        }

        // 尺寸信息
        u16 rows() const noexcept
        {
            return rows_;
        }
        u16 cols() const noexcept
        {
            return cols_;
        }
        u32 size() const noexcept
        {
            return rows_ * cols_;
        }
        bool empty() const noexcept
        {
            return size() == 0;
        }

        // 内存信息
        u32 memory_usage() const noexcept
        {
            return size() * sizeof(T) + sizeof(*this);
        }

        // 填充操作
        void fill(const T& value) noexcept
        {
            for (u32 i = 0; i < size(); ++i) data_[i] = value;
        }

        // 清零（对于数值类型）
        void zero() noexcept
        {
            if constexpr (std::is_arithmetic_v<T>) std::memset(data(), 0, size() * sizeof(T));
            else fill(T{});
        }

        // 交换操作
        void swap(SwfArray2D& other) noexcept
        {
            data_.swap(other.data_);
            std::swap(rows_, other.rows_);
            std::swap(cols_, other.cols_);
        }
    };
} // namespace swf_reader
