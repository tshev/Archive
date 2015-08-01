#include <iostream>
struct A{};
int main() {
    int bar(int());
    int foo((int()));
    int bar2(((int())));
    std::cout << bar << std::endl;
    std::cout << bar2 << std::endl;
    std::cout << foo << std::endl;
    std::cout << int() << std::endl;
}
