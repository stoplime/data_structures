// FILE: set1.h

#ifndef MAIN_SAVITCH_set1_H
#define MAIN_SAVITCH_set1_H
#include <cstdlib>  // Provides size_t

namespace main_savitch_3
{
	///Invariance: no duplicates present
    class set
    { 
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;
        // CONSTRUCTOR
        set();
        ~set(); 
        // MODIFICATION MEMBER FUNCTIONS
        /// Post: remove all in the bag, used = 0
        void empty();
        /// Post: remove a specified object, returns true if successful
        bool erase(const value_type& target);
        /// Pre: checks to see if entry already exists
        /// Post: adds the new entry to the set, returns true if successful
        bool insert(const value_type& entry);
        ///Post: returns the data with a given index
        value_type get_data(size_type index) const;
        ///Post: resize the data array
        //void resize(size_type new_capacity);
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const { return used; }
        bool contains(const value_type& target) const;
    private:
        value_type* data;  // The array to store items
        size_type used;             // How much of array is used
        size_type capacity;
    };

    // NONMEMBER FUNCTIONS for the set class
    ///Pre: size of b1+b2 cannot be greater than CAPACITY
    set operator +(const set& b1, const set& b2);
    set operator -(const set& b1, const set& b2);
    set operator ^(const set& b1, const set& b2);
}

#endif
