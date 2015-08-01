#include "combinations.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
	std::string str = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	std::vector<std::string> letters(52);
	std::copy(str.begin(), str.end(), letters.begin());
	
	std::vector<std::string> results(pow(52, 5));
	auto end = combinations(letters.begin(), letters.end(), 5, results.begin());
	std::cout << end - letters.begin() << std::endl;
	for (auto &x : results) {
		std::cout << x << std::endl;
	}	
}
