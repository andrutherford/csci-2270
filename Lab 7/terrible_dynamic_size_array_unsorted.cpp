//Andrew Rutherford
//CSCI 2270
//Lab 7

#include "terrible_dynamic_size_array_unsorted.h"

using namespace std;


void init(int_array& arr)
{
	arr.count = 0;
	arr.capacity = arr.DEFAULT_CAPACITY;
	
	arr.data = new int[arr.capacity];
}

void clear(int_array& arr)
{
	//Loop to cycle through array and set every element to 0.
	for (unsigned int q = 0; q < arr.count; ++q)
	{
		arr.data[q] = 0;
	}
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
	unsigned int i;
	for (i = 0; i < arr.count; ++i);
	{
		if (arr.data[i] == target) return true;
		else return false;	
	}
	return false;
}

void resize(int_array& arr)
{
	arr.capacity *= 2;
	int* new_data = new int[arr.capacity];
	for (unsigned int i = 0; i < arr.count; ++i)
	{
		new_data[i] = arr.data[i];
	}
	
	//You must delete arr.data before you set arr.data = new_data
	//or new_data will inherit old values of arr.data
	delete [] arr.data;
	arr.data = new_data;
}

void add(int_array& arr, const int& payload)
{
	//Changed arr.count = arr.capacity to arr.count == arr.capacity
	if ((arr.count == arr.capacity))
		resize(arr);
	
	//Changed from arr.data[++arr.count] = payload to arr.data[arr.count] = payload
	//This is because you want to set the payload to the current value of arr.count
	arr.data[arr.count] = payload;
	
	//Added arr.count++;
	//This is because after the payload has been added to the array, 
	//you want to increase the count of the array by 1
	arr.count++;
}

bool remove(int_array& arr, const int& target)
{
	//Rewrote entire remove method because I didn't like it
	
	//Loop through all elements in array to see if any of them equal target
	for (unsigned int q = 0; q < arr.count; q++)
	{
		//If data[q] = target, replace data[q] with the next element in the array.
		if (arr.data[q] == target)
		{
			arr.data[q] = arr.data[arr.count - 1];
			arr.count--;		
			return true;
		}
		if (arr.count == 0)
		{
			return false;
		}
	}
	return false;
}

