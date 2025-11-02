#pragma once
#include <cstdint>
#include <memory>
#include <optional>
#include <unordered_map>
#include <vector>

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


template<typename StyleChangeShapeRecord_T>
using Box = std::unique_ptr<StyleChangeShapeRecord_T>;
// std::make_unique
template<typename StyleChangeShapeRecord_T, typename... Args>
constexpr Box<StyleChangeShapeRecord_T> boxed(Args&&... args)
{
    return std::make_unique<StyleChangeShapeRecord_T>(std::forward<Args>(args)...);
}

template<typename StyleChangeShapeRecord_T>
using Rc = std::shared_ptr<StyleChangeShapeRecord_T>;
template<typename StyleChangeShapeRecord_T>
using Weak = std::weak_ptr<StyleChangeShapeRecord_T>;

template<typename StyleChangeShapeRecord_T>
using Vec = std::vector<StyleChangeShapeRecord_T>;
template<typename K, typename V>
using Map = std::unordered_map<K, V>;
template<typename StyleChangeShapeRecord_T>
using Option = std::optional<StyleChangeShapeRecord_T>;
