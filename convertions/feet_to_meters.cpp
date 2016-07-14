/************************ Steffen Lim *****************************/
/************************** cs3304 ********************************/
#include <iostream>
#include <cassert>

using namespace std;

float feet_to_meter (float feet)
//Precondition: non-negative
//Postcondition: the converted value from feet to meters
{
	assert(feet >= 0);
	return feet*0.3048;
}

void print_table ()
//Precondition: non-negative
//Postcondition:
{
	const char   HEADING1[]  = "   Feet";
    const char   HEADING2[]  = "Meters";
    const float  TABLE_BEGIN =         0.0f;
    const float  TABLE_END   =        100.0f;
    const float  TABLE_STEP  =        10.0f;
    
    cout << "CONVERSIONS from " << TABLE_BEGIN << " to " << TABLE_END << endl;
    cout << HEADING1 << "  " << HEADING2 << endl;
    for (float value1 = TABLE_BEGIN; value1 <= TABLE_END; value1+=TABLE_STEP)
	{
		float value2 = feet_to_meter(value1);
		cout << "    " << value1 << "ft" << "  "; 
        cout << "    " << value2 << "m" << endl; 
	}
    
}

int main(int argc, char **argv)
{
	print_table();
	
	
	return 0;
}
