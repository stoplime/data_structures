/************************ Steffen Lim *****************************/
/************************** cs3304 ********************************/
#ifndef QUADRATIC_OBJECT_H_
#define QUADRATIC_OBJECT_H_

namespace quadratic_namespace
{
	/// Class Invariance: Contains 3 doubles coresponding to the coefficients of a quadratic expression
	class quadratic
	{
	public:
		///Post: create an empty quadratic object with coefficients of 0
		quadratic();
		
		///Post: sets coefficients to a, b, c
		void set_coefficients(double a, double b, double c);
		
		///Post: returns the coresponding coefficient
		double get_coefficient_a() const;
		double get_coefficient_b() const;
		double get_coefficient_c() const;
		
		///Post: returns the value of the expression ax^2+bx+c
		double evaluate (double x);
		
		///Post: returns the number of roots as 0, 1, 2, or 3 where 3 is an infinite amount of roots.
		int num_of_roots();
		
		///Pre: num_of_roots > 0
		///Post: returns the high or low value of root num, if infinity returns 0, if only one root both functions return the one root
		double low_root();
		double high_root();
	private:
		double coefficients[3];
	};
	
	///Post: returns the sum of two quadratics
	quadratic operator + (const quadratic& q1, const quadratic& q2);
	
	///Post: returns the product of a number with a quadratics
	quadratic operator * (double r, const quadratic& q);
	
}
#endif
