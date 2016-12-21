#include "dynamic_size_array_unsorted.h"

using namespace std;


void init(int_array& arr)
{
	arr.count = 0;
	arr.capacity = arr.DEFAULT_CAPACITY;
	arr.data = new int[arr.capacity];
}

void clear(int_array& arr)
{
	destr(arr);
	init(arr);
}

void destr(int_array& arr)
{
	delete [] arr.data;
	arr.count = 0;
}

void print(const int_array& arr)
{
	for (unsigned int i = 0; i < arr.count; ++i)
		cout << arr.data[i] << " ";
	cout << endl;
}

bool contains(const int_array& arr, const int& target)
{
	bool found = false;
	for (unsigned int i = 0; !found && i < arr.count; ++i)
		if (arr.data[i] == target) found = true;
	return found;
}

void resize(int_array& arr)
{
	arr.capacity *= 2;
	int* new_data = new int[arr.capacity];
	for (unsigned int i = 0; i < arr.count; ++i)
	{
		new_data[i] = arr.data[i];
	}
	delete [] arr.data;
	arr.data = new_data;
}

void add(int_array& arr, const int& payload)
{
	if (arr.count == arr.capacity)
		resize(arr);
	
	arr.data[arr.count++] = payload;
}

bool remove(int_array& arr, const int& target)
{
	unsigned int i = 0; 
	while (i < arr.count && arr.data[i] != target)  i++;
	
	if (i == arr.count) return false;
	if (i < arr.count - 1)
	{
		arr.data[i] = arr.data[arr.count - 1];
	}
	
	arr.count--;
	return true;
}

