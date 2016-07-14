/************************ Steffen Lim *****************************/
/************************** cs3304 ********************************/
//compile: g++ -g -Wall -o bank account.cpp interest_calculator.cpp
#include <iostream>
#include <cstddef>
#include <string>
#include <cassert>
#include <math.h>
#include "account.h"

using namespace bank_space;
using namespace std;

account my_account;

///Pre: goal_value > 0
///		yearly_deposit >= 0;
///Post: returns the number of years required to reach the goal value along with additional yearly deposits
int calculate_savings (double goal_value, double yearly_deposit)
{
	assert(goal_value > 0);
	assert(yearly_deposit >= 0);
	double current_balance = my_account.get_balance();
	size_t count = 0;
	while (my_account.get_balance() < goal_value)
	{
		my_account.apply_intrest(1.0, 1);
		my_account.deposite("pass", yearly_deposit);
		count++;
	}
	my_account.set_balance("pass", current_balance);
	return count;
}

int main(int argc, char **argv)
{
	//tests
	account a1;
	a1.set_balance("pass", 10101010.1010101);
	a1.set_interest_rate("pass", 0.01);
	assert(a1.get_balance() == 10101010.1010101);
	assert(a1.get_interest_rate() == 0.01);
	a1.deposite("pass", 500);
	assert(a1.get_balance() == 10101510.1010101);
	a1.withdraw("pass", 10101010.1010101);
	assert(a1.get_balance() == 500);
	a1.apply_intrest(1.0, 1);
	assert(a1.get_balance() == 505);
	a1.withdraw("pass", 5);
	a1.apply_intrest(5.0, 2);
	a1.print_balance(); //should be 525.57
	cout << "actual value: " << a1.get_balance() << endl;
	
	cout << "test successful " << endl;
	
	//interest Calculator
	cout << "enter a balance" << endl;
	int balance_amount;
	cin >> balance_amount;
	cout << "provide the interest rate" << endl;
	double interest_rate_given;
	cin >> interest_rate_given;
	cout << "enter the goal value" << endl;
	double goal_value;
	cin >> goal_value;
	cout << "enter a yearly deposite (enter 0 if none)" << endl;
	double yearly_deposit;
	cin >> yearly_deposit;
	
	my_account.deposite("pass", balance_amount);
	my_account.set_interest_rate("pass", interest_rate_given);
	
	int years = calculate_savings(goal_value, yearly_deposit);
	
	cout << "It will take " << years << " years to reach the goal value with the current interest rate" << endl;
	
	return 0;
}
