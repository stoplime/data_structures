#ifndef COMPLEX_CLASS_H_
#define COMPLEX_CLASS_H_

#include <iostream>
#include <string>
namespace complex_numbers
{
	// class invariant: format of a + bi
	class complex
	{
	public:
		complex(double _real, double _imaginary);
		double get_real() const;
		double get_imaginary() const;
		double get_modulo() const;
	private:
		double real;
		double imaginary;
	};
	
	std::ostream& operator << (std::ostream& output, const complex& c);
	
	complex operator + (const complex& c1, const complex& c2);
	complex operator - (const complex& c1, const complex& c2);
	complex operator * (const complex& c1, const complex& c2);
	complex operator / (const complex& c1, const complex& c2);
}

#endif
