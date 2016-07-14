/// g++ -g -Wall -o breath_tree main.cpp
#include "bintree.h"

using namespace main_savitch_10;
using namespace std;

int total_sum;

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

/// Post: uses breath first order to sum the tree
void sum_tree (int t)
{
	total_sum += t;
}

/// Post: uses breath first order to print the tree
void print_tree (int t)
{
	cout << t << " ";
}

void call_functions (binary_tree_node<int>* t)
{
	breadthfirst(sum_tree, t);
	breadthfirst(print_tree, t);
}

int main(int argc, char** argv)
{
	binary_tree_node<int>* tree = create_tree();
	total_sum = 0;
	
	call_functions(tree);
	cout << endl;
	cout << "Total Sum: " << total_sum << endl;
	
	return 0;
}
