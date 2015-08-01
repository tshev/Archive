#include "fraction.hpp"
#include <iostream>
int main() {
	ext::fraction<int> one_thrird(1, 3);
	ext::fraction<int> two_fiveth(2, 5);

	std::cout << "1/3 + 2/5 =\t" << one_thrird + two_fiveth << std::endl;
	std::cout << "1/3 - 2/5 + 2/5 =\t" << one_thrird - two_fiveth + two_fiveth  << std::endl;
	std::cout << "1/3 * 2/5 =\t" << one_thrird * two_fiveth << std::endl;
	std::cout << "1/3 / 2/5 =\t" << one_thrird / two_fiveth << std::endl;
	std::cout << "0.33 + 2/5 =\t" << 0.33 + two_fiveth << std::endl;
	return 0;
}
