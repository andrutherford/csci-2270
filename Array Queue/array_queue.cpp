#include "array_queue.h"

using namespace std;


void init(array_queue& que)
{

}

void clear(array_queue& que)
{

}

void destr(array_queue& que)
{
	destr(que.arr);
}

void print(const array_queue& que)
{
	cout << "queue front ";
	for (unsigned int i = que.front; i != que.back; i = (i + 1) % que.arr.capacity)
	{
		cout << que.arr.data[i] << " ";
	}
	cout << "back of queue" << endl;
}

void add(array_queue& que, const int& payload)
{
	que.arr.data[que.back] = payload;
	que.back = (que.back + 1) % que.arr.capacity;
	if (que.back == que.front)
	{
		int* new_data = new int[que.arr.capacity * 2];
		if (que.front > 0)
		{
			copy(que.arr.data + 0, que.arr.data + que.front, new_data + 0)
		}
		copy(que.arr.data + que.front, que.arr.data + que.arr.capacity, new_data + que.front + que.arr.capacity);
		delete [] que.arr.data;
		que.arr.data = new_data;
		que.front += que.arr.capacity;
		que.arr.capacity *= 2;
	}
}

void remove(array_queue& que)
{
	que.front = (que.front + 1) % que.arr.capacity;
}

int front(const array_queue& que)
{
	return que.arr.data[que.front];
}

bool empty(const array_queue& que)
{
	return (que.front == que.back);
}
