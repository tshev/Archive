#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
int main() {
	int *p = 0x0;
	int x = 11;
	int *px = &x;
	std::cout << px << std::endl;
	std::stringstream str;
	str <<  px;
	char *ps;
	long long v = strtol(str.str().c_str(), &ps, 16);
	p += v/sizeof(int);
	//std::cout << str.str();
	std::cout << *p << std::endl;
	std::cout << &(*(char**)&ps) << std::endl;
}
