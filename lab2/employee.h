#ifndef EMPLOYEE_CLASS_H_
#define EMPLOYEE_CLASS_H_

#include <iostream>
#include <string>
namespace employee_space
{
	// class invariant: rational number is in lowest terms
	// with a positive denominator
	class employee
	{
	public:
		employee(std::string n, int id, double _salary);
		std::string get_name() const;
		int get_id() const;
		double get_salary() const;
		double get_biweekly() const;
		double yearly_salary();
		void increase_salary(double percentage);
		void calculate_biweekly(double time);
	private:
		std::string name;
		int id_num;
		double salary;
		//Post: salary based on hourly wage
		double biweekly_check;
	};

}

#endif
