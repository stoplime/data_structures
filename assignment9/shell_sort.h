
#ifndef SHELL_SORT_H
#define SHELL_SORT_H
#include <cstdlib>
#include <vector>

template <class T>
class shell_sort
{
public:
	/// Post: creates an empty set of data to sort
	shell_sort();
	shell_sort(const shell_sort& src);
	~shell_sort();
	
	/// Post: rearrage the data to be sorted;
	void sort();
	
	/// ****** mainly for interacting with data values ****** 
	/// Post: adds item to the end of the vector
	void push_back(const T& item);
	/// Pre: int i must be a valid index
	/// Post: insert item at index i, shift all values after it by one
 	void insert(const T& item, int i);
 	/// Pre: data must have atleast one entry
 	/// Post: remove the last entry of the data
	void pop_back();
	/// Pre: index i must exist
	/// Post: removes the item at index i, shifts all values after it by negative one
	void remove(int i);
	
	/// overloads the [] to access data
	T operator [](int i) const    {return data[i];}
    T& operator [](int i) {return data[i];}
private:
	vector<T> data;
	/// Post: swaps indexes
	void swap(int index1, int index2);
};

#include "shell_sort.template"
