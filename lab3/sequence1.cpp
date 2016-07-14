// compile: g++ -g -Wall -o sequences sequence_exam.cpp sequence1.cpp 
#include <cassert>
#include <cstdlib>
#include "sequence1.h"

using namespace main_savitch_3;

sequence::sequence( )
{
	used = 0;
	current_index = 0;
}
// MODIFICATION MEMBER FUNCTIONS
void sequence::start( )
{
	current_index = 0;
}
void sequence::advance( )
{
	assert(is_item());
	current_index++;
}
void sequence::insert(const value_type& entry)
{
	assert(used < CAPACITY);
	if (!is_item())
	{
		current_index = 0;
	}
	for (size_type i = used; i > current_index; i--)
	{
		data[i] = data[i-1];
	}
	data[current_index] = entry;
	used++;
}
void sequence::attach(const value_type& entry)
{
	assert(used < CAPACITY);
	current_index++;
	if (!is_item())
	{
		current_index = used;
	}
	for (size_type i = used; i > current_index; i--)
	{
		data[i] = data[i-1];
	}
	data[current_index] = entry;
	used++;
}
void sequence::remove_current( )
{
	assert(is_item());
	for (size_type i = current_index; i < used-1; i++)
	{
		data[i] = data[i+1];
	}
	used--;
}
// CONSTANT MEMBER FUNCTIONS
sequence::size_type sequence::size( ) const
{
	return used;
}
bool sequence::is_item( ) const
{
	if (current_index < used)
	{
		return true;
	}
	return false;
}
sequence::value_type sequence::current( ) const
{
	return data[current_index];
}

/* Private:
value_type data[CAPACITY];
size_type used;
size_type current_index;
*/
