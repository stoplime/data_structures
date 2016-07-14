/************************ Steffen Lim *****************************/
/************************** cs3304 ********************************/
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <cassert>
#include <math.h>

#define PI 3.14159265

using namespace std;

double find_area(int side_length = 1, int num_of_side = 3)
//Precondition: side_length >= 0; num_of_side >= 3;
//Postcondition: returns the area of a given polynomial.
{
	assert(side_length >= 0);
	assert(num_of_side >= 3);
	double deg_to_rad = PI/180;
	double apothem = 0.5*side_length*(cos(180/num_of_side*deg_to_rad)/sin(180/num_of_side*deg_to_rad));
	return 0.5*side_length*num_of_side*apothem;
}

double area_triangle(int side_length)
//Precondition: side_length >= 0;
//Postcondition: area of polynomial
{
	return find_area(side_length, 3);
}

double area_square(int side_length)
//Precondition: side_length >= 0;
//Postcondition: area of polynomial
{
	return find_area(side_length, 4);
}

double area_pentagon(int side_length)
//Precondition: side_length >= 0;
//Postcondition: area of polynomial
{
	return find_area(side_length, 5);
}

double area_hexagon(int side_length)
//Precondition: side_length >= 0;
//Postcondition: area of polynomial
{
	return find_area(side_length, 6);
}

double area_heptagon(int side_length)
//Precondition: side_length >= 0;
//Postcondition: area of polynomial
{
	return find_area(side_length, 7);
}

double area_octagon(int side_length)
//Precondition: side_length >= 0;
//Postcondition: area of polynomial
{
	return find_area(side_length, 8);
}

void user_interface ()
{
	cout << "Find Polygon area:" << endl;
	cout << "choose number of sides(3-8): ";
	int side_count_num;
	cin >> side_count_num;
	cout << "choose length of each side: ";
	int side_length_num;
	cin >> side_length_num;
	
	if (side_count_num < 3)
	{
		cout << "please enter a shape greater than or equal to 3 sides" << endl;
		user_interface();
		return;
	}
	if (side_length_num < 0)
	{
		cout << "please enter a side length greater than or equal to 0" << endl;
		user_interface();
		return;
	}
	
	cout << "Area: " << find_area(side_length_num, side_count_num) << endl;
}

int main(int argc, char **argv)
{
	user_interface();
	return 0;
}

