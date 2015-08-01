#include <boost/range/algorithm/find_if.hpp>
#include <vector>
#include <algorithm>
template <typename T>
void f(T x) {
	*x = 10;
}
int main() {
	const std::vector<int> hello = {1, 2, 3, 4, 5};
	//auto ptr_1 = boost::find_if(hello, [](const int &x) { return x == 5; });
	//auto ptr_2 = std::find_if(hello.cbegin(), hello.cend(), [](const int &x) { return x == 5; });
	f(hello.cbegin());
	return 0;
}
