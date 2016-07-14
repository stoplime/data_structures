// compile: g++ -g -Wall -o sequences2 sequence_exam2.cpp sequence2.cpp 
#include <algorithm>
#include <string> 
#include <cassert>
#include <cstdlib>
#include "sequence2.h"

using namespace main_savitch_4;

sequence::sequence(size_type initial_capacity)
{
	used = 0;
	current_index = 0;
	capacity = initial_capacity;
	data = new value_type[capacity];
}
sequence::sequence(const sequence& source)
{
	data = new value_type[source.capacity];
	capacity = source.capacity;
	used = source.used;
	std::copy(source.data, source.data + used, data);
	current_index = source.current_index;
}
sequence::~sequence()
{
	delete [] data;
}

// MODIFICATION MEMBER FUNCTIONS
void sequence::resize(size_type new_capacity)
{
	value_type *larger_array;

	if (new_capacity == capacity)
		return; // The allocated memory is already the right size.

	if (new_capacity < used)
		new_capacity = used; // Can't allocate less than we are using.

	larger_array = new value_type[new_capacity];
	std::copy(data, data + used, larger_array);
	delete [ ] data;
	data = larger_array;
	capacity = new_capacity;
}
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
	if (used >= capacity)
	{
		resize(used+used);
	}
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
	if (used >= capacity)
	{
		resize(used+used);
	}
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
void sequence::operator =(const sequence& source)
{
	value_type *new_data;
	
	if (this == &source)
	{
		return;
	}
	
	if (capacity != source.capacity)
	{ 
		new_data = new value_type[source.capacity];
		delete [] data;
		data = new_data;
		capacity = source.capacity;
		current_index = source.current_index;
	}
	used = source.used;
	std::copy(source.data, source.data + used, data);
	
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
