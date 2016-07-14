#include "complex.h"
#include <cassert>
#include <math.h>

namespace complex_numbers
{
	complex::complex(double _real, double _imaginary)
	{
		real = _real;
		imaginary = _imaginary;
	}
	
	double complex::get_real() const
	{
		return real;
	}
	
	double complex::get_imaginary() const
	{
		return imaginary;
	}
	
	double complex::get_modulo() const
	{
		return sqrt(real*real + imaginary*imaginary);
	}
	
	complex operator + (const complex& c1, const complex& c2)
	{
		double a = c1.get_real() + c2.get_real();
		double b = c1.get_imaginary() + c2.get_imaginary();
		return complex(a,b);
	}
	complex operator - (const complex& c1, const complex& c2)
	{
		double a = c1.get_real() - c2.get_real();
		double b = c1.get_imaginary() - c2.get_imaginary();
		return complex(a,b);
	}
	complex operator * (const complex& c1, const complex& c2)
	{
		double a = (c1.get_real() * c2.get_real()) - (c1.get_imaginary() * c2.get_imaginary());
		double b = c1.get_real() * c2.get_imaginary() + c2.get_real() * c1.get_imaginary();
		return complex(a,b);
	}
	complex operator / (const complex& c1, const complex& c2)
	{
		assert((c2.get_real()*c2.get_real()+c2.get_imaginary()*c2.get_imaginary()) != 0);
		double a = (c1.get_real() * c2.get_real() + c1.get_imaginary() * c2.get_imaginary())/(c2.get_real()*c2.get_real()+c2.get_imaginary()*c2.get_imaginary());
		double b = (c1.get_imaginary() * c2.get_real() - c1.get_real() * c2.get_imaginary())/(c2.get_real()*c2.get_real()+c2.get_imaginary()*c2.get_imaginary());
		return complex(a,b);	
	}
	/*
	double operator % (const complex& c1, const complex& c2)
	{
		double a = c1.get_real() + c2.get_real();
		double b = c1.get_imaginary() + c2.get_imaginary();
		return sqrt(a*a + b*b);
	}*/
	
	std::ostream& operator << (std::ostream& output, const complex& c)
	{
		output << c.get_real() << " + " << c.get_imaginary() << "i";
		return output;
	}
	
}
