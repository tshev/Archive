#include <iostream>
int calc(int v, int &x) {
	 int tmp = x + 1;
	x+= v;
	return tmp + v;
}
int main() {
	int v = 3;
	for(int i = 0; i < 1000; i++) {
	int x = 4;
	auto y = calc(v, x);
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	}
}
