#include "terrible_dynamic_size_array_unsorted.h"

using namespace std;


int main()
{
	int_array arr;
	int num;
	
	init(arr);
	
	for (unsigned int i = 0; i < 5; ++i)
	{
		cout << "Enter a number to add: ";
		cin >> num;
		add(arr, num);
		print(arr);
	}
	
	for (unsigned int i = 0; i < 5; ++i)
	{
		cout << "Enter a number to remove: ";
		cin >> num;
		remove(arr, num);
		print(arr);
	}
	
	cout << "Search array for what value? ";
	cin >> num;
	cout << endl;
	contains(arr, num);
	
	destr(arr);
}
