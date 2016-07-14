///g++ -g -Wall -o deque deque.cpp
#include "deque.h"
#include <iostream>

using namespace std;


int main()
{
	deque<int> dq1;
	assert(dq1.empty());
	dq1.push_front(2);
	dq1.push_back(3);
	dq1.push_front(1);
	dq1.push_back(4);
	dq1.push_front(0);
	cout << dq1 << endl;
	dq1.pop_front();
	assert(dq1.front()==1);
	dq1.pop_back();
	assert(dq1.back()==3);
	cout << dq1 << endl;
	assert(dq1.size()==3);
	assert(!dq1.empty());
	assert(!dq1.full());
	dq1.push_front(2);
	dq1.push_back(3);
	dq1.push_front(1);
	dq1.push_back(4);
	dq1.push_front(0);
	dq1.push_back(6);
	dq1.push_front(5);
	cout << dq1 << endl;
	
	//dq1.push_front(5); Breaks full capacity
	return 0;
}
