#pragma once
#include <cstdint>
#include <memory>
#include <unordered_map>
#include <vector>
#include <optional>

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using f32 = float;
using f64 = double;

using usize = size_t;
using isize = ptrdiff_t;


template<typename T>
using Box = std::unique_ptr<T>;
// std::make_unique
template<typename T, typename... Args>
constexpr Box<T> boxed(Args&&... args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
using Rc = std::shared_ptr<T>;
template<typename T>
using Weak = std::weak_ptr<T>;

template<typename T>
using Vec = std::vector<T>;
template<typename K, typename V>
using Map = std::unordered_map<K, V>;
template<typename T>
using Option = std::optional<T>;
