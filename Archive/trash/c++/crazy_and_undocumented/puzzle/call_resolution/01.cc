#include <stdio.h>

namespace foo {
	namespace bar {
		class A {};
		void f(A &x) {}
	}
}
int main() {
	using foo::bar::A;
	A x;
	f(x);
}
