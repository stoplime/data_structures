/// g++ -g -Wall -o heap_queue main.cpp
#include "priority_queue.h"
#include <iostream>	

using namespace std;

int main(int argc, char** argv)
{
	priority_queue<int> q;
	q.push(5);
	q.push(1);
	q.push(0);
	q.push(9);
	q.push(6);
	q.push(3);
	q.push(4);
	q.push(2);
	q.push(7);
	q.push(8);
	
	for (int i = 9; i >= 0 ; i--)
	{
		assert(q.top() == i);
		q.pop();
	}
	
	cout << "it worked" << endl;
	
	return 0;
}
