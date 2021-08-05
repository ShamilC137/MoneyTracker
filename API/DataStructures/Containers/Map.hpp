#ifndef APPLICATION_API_DATASTRUCTURES_CONTAINERS_MAP_HPP_
#define APPLICATION_API_DATASTRUCTURES_CONTAINERS_MAP_HPP_
// current project
#include "../../../Config.hpp"
#if ALIGNED_ALLOCATOR_USAGE
#include "../../Memory/AlignedAllocator.hpp"
#endif // !ALIGNED_ALLOCATOR_USAGE

// STL
#include <map>

namespace api {
#if STL_ALLOCATOR_USAGE
template <class Key, class Value, class Compare = std::less<Key>,
          class Allocator = std::allocator<std::pair<const Key, Value>>>
using Map = std::map<Key, Value, Compare, Allocator>;
#elif ALIGNED_ALLOCATOR_USAGE
template <class Key, class Value, class Compare = std::less<Key>,
          class Allocator = AlignedAllocator<std::pair<const Key, Value>>>
using Map = std::map<Key, Value, Compare, Allocator>;
#else
static_assert(false, "Ambigious allocator");
#endif
} // namespace api
#endif // !APPLICATION_API_DATASTRUCTURES_CONTAINERS_MAP_HPP_
