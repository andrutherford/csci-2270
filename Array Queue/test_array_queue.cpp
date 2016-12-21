#include "array_queue.h"

using namespace std;


int main()
{
	array_queue arr_que;
	int num;
	
	init(arr_que);
	
	
	char choice;
	do 
	{
		cout << "Enter 'a' to add to queue, 'r' to remove or 'q' to quit: ";
		cin >> choice;
		if (choice == 'a' || choice == 'A')
		{
			cout << "Enter a number to add: ";
			cin >> num;
			add(arr_que, num);
			print(arr_que);
		}
	
		if (choice == 'r' || choice == 'R')
		{
			cout << "removing " << front(que_arr) << endl;
			remove(arr_que);
			print(arr_que);
		}
		
	} while (choice != 'q' && choice != 'Q');
	
	
}

