#ifndef _SET_H_
#define _SET_H_

#include <cstdlib>
#include <iostream>
#include "node1.h"


/**********************************************
class invariant: set cannot have duplicates
*/
namespace main_savitch_5
{
	class set
	{
	public:
		typedef int value_type;
		typedef std::size_t size_type;
		static const size_type CAPACITY = 30;
		// Post: empty set has been created
		set();
		
		// Post: copies the src list to this list
		set(const set& src);
		
		// Post: clear the linked list
		~set();
		
		// Post: add the entry to the front of the linked list
		void insert(const value_type& entry);
		
		// Post: delets entry from the list
		void remove(const value_type& entry);
		
		// Post: number of elements in the set has been returned
		size_type size() const;
		
		// Post: true or false if entry exists
		bool contains (const value_type& entry) const;
		
		// Post: union of s1 & s2 has been returned
		friend set set_union (const set& s1, const set& s2);

		// Post: intersection of si & s2 has been returned
		friend set set_intersection(const set& s1, const set& s2);

		// Post: set consisting of all elements in s1 that are not in s2
		//   has been returned
		friend set set_difference(const set& s1, const set& s2);

		// Post: contents of s have been set to output
		friend std::ostream& operator<< (std::ostream& output, const set& s);
		
		// Post: set the current linked list to the source linked list
		void operator =(const set& source);
		
	private:
		// Post: returns a pointer to the entry, NULL if entry does not exist
		node* find_precursor (const value_type& entry) const;
		node* head_ptr;
		node* tail_ptr;
		size_type used;
	};
}
#endif
