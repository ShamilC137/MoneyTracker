#ifndef APPLICATION_API_DATASTRUCTURES_CONTAINERS_QUEUE_HPP_
#define APPLICATION_API_DATASTRUCTURES_CONTAINERS_QUEUE_HPP_
// current project
#include "../../Memory/VAllocator.hpp"
#include "Deque.hpp"

// STL
#include <queue>

namespace api {
template <class Value, class Container = Deque<Value>>
using Queue = std::queue<Value, Container>;
}
#endif // !APPLICATION_API_DATASTRUCTURES_CONTAINERS_QUEUE_HPP_
