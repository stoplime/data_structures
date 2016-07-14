/************************ Steffen Lim *****************************/
/************************** cs3304 ********************************/
//compile: g++ -g -Wall -o bank account.cpp interest_calculator.cpp
#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>
#include <math.h>
#include "account.h"

using namespace bank_space;

///Post: create an empty account 
account::account()
{
	balance = 0;
	intrest_rate =0;
}

///Post: returns a value for the current balance
double account::get_balance() const
{
	return balance;
}

///Post: prints the balance to two decimal places
void account::print_balance() const
{
	std::streamsize ss = std::cout.precision();
	std::cout << "balance: " << std::setprecision (2) << std::fixed << balance << std::endl;
	std::cout.precision (ss);
}

///Post: returns a value for the current interest rate
double account::get_interest_rate() const
{
	return intrest_rate;
}

///Pre: provides authenticated pass code
///amount > 0;
///Post: sets the balance
void account::set_balance(std::string pass, double amount)
{
	assert(amount >= 0);
	if (authenticate(pass) == 1)
	{
		balance = amount;
	}
}

///Pre: provides authenticated pass code
///amount >= 0;
///Post: sets the interest rate
void account::set_interest_rate(std::string pass, double amount)
{
	assert(amount >= 0);
	if (authenticate(pass) == 1)
	{
		intrest_rate = amount;
	}
}

///Pre: provides authenticated pass code
///amount >= 0;
///Post: adds the deposit balance with amount
void account::deposite(std::string pass, double amount)
{
	assert(amount >= 0);
	if (authenticate(pass) == 1)
	{
		balance += amount;
	}
	
}

///Pre: provides authenticated pass code
///amount >= 0;
///Post: subtract the deposit balance with amount
void account::withdraw(std::string pass, double amount)
{
	assert(amount >= 0);
	if (authenticate(pass) == 1)
	{
		balance -= amount;
	}
}

///Pre: years > 0
///		compound > 0
///Post: adds the amount of interest by the interest rate for the given years
void account::apply_intrest (double years, int compound)
{
	assert(years > 0);
	assert(compound > 0);
	balance *= pow(1.0+intrest_rate/compound, compound*years);
}

///Post: authenticate for security purposes (deligated)
///returns 1 for successful authentication and 0 if failed
int account::authenticate(std::string pass)
{
	//delegated
	if (pass == "pass")
	{
		return 1;
	}
	return 0;
}




