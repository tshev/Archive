#include <string>
#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> split_1(const std::string &str, char delimiter) {
	std::vector<std::string> result;
	std::string tmp;
	int start = 0;
	int end = start;
	for(auto it = str.begin(); it != str.end(); it++) {
		if(*it == delimiter) {
			result.push_back(str.substr(start, end-start));
			start = end;
		}
		end++;
	}
	return result;
}
int main() {
	for(int i = 0; i < 100000; i++){
		auto res = split_1("hello world d", ' ');
		//std::cout <<  res[0] << std::endl;
	}
}
