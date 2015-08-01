#include "primes.hpp"
#include <iostream>
int main() {
    gries_misra_t<int> primes(5);
    std::cout << primes(3) << std::endl;
    return 0;
}
