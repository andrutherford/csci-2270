#include <cstdlib>
#include <iostream>
 
using namespace std;
 
//member function
void insertion_sort(int arr[], int length);
void print_array(int array[],int size);
 
int main() {
 
int array[10]= {9, 17, 2, 1, 21, 18, 25, 12, 50, 45};
insertion_sort(array,10);
 
 return 0;
}//end of main
 
void insertion_sort(int arr[], int length) {
	int i, j ,tmp;
	for (i = 1; i < length; i++) 
	{
		j = i;
		while (j > 0 && arr[j - 1] > arr[j]) 
		//Reverse Order: while (j > 0 && arr[j - 1] < arr[j]) 
		{
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
			j--;
			}//end of while loop
		print_array(arr,10);
	}//end of for loop
 }//end of insertion_sort.
 
void print_array(int array[], int size){
 
 cout<< "sorting: ";
 int j;
 for (j=0; j<size;j++)
 for (j=0; j<size;j++)
 cout <<" "<< array[j];
 cout << endl;
 }//end of print_array
