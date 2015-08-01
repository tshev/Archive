#include <iostream>
using namespace std;
template<int x> struct A {
	enum { value = x*A<x-1>::value };
};
template<> struct A<1> {
	enum { value = 1};
};
int main() {
	A<10> v;
	cout << v.value << endl;
}
