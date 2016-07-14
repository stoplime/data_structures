#include <iostream>
#include <cassert>
#include "employee.h"
#include <string>

namespace employee_space
{
	employee::employee(std::string n, int id, double _salary)
	{
		assert(_salary > 0);
		assert(id > 0);
		name = n;
		id_num = id;
		salary = _salary;
	}
	
	double employee::yearly_salary()
	{
		return 52*40*salary;
	}
	
	void employee::increase_salary(double percentage)
	{
		salary *= 1+(percentage/100);
	}
	
	void employee::calculate_biweekly(double time)
	{
		if (time > 40)
		{
			biweekly_check = 40*salary + (time-40)*1.5*salary;
		}
		else
		{
			biweekly_check = time*salary;
		}
		
	}
	
	std::string employee::get_name() const
	{
		return name;
	}
	
	int employee::get_id() const
	{
		return id_num;
	}
	
	double employee::get_salary() const
	{
		return salary;
	}
	
	double employee::get_biweekly() const
	{
		return biweekly_check;
	}

}
