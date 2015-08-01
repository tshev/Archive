// play with even numbers
// print first 10 not even natural numbers
// print first 10 even natural numbers
#include "iota.hpp"
#include <algorithm>
#include <vector>
#include <iostream>
int main() {
	size_t sample_size = 10;
	std::vector<double> numbers(sample_size);
	ext::iota(numbers.begin(), numbers.end(), 1, 2);
	for(auto &x : numbers) {
		std::cout << x << "\t";
	}
	std::cout << std::endl;
	ext::iota(numbers.begin(), numbers.size(), 2, 2);
	for(auto &x : numbers) {
		std::cout << x << "\t";
	}
	std::cout << std::endl;
	return 0;
}
