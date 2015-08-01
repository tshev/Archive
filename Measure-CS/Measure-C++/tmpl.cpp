#include <iostream>

template<int... > struct A;
template<int x, int y> struct A<x, y> {
	enum a { z=4};
	A() {
		enum a { z= 4, za = 100};
		a v ;
		a::z = 4;
		//a::z = 2;
		std::cout << "D\n";
	//	std::cout << y;
	}
};
int main() {
	A<3,4> v;
	std::cout << A<4,5>::z << std::endl;
}
