/// g++ -g -Wall -o flat_tree main.cpp
#include "bintree.h"
#include <iostream>
#include <iterator>
#include <list>

using namespace main_savitch_10;
using namespace std;

list<int> L;

/// Post: Create a binary tree, hardcode
binary_tree_node<int>* create_tree()
{
	binary_tree_node<int>* t4 = new binary_tree_node<int> (3);
	binary_tree_node<int>* t9 = new binary_tree_node<int> (32);
	binary_tree_node<int>* t6 = new binary_tree_node<int> (48);
	binary_tree_node<int>* t7 = new binary_tree_node<int> (64);
	binary_tree_node<int>* t8 = new binary_tree_node<int> (9999);
	binary_tree_node<int>* t5 = new binary_tree_node<int> (16, NULL, t9);
	binary_tree_node<int>* t3 = new binary_tree_node<int> (918, t7, t8);
	binary_tree_node<int>* t2 = new binary_tree_node<int> (46, t5, t6);
	binary_tree_node<int>* t1 = new binary_tree_node<int> (6, t4, t2);
	binary_tree_node<int>* t0 = new binary_tree_node<int> (56, t1, t3);
	return t0;
}

/// Post: adds data from tree to the global list
void push_list_callback(int data)
{
	L.push_back(data);
}

/// Post: create a linked list of the binary tree
void flatten_tree(binary_tree_node<int>* t)
{
	inorder(push_list_callback, t);
}

/// Post: display the flattened tree
void display_list()
{
	copy(L.begin(), L.end(), ostream_iterator<int>(cout, "\n"));
}

int main()
{
	binary_tree_node<int>* input_tree = create_tree();
	flatten_tree(input_tree);
	display_list();
}
