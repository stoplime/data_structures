// FILE: set1.cxx
// CLASS IMPLEMENTED: set (see set1.h for documentation)
// INVARIANT for the set class:
//   1. The number of items in the set is in the member variable used;
//   2. For an empty set, we do not care what is stored in any of data; for a
//      non-empty set the items in the set are stored in data[0] through
//      data[used-1], and we don't care what's in the rest of data.

/// g++ -g -Wall -o sets set1.cpp set1_test.cpp

#include <algorithm> // Provides copy function
#include <cassert>   // Provides assert function
#include <iostream>
#include "set1.h"
using namespace std;

namespace main_savitch_3
{
    const set::size_type set::CAPACITY;
    
    set::set()
    {
		data = new set::value_type[CAPACITY];
		used = 0;
		capacity = CAPACITY;
	}
    
    set::~set()
    {
		delete [] data;
	}
    
    void set::empty()
    {
		used = 0;
		capacity = CAPACITY;
    }

    bool set::erase(const value_type& target)
    {
		for (size_t i = 0; i < used; i++)
		{
			if (data[i] == target)
			{
				used--;
				data[i] = data[used];
				return true;
			}
		}
		return false;
    }
    
    void set::resize(size_type new_capacity)
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
	
    bool set::insert(const value_type& entry)
    // Library facilities used: cassert
    {   
		
		if(used >= CAPACITY)
		{
			resize(used*2);
		}
		//assert(used < CAPACITY);
        for (size_t i = 0; i < used; i++)
		{
			if (data[i] == entry)
			{
				return false;
			}
		}
		data[used] = entry;
		used++;
		return true;
    }
    
    void set::display()
    {
		std::cout << "set: " << std::endl;
		for (size_t i = 0; i < used; i++)
		{
			std::cout << data[i] << std::endl;
		}
	}
    
    set::value_type set::get_data(size_type index) const
    {
		return data[index];
	}
	
    bool set::check_exist (value_type item)
    {
		for (size_t i = 0; i < used; i++)
		{
			if (data[i] == item)
			{
				return true;
			}
		}
		return false;
	}
	
	void set::operator =(const set& source)
	{
		used = source.used;
		capacity = source.capacity;
		copy(source.data, source.data+used, data);
	}
	
	bool set::contains(const value_type& target) const
	{
		for (size_t i = 0; i < used; i++)
		{
			if (data[i] == target)
			{
				return true;
			}
		}
		return false;
	}

	// O(n^2)
    set operator +(const set& b1, const set& b2)
    // Library facilities used: cassert
    {
        set answer;
		size_t size = b1.size() + b2.size();
		
        if(size > set::CAPACITY)
        {
			answer.resize(size);
		}//*/
		//assert(size <= set::CAPACITY);

        for (size_t j = 0; j < b2.size(); j++)
		{	
			answer.insert(b2.get_data(j));
		}
        
        for (size_t i = 0; i < b1.size(); i++)
		{
			bool union_b1 = false;
			for (size_t j = 0; j < b2.size(); j++)
			{
				if (b1.get_data(i) == b2.get_data(j))
				{
					union_b1 = true;
					break;
				}
			}
			if (!union_b1)
			{
				answer.insert(b1.get_data(i));
			}
		}
		
        return answer;
    }
    // O(n^2)
    set operator -(const set& b1, const set& b2)
    {
        set answer;
		
		for (size_t i = 0; i < b1.size(); i++)
		{
			answer.insert(b1.get_data(i));
		}
		for (size_t i = 0; i < b2.size(); i++)
		{
			for (size_t j = 0; j < answer.size(); j++)
			{
				if (answer.get_data(j) == b2.get_data(i))
				{
					answer.erase(b2.get_data(i));
					break;
				}
			}
			
		}
		return answer;
	}
	
	// O(n^2)
	set operator ^(const set& b1, const set& b2)
	{
		set answer;
		for (size_t i = 0; i < b1.size(); i++)
		{
			for (size_t j = 0; j < b2.size(); j++)
			{
				if (b1.get_data(i) == b2.get_data(j))
				{
					answer.insert(b1.get_data(i));
					break;
				}
			}
			
		}
		return answer;
	}
    
}
