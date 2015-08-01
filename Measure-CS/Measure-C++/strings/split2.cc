#include <string>
#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> split_1(const std::string &str, char delimiter) {
	std::stringstream buffer(str);
	std::vector<std::string> result;
	std::string tmp;
	while(std::getline(buffer, tmp, delimiter)) {
		result.push_back(tmp);
	}
	return result;
}
int main() {
	for(int i = 0; i < 100000; i++)
		auto res = split_1("hello world d", ' ');
}
