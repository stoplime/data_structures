#include "set.h"
#include <cassert>

namespace main_savitch_5
{

	set::set()
	{
		used = 0;
		head_ptr = NULL;
		tail_ptr = NULL;
	}

	set::set(const set& source)
	{
		used = source.used;
		list_copy(source.head_ptr, head_ptr, tail_ptr);
	}

	set::~set()
	{
		list_clear(head_ptr);
	}

	void set::insert(const value_type& entry)
	{
		if (contains(entry))
		{
			return;
		}
		
		list_head_insert(head_ptr, entry);
		if (used == 0)
		{
			tail_ptr = head_ptr;
		}
		used++;
	}

	void set::remove(const value_type& entry)
	{
		node* location = find_precursor(entry);
		if (location == NULL)
			return;
			
		if (head_ptr == location)
		{
			list_head_remove(head_ptr);
			return;
		}
		
		node* cursor = head_ptr;
		while (cursor->link()->data() != entry)
		{
			location = location->link();
		}
		
		list_remove(location);
		used--;
		if (used == 0)
		{
			tail_ptr = NULL;
			head_ptr = NULL;
		}
		
	}

	set::size_type set::size() const
	{
		return used;
	}

	node* set::find_precursor (const value_type& entry) const
	{
		node* location = head_ptr;
		if (location == NULL)
		{
			return NULL;
		}
		
		if (head_ptr->data() == entry)
		{
			return head_ptr;
		}
		while (location->data() != entry)
		{
			location = location->link();
			if (location == NULL)
			{
				return NULL;
			}
			
		}
		return location;
	}

	bool set::contains (const value_type& entry) const
	{
		return find_precursor (entry) != NULL;
	}

	set set_union(const set& s1, const set& s2)
	{
		set result;
		for (node* i = s1.head_ptr; i != NULL; i=i->link())
		{
			result.insert(i->data());
		}
		for (node* i = s2.head_ptr; i != NULL; i=i->link())
		{
			result.insert(i->data());
		}
		return result;
	}

	set set_intersection(const set& s1, const set& s2)
	{
		set result;
		for (node* i = s1.head_ptr; i != NULL; i=i->link())
		{
			if (s2.contains(i->data()))
			{
				result.insert(i->data());
			}
		}
		return result;
	}

	set set_difference(const set& s1, const set& s2)
	{
		set result;
		for (node* i = s1.head_ptr; i != NULL; i=i->link())
		{
			if (!s2.contains(i->data()))
			{
				result.insert(i->data());
			}
		}
		return result;
	}

	std::ostream& operator<< (std::ostream& output, const set& s)
	{
		for (node* i = s.head_ptr; i != NULL; i=i->link())
		{
			output << i->data() << " ";
		}
		return output;
	}

	void set::operator =(const set& source)
	{
		used = source.used;
		list_copy(source.head_ptr, head_ptr, tail_ptr);
	}
}
