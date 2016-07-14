#ifndef RATIONAL_NUM_CLASS_H_
#define RATIONAL_NUM_CLASS_H_

#include <iostream>
// To compile:
//g++ -g -Wall -o rational test_rational.cpp rational_number.cpp
namespace rational
{
	// class invariant: rational number is in lowest terms
	// with a positive denominator
	class rational_number
	{
	public:
		rational_number(int n, int d);
		//Precondition: denominator != 0;
		//Postcondition: rational number object with class invariant
		int get_numerator() const;
		int get_denominator() const;
	private:
		void reduce();
		//Postcondition: rational number is in class invariant format
		int numerator;
		int denominator;
	};
	
	std::ostream& operator << (std::ostream& output, const rational_number& r);
	
	rational_number operator + (const rational_number& r1, const rational_number& r2);
	rational_number operator - (const rational_number& r1, const rational_number& r2);
	rational_number operator * (const rational_number& r1, const rational_number& r2);
	rational_number operator / (const rational_number& r1, const rational_number& r2);
	// Precondition: r2 != 0;
	// Postcondition: r1/r2;

}

#endif
