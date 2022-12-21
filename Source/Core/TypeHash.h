/// @author M. A. Serebrennikov
#pragma once

#include <typeinfo>
#include <unordered_map>
#include <unordered_set>

namespace sp {
    template<class T>
    using TypeHash = std::unordered_map<const std::type_info*, T>;
    using TypeSet = std::unordered_set<const std::type_info*>;
} // namespace sp
