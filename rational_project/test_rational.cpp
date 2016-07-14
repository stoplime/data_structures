#include <iostream>
#include "rational_number.h"
#include <cassert>

using namespace rational;

int main(int argc, char ** argv)
{
	rational_number r1 (4,5);
	assert(r1.get_numerator() == 4);
	assert(r1.get_denominator() == 5);
	rational_number r2 (2,7);
	rational_number r3 = r1+r2;
	std::cout << r3;
	return 0;
}
