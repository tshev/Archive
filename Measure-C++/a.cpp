#include  <boost/scope_exit.hpp>
#include <memory>
void f(const std::shared_ptr<int>& p) {
	std::cout << "Called\n";
}
int main() {
	int *p = new int;
	*p = 4;
	BOOST_SCOPE_EXIT_ALL(&) { delete p;};
	//delete p;
	std::cout << *p << std::endl;
	f(std::make_shared<int>x(4))

}
