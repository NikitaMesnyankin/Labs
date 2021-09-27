#include "basic_fraction.h"
#include <cstdlib>
#include <iostream>

int main() {
	mesnyankin::BasicFraction o1 = mesnyankin::BasicFraction(1, 1);
	mesnyankin::BasicFraction o2 = mesnyankin::BasicFraction(1, 1);
	o1 = o1 + 'h';
	std::cout << o1.getNumerator() << " " << o1.getDenominator() << std::endl;
	o1 += o2;
	std::cout << o1.getNumerator() << " " << o1.getDenominator() << std::endl;
	system("pause");
	return 0;
}