/************************ Steffen Lim *****************************/
/************************** cs3304 ********************************/
#ifndef BANK_ACCOUNT_OBJ_H_
#define BANK_ACCOUNT_OBJ_H_

#include <iostream>
#include <string>

namespace bank_space
{
	/// Class Invariance: Interests rates are compounded. 
	class account
	{
	public:
		///Post: create an empty account 
		account();
		
		///Post: returns a value for the current balance
		double get_balance() const;
		
		///Post: prints the balance to two decimal places
		void print_balance() const;
		
		///Post: returns a value for the current interest rate
		double get_interest_rate() const;
		
		///Pre: provides authenticated pass code
		///amount > 0;
		///Post: sets the balance
		void set_balance(std::string pass, double amount);
		
		///Pre: provides authenticated pass code
		///amount > 0;
		///Post: sets the interest rate
		void set_interest_rate(std::string pass, double amount);
		
		///Pre: provides authenticated pass code
		///amount > 0;
		///Post: adds the deposit balance with amount
		void deposite(std::string pass, double amount);
		
		///Pre: provides authenticated pass code
		
		/***************************************
		 * also cannot be larger than the balance
		 */
		///amount > 0;
		///Post: subtract the deposit balance with amount
		void withdraw(std::string pass, double amount);
		
		///Pre: years > 0
		///		compound > 0
		///Post: adds the amount of interest by the interest rate for the given years
		void apply_intrest (double years, int compound);
		
	private:
		///Post: authenticate for security purposes (deligated)
		///returns 1 for successful authentication and 0 if failed
		
		/**************************************
		 * bool would be better
		 */
		int authenticate(std::string pass);
		
		double balance;
		double intrest_rate;
	};
}
#endif
