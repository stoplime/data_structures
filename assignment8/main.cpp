/// g++ -g -Wall -o hash_table main.cpp
#include "table2.h"
#include <iostream>
#include <cassert>

using namespace std;
using namespace main_savitch_12B;

class hashed
{
public:
	hashed(
		int _key,
		int _data = 0)
	{
		key = _key;
		data = _data;
	}
	hashed()
	{
		key = 0;
		data = 0;
	}
	int* get_data() {return &data;}
	int key;
private:
	int data;
};

int main(int argc, char** argv)
{
	table<hashed> t;
	hashed h1(1,1);
	hashed h2(0,2);
	t.insert(h1);
	t.insert(h2);
	assert(t.is_present(0));
	assert(t.is_present(1));
	t.remove(1);
	assert(!t.is_present(1));
	assert(!t.is_present(811));
	hashed h3(811, 5);
	t.insert(h3);
	assert(t.is_present(811));
	t.remove(0);
	assert(t.is_present(811));
	t.remove(811);
	
	cout << "Yay!" << endl;
	
	return 0;
}
