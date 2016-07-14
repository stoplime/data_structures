#include <iostream>
#include "employee.h"
#include <cassert>

using namespace employee_space;

int main(int argc, char ** argv)
{
	employee e1 ("Joe", 1, 16.70);
	assert(e1.get_name() == "Joe");
	assert(e1.get_id() == 1);
	assert(e1.get_salary() == 16.70);
	employee e2 ("Sam", 1, 10.0);
	assert(e2.yearly_salary() == 10*40*52);
	e2.calculate_biweekly(42.5);
	assert(e2.get_biweekly() == 400+2.5*15);
	std::cout << "All correct" << std::endl;
	return 0;
}

