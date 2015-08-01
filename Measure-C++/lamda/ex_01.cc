#include <iostream>
int main() {
	for(int i = 0; i < 1000; i++) {
	int x = 4;
	auto y = [&manipulator = x, x = x+1](int v)->int {
            manipulator += v;
            return x+v;
         }(3);  
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	}
}
