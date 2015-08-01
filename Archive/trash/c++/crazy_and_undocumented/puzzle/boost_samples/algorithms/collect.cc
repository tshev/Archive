#include <boost/range/algorithm/find_if.hpp>
#include <boost/range/istream_range.hpp>
#include <vector>
#include <iterator>
#include <algorithm>
template <typename T>
auto collect(const T &range, size_t count) {
	std::vector<std::value_trait<T>::value_type> vec;
	for(auto &x : range) {
		vec.push_back(x);
	}
	return vec;
}
int main() {
	auto collection = collect(boost::istream_range<int>(std::cin), 10);
	for (auto &x: collection) {
		std::cout << x << std::endl;
	}
}
