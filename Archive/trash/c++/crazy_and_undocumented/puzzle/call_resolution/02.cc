#include <stdio.h>

namespace foo {
	namespace bar {
		class A {};
	}
	using namespace bar;
	void f(A &x) {}
}
int main() {
	using foo::A;
	A x;
	foo::f(x);
}
