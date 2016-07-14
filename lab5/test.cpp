///g++ -g -Wall -o sequence3 sequence3.cpp test.cpp node1.cpp
#include <iostream>     // Provides cout.
#include <cstdlib>      // Provides size_t.
#include "sequence3.h"  // Provides the sequence class with double items.
using namespace std;
using namespace main_savitch_5;

int main()
{
	sequence s1;
	//cout << "0: " << s1.current() << endl;
	s1.attach(10);
	s1.attach(20);
	s1.attach(30);
	s1.attach(40);
	s1.attach(50);
	s1.attach(60);
	s1.attach(70);
	s1.attach(80);
	s1.attach(90);
	/*cout <<"0:" << s1.current() << endl;
	//s1.advance();
	//cout <<"1:" << s1.current() << endl;
	s1.attach(100);
	cout <<"2:" << s1.current() << endl;
	//s1.advance();
	s1.attach(305);
	cout <<"3:" << s1.current() << endl;
	//s1.advance();
	s1.advance();
	s1.insert(5);
	cout <<"4:" << s1.current() << endl;//*/
	s1.start();
	cout <<"1:" << s1.current() << endl;
	s1.advance();
	/*s1.advance();
	s1.advance();
	s1.advance();
	s1.advance();*/
	s1.remove_current();
	cout <<"2:" << s1.size() << endl;
	
	sequence s2(s1);
	s2.start();
	while (s2.is_item())
	{
		cout << s2.current() << endl;
		s2.advance();
	}
	
	return 0;
}
