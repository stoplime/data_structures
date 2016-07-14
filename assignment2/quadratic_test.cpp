/************************ Steffen Lim *****************************/
/************************** cs3304 ********************************/
//compile: g++ -g -Wall -o quad quadratic_test.cpp quadratic.cpp
#include "quadratic.h"
#include <iostream>
#include <cassert>
#include <math.h>

using namespace quadratic_namespace;

int main (int argc, char **argv) 
{
	quadratic q1;
	q1.set_coefficients(1,2,4);
	assert(q1.get_coefficient_a() == 1);
	assert(q1.get_coefficient_b() == 2);
	assert(q1.get_coefficient_c() == 4);
	quadratic q2;
	q2.set_coefficients(2,-5,13.75);
	quadratic q3 = q1 + q2;
	assert(q3.get_coefficient_a() == 3);
	assert(q3.get_coefficient_b() == -3);
	assert(q3.get_coefficient_c() == 17.75);
	q2 = 2.0 * q2;
	assert(q2.get_coefficient_a() == 4);
	assert(q2.get_coefficient_b() == -10);
	assert(q2.get_coefficient_c() == 27.5);
	// Test roots
	quadratic q4;
	q4.set_coefficients(0,0,0);
	assert(q4.num_of_roots() == 3);
	assert(q4.low_root() == 0);
	assert(q4.high_root() == 0);
	quadratic q5;
	q5.set_coefficients(0,0,6);
	assert(q5.num_of_roots() == 0);
	//assert(q5.low_root() == 0);// should crash
	quadratic q6;
	q6.set_coefficients(0,-1,1);
	assert(q6.num_of_roots() == 1);
	assert(q6.low_root() == 1);
	assert(q6.high_root() == 1);
	quadratic q7;
	q7.set_coefficients(1,0,4);
	assert(q7.num_of_roots() == 0);
	quadratic q8;
	q8.set_coefficients(1,2,1);
	assert(q8.num_of_roots() == 1);
	assert(q8.low_root() == -1);
	assert(q8.high_root() == -1);
	quadratic q9;
	q9.set_coefficients(1,3,1);
	assert(q9.num_of_roots() == 2);
	assert(q9.low_root() == (-3.0/2)-sqrt(5.0)/2.0);
	assert(q9.high_root() == (-3.0/2)+sqrt(5.0)/2.0);
	
	std::cout << "everything works" << std::endl;
	return 0;
}
