#include <iostream>
struct unnamed_lambda
{
  template<typename T, typename U>
    auto operator()(T x, U y) const  {return x + y;}
};
template<class T> void f(T p) {
	std::cout << p(4,4) << std::endl;
}
int sum(int x, int y) {
	return x + y;
}
int main() {
	auto lambda = unnamed_lambda();
	f(sum);
	std::cout << lambda(3, 4) << "\n";
}
