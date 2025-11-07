#pragma once

#include <memory>
#include <optional>
#include <unordered_map>
#include <vector>
#include "primitive_types.h"

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
