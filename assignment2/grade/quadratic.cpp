/************************ Steffen Lim *****************************/
/************************** cs3304 ********************************/
//compile: g++ -g -Wall -o quad quadratic_test.cpp quadratic.cpp
#include "quadratic.h"
#include <cassert>
#include <math.h>

namespace quadratic_namespace
{
	quadratic::quadratic()
	{
		coefficients[0] = 0;
		coefficients[1] = 0;
		coefficients[2] = 0;
	}

	void quadratic::set_coefficients(double a, double b, double c)
	{
		coefficients[0] = a;
		coefficients[1] = b;
		coefficients[2] = c;
	}

	double quadratic::get_coefficient_a() const
	{
		return coefficients[0];
	}
	double quadratic::get_coefficient_b() const
	{
		return coefficients[1];
	}
	double quadratic::get_coefficient_c() const
	{
		return coefficients[2];
	}

	double quadratic::evaluate (double x)
	{
		return (coefficients[0]*x*x)+coefficients[1]*x+coefficients[2];
	}
	
	int quadratic::num_of_roots()
	{
		double a = coefficients[0];
		double b = coefficients[1];
		double c = coefficients[2];
		if (a == 0 && b == 0 && c == 0)
			return 3;
		if (a == 0 && b == 0 && c != 0)
			return 0;
		if (a == 0 && b != 0)
			return 1;
		if (a != 0 && b*b < 4*a*c)
			return 0;
		if (a != 0 && b*b == 4*a*c)
			return 1;
		if (a != 0 && b*b > 4*a*c)
			return 2;
		return 0;
	}
	
	double quadratic::low_root()
	{
		assert(num_of_roots() != 0);
		double a = coefficients[0];
		double b = coefficients[1];
		double c = coefficients[2];
		if (a == 0 && b != 0)
			return -c/b;
		if (a != 0 && b*b == 4*a*c)
			return -b/(2*a);
		if (a != 0 && b*b > 4*a*c)
			return (-1*b-sqrt(b*b-4*a*c))/(2*a);
		return 0;
	}
	double quadratic::high_root()
	{
		assert(num_of_roots() != 0);
		double a = coefficients[0];
		double b = coefficients[1];
		double c = coefficients[2];
		if (a == 0 && b != 0)
			return -1*c/b;
		if (a != 0 && b*b == 4*a*c)
			return -1*b/(2*a);
		if (a != 0 && b*b > 4*a*c)
			return (-1*b+sqrt(b*b-4*a*c))/(2*a);
		return 0;
	}
	

	quadratic operator + (const quadratic& q1, const quadratic& q2)
	{
		double a = q1.get_coefficient_a()+q2.get_coefficient_a();
		double b = q1.get_coefficient_b()+q2.get_coefficient_b();
		double c = q1.get_coefficient_c()+q2.get_coefficient_c();
		quadratic output;
		output.set_coefficients(a,b,c);
		return output;
	}

	quadratic operator * (double r, const quadratic& q)
	{
		double a = r*q.get_coefficient_a();
		double b = r*q.get_coefficient_b();
		double c = r*q.get_coefficient_c();
		quadratic output;
		output.set_coefficients(a,b,c);
		return output;
	}
}
