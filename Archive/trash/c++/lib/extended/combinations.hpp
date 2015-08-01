#include <iterator>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
template <typename InputIterator, typename OutputIterator> 
OutputIterator __combinations(InputIterator begin, InputIterator end,
				int deep, int index, OutputIterator out) {
	if (deep <= index) {
		*out = " ";
		++out;
		return out;
	}
	std::vector<std::string> results(std::pow(end-begin, deep - index));
	auto out2 = __combinations(begin, end, deep, index + 1, results.begin());
	for (auto it1 = begin; it1 < end; it1++) {
		for(auto it2 = results.begin(); it2 < out2; it2++) {
			*out = std::string(*it1) + std::string(*it2);
			out++;
		}
	}
	return out;
}

template <typename InputIterator, typename OutputIterator> 
OutputIterator combinations(InputIterator begin, InputIterator end,
				int deep, OutputIterator out) {
	return __combinations(begin, end, deep, 0, out);
}
