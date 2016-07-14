#include <iostream>
#include "set1.h"
#include <cassert>

using namespace main_savitch_3;

int main(int argc, char** argv)
{
	set s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(6);
	assert(s1.size() == 4);
	assert(s1.contains(1));
	assert(s1.contains(2));
	assert(s1.contains(3));
	assert(s1.contains(6));
	set s2;
	s2.insert(3);
	s2.insert(4);
	s2.insert(5);
	s2.insert(5);
	assert(s2.size() == 3);
	set s3 = s1+s2;
	assert(s3.size() == 6);
	assert(s3.contains(1));
	assert(s3.contains(2));
	assert(s3.contains(3));
	assert(s3.contains(4));
	assert(s3.contains(5));
	assert(s3.contains(6));
	set s4 = s1-s2;
	assert(s4.size() == 3);
	assert(s4.contains(1));
	assert(s4.contains(2));
	assert(s4.contains(6));
	set s5 = s1^s2;
	assert(s5.size() == 1);
	assert(s5.contains(3));
	s3.insert(0);
	s3.insert(10);
	s3.insert(20);
	s3.insert(30);
	s3.insert(40);
	s3.insert(50);
	s3.insert(60);
	s3.insert(70);
	s3.insert(80);
	s3.insert(90);
	s3.insert(100);
	s3.insert(110);
	s3.insert(120);
	s3.insert(1230);
	s3.insert(715);
	s3.insert(6574);
	s3.insert(347);
	s3.insert(247);
	s3.insert(96);
	s3.insert(34127);
	s3.insert(197);
	s3.insert(8520);
	s3.insert(540);
	s3.insert(8+70);
	s3.insert(8+71); //Breaks assertion
	s3.display();
	assert(s3.check_exist(100));
	std::cout << s3.size() <<" Everything Works!" << std::endl;
	
	return 0;
}


