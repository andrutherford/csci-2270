#include "list_queue.h"

using namespace std;

void init(list_queue& que)
{
	que.head_ptr = nullptr;
	que.tail_ptr = nullptr;
}

void add(list_queue& que, const int& payload)
{
	if (que.head_ptr == nullptr)
	{	
		que.head_ptr = new node();
		que.head_ptr->data = payload;
		que.head_ptr->next = nullptr;
		que.tail_ptr = que.head_ptr;
	}
	else
	{
		que.tail_ptr->next = new node();
		que.tail_ptr = que.tail_ptr->next;
		que.tail_ptr->data = payload;
		que.tail_ptr->next = nullptr;
	}
}

bool remove(list_queue& que)
{
	if (que.head_ptr == nullptr) return false;
	node* rest_of_list = que.head_ptr->next;
	delete que.head_ptr;
	que.head_ptr = rest_of_list;
	return true;
}

void destr(list_queue& que)
{
	clear_list(que.head_ptr);
}

void print(const list_queue& que)
{
	cout << "Front ";
	print_list(que.head_ptr);
}

bool empty(const list_queue& que)
{
	return (que.head_ptr == nullptr);
}

int front(const list_queue& que)
{
	return que.head_ptr->data;
}

