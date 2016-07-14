///g++ -g -Wall -o post_fix post_fix.cpp

#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <list>
#include <stack>

using namespace std;

int what_operator (string in)
{
	if (in == "+")
		return 1;
	else if (in == "-")
		return 2;
	else if (in == "*")
		return 3;
	else if (in == "/")
		return 4;
	return 0;
}

int eval_post_fix (list<string>& in)
{
	stack<int> the_stack;
	for (list<string>::iterator it = in.begin(); it != in.end(); it++)
	{
		int operator_type = what_operator(*it);
		if (operator_type != 0)
		{
			int a = the_stack.top();
			the_stack.pop();
			int b = the_stack.top();
			the_stack.pop();
			
			switch (operator_type)
			{
				case 1:
					the_stack.push(a+b);
					break;
				case 2:
					the_stack.push(a-b);
					break;
				case 3:
					the_stack.push(a*b);
					break;
				case 4:
					the_stack.push(a/b);
					break;
				default:
					break;
			}
		}
		else
		{
			the_stack.push(atoi((*it).c_str()));
		}
	}
	return the_stack.top();
}

int main(int argc, char** argv)
{
	list<string> l1;
	l1.push_back("1");
	l1.push_back("2");
	l1.push_back("+");
	l1.push_back("3");
	l1.push_back("*");
	cout << eval_post_fix(l1) << endl;
	return 0;
}


