/**	Steffen Lim
 * Anh Huynh
 * Andrew Shatz
 * Manaf Alhabbal
 * Kyle Walker
 * Chasse Cossairt
*/
#include "node1.h"
#include <iostream>
#include <cassert>

using namespace std;
using namespace main_savitch_5;

///Post: returns the list without any repetitions
void no_repetition (node* input_list)
{
	node* current_node = input_list->link();
	
	while (current_node->link() != NULL)
	{
		node* check_node = current_node;
		// checks if check_node has not finished the link_list
		while (check_node->link() != NULL)
		{
			cout << "check:" << check_node->data() << " current:"<< current_node->data() << endl;
			//remove the check_node next data with current_data
			if ((check_node->link())->data() == current_node->data())
			{
				//remove the check_node and reconfigures the list
				list_remove(check_node);
			}
			//increment check_node
			check_node = check_node->link();
		}
		//increment current_node
		current_node = current_node->link();
	}
	
}

int main (int arg, char ** argv)
{
	node* list = new node(10.0);
	list_head_insert(list, 1.0);
	list_head_insert(list, 2.0);
	list_head_insert(list, 3.0);
	list_head_insert(list, 1.0);
	list_head_insert(list, 1.0);
	list_head_insert(list, 5.0);
	list_head_insert(list, 2.0);
	list_head_insert(list, 5.0);
	list_head_insert(list, 7.0);
	
	node* traverse = list;
	while (traverse != NULL)
	{
		cout << traverse->data() << endl;
		traverse = traverse->link();
	}
	
	cout << "before no_repetition" << endl;
	no_repetition(list);
	cout << "after no_repetition" << endl;
	traverse = list;
	while (traverse != NULL)
	{
		cout << traverse->data() << endl;
		traverse = traverse->link();
	}
	
	return 0;
}
