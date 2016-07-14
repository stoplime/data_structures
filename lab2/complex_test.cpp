#include <iostream>
#include "complex.h"
#include <cassert>
#include <math.h>

using namespace complex_numbers;

int main(int argc, char ** argv)
{
	complex c1 (1,2);
	assert(c1.get_real() == 1);
	assert(c1.get_imaginary() == 2);
	complex c2 (4,-5);
	complex c3 = c1+c2;
	complex c4 = c1-c2;
	complex c5 = c1*c2;
	complex c6 = c1/c2;
	double dist = c1.get_modulo();
	assert(c3.get_real() == 5);
	assert(c3.get_imaginary() == -3);
	assert(c4.get_real() == -3);
	assert(c4.get_imaginary() == 7);
	assert(c5.get_real() == 14);
	assert(c5.get_imaginary() == 3);
	assert(c6.get_real() == (-6/41.0));
	assert(c6.get_imaginary() == 13/41.0);
	assert(dist == sqrt(5.0));
	std::cout << "Everything works" << std::endl;
	return 0;
}
