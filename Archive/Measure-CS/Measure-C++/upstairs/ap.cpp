#include <iostream>
void foo(int &x) {
	int v = std::move(x);
}
int main() {
	int y = 5;
	foo(y);
	std::cout << y << std::endl;
}
