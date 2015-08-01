#include <cstdint>
namespace ext { 
typedef uint64_t size_t;
template <typename ForwardIterator, typename T>
void iota(ForwardIterator begin, ForwardIterator end, T value, const T &step) {
	for (auto it = begin; it != end; it++) {
		*it = value;
		value += step;
	}
}
template <typename ForwardIterator, typename T> 
void iota(ForwardIterator begin, size_t size, T value, const T &step) {
	for (size_t i = 0; i < size; i++) {
		*begin = value;
		value += step;
		++begin;
	}
}
}
