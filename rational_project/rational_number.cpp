#include "rational_number.h"
#include <cassert>

namespace rational
{
	rational_number::rational_number(int n, int d)
	{
		assert(d != 0);
		numerator = n;
		denominator = d;
	}
	
	int rational_number::get_numerator() const
	{
		return numerator;
	}
	
	int rational_number::get_denominator() const
	{
		return denominator;
	}
	
	void rational_number::reduce()
	{
		
	}
	
	rational_number operator + (const rational_number& r1, const rational_number& r2)
	{
		int n = r1.get_numerator()*r2.get_denominator()+r2.get_numerator()*r1.get_denominator();
		int d = r1.get_denominator()*r2.get_denominator();
		return rational_number(n,d);
	}
	rational_number operator - (const rational_number& r1, const rational_number& r2)
	{
		int n = r1.get_numerator()*r2.get_denominator()-r2.get_numerator()*r1.get_denominator();
		int d = r1.get_denominator()*r2.get_denominator();
		return rational_number(n,d);
	}
	rational_number operator * (const rational_number& r1, const rational_number& r2)
	{
		int n = r1.get_numerator()*r2.get_numerator();
		int d = r1.get_denominator()*r2.get_denominator();
		return rational_number(n,d);
	}
	rational_number operator / (const rational_number& r1, const rational_number& r2)
	{
		assert(r2.get_numerator() != 0);
		int n = r1.get_numerator()*r2.get_denominator();
		int d = r1.get_denominator()*r2.get_numerator();
		return rational_number(n,d);
	}
	
	std::ostream& operator << (std::ostream& output, const rational_number& r)
	{
		output << r.get_numerator() << " / " << r.get_denominator();
		return output;
	}
	
}
