///g++ -g -Wall -o linked_set main.cpp set.cpp node1.cpp
#include "set.h"
#include <cassert>

using namespace std;
using namespace main_savitch_5;

int main()
{
	set s1;
	assert(s1.size()==0);
	s1.remove(1);
	s1.insert(1);
	assert(s1.size()==1);
	assert(s1.contains(1));
	s1.insert(1);
	assert(s1.size()==1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	assert(s1.size()==4);
	set s2;
	s2.insert(1);
	s2.insert(2);
	s2.insert(4);
	s2.insert(8);
	set s3 = set_union(s1,s2);
	assert(s3.size()==5);
	assert(s3.contains(1));
	assert(s3.contains(2));
	assert(s3.contains(3));
	assert(s3.contains(4));
	assert(s3.contains(8));
	set s4 = set_intersection(s1,s2);
	assert(s4.size()==3);
	assert(s4.contains(1));
	assert(s4.contains(2));
	assert(s4.contains(4));
	set s5 = set_difference(s1,s2);
	assert(s5.size()==1);
	assert(s5.contains(3));
	
	cout << "set 1: " << s1 << endl;
	cout << "set 2: " << s2 << endl;
	cout << "set 3: " << s3 << endl;
	cout << "set 4: " << s4 << endl;
	cout << "set 5: " << s5 << endl;
	cout << "All set!" << endl;
	
	return 0;
}
