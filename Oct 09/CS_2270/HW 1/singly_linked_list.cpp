//Andrew Rutherford
//CSCI 2270
//Homework #1

#include "singly_linked_list.h"

using namespace std;

void add_node(node*& head_ptr, const int& payload)
{
	//If list is empty, make a new node, and set payload to data
	if (head_ptr == nullptr)
	{
		node* new_node = new node;
		new_node->data = payload;
		new_node->next = nullptr;
		head_ptr = new_node;
		return; 
		delete new_node;
	}
	
	//If list is not empty, but the number is less than head_ptr
	if (head_ptr != nullptr && ( payload <= head_ptr->data))
	{
		//Create a new node
		//Set its data to the payload
		//Set the new node's next to the head_ptr
		//Set the head_ptr as the new node
		node* new_node = new node;
		new_node->data = payload;
		new_node->next = head_ptr;
		head_ptr = new_node;
		return;
		delete new_node;
	}
	
	//If list is not empty, and number is greater than head_ptr;
	if (head_ptr != nullptr && ( payload > head_ptr->data ))
	{
		//Create a new node
		//Set its data to the payload
		node* new_node = new node;
		new_node->data = payload;
		
		//Create a pointer called cursor, set to head_ptr
		node* cursor = head_ptr;
		while ((cursor->next != nullptr) && (payload > cursor->next->data))
		{
			//Walk through list
			cursor = cursor->next;
		}	
		new_node->next = cursor->next;
		cursor->next = new_node;
		return;
		delete cursor;
	}	
}

bool remove_node(node*& head_ptr, const int& target)
{
	//If target equals the value of head_ptr (first value)
	if (target == head_ptr->data)
	{
		//Create a copy of head_ptr called destroy
		//Move head_ptr to head_ptr->next
		//Delete destroy and return true;
		node* destroy = head_ptr;
		head_ptr = head_ptr->next;
		return true;
		delete destroy;
		
	}
	
	//Create a pointer to head_ptr called cursor
	node* cursor = head_ptr;
	
	//While the next value of cursor is not nullptr
	//Ensures loop does not exceed list length
	while (cursor->next != nullptr)
	{
		//If the data of cursor->next matches the target
		if (cursor->next->data == target)
		{
			node* destroy = cursor->next; 
			cursor->next = destroy->next;
			delete destroy;
			return true;
		}
		cursor = cursor->next;
	}
}

bool find_list(const node*& head_ptr, const int& target)
{
	//While the next value of head_ptr is not nullptr
	//Ensures loop does not exceed list length
	while (head_ptr != nullptr)
	{
		//If head_ptr->data matches target, return true
		if (head_ptr->data == target)
		{
			return true;
		}
		
		//If head_ptr->data does not match target, move to head_ptr->next
		if (head_ptr->data != target)
		{
			head_ptr = head_ptr->next;
		}
	}
	
	//If head_ptr->next is nullptr, the loop is at the end of the list.  Return false
	if (head_ptr == nullptr)
	{
		return false;
	}
}

void clear_list(node*& head_ptr)
{
	//Delete the head_ptr as long as it does not equal nullptr
	while (head_ptr != nullptr)
	{
		node* destroy = head_ptr;
		head_ptr = destroy->next;
		delete destroy;
	}
}

void print_list(const node*& head_ptr)
{
	const node* cursor = head_ptr;
	while (cursor != nullptr)
	{
		cout << cursor->data << " ";
		cursor = cursor->next;
	}
	cout << endl;
}

void copy_list(const node*& source_ptr, node*& dest_ptr)
{
	//If dest_ptr is not empty, clear it with clear_list
	if (dest_ptr != nullptr)
	{
		clear_list(dest_ptr);
	}
	
	//Create pointers to dest_ptr and source_ptr
	node* dest = dest_ptr;
	const node* source = source_ptr;
	
	//Copy data from source to dest, as long as source is not nullptr
	while (source != nullptr)
	{
		node* new_node = new node;
		new_node->data = source->data;
		if (dest == nullptr)
		{
			dest = new_node;
		}
		if (dest != nullptr)
		{
			dest->next = new_node;
		}
		source = source->next;
		dest = dest->next;
		delete new_node;
	}
}

