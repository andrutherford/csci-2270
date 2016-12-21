#include <iostream>

using namespace std;

bool binary_contains1(const int* arr, unsigned int first,
                      unsigned int last, int target)
{
    //Print out all elements in array
    cout << endl;
    for (unsigned int i = first; i <= last; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    unsigned int half;
    unsigned int length = last - first + 1;
    
    //Determine what the middle element will be
    if (length % 2 == 0)
        half = ((last - first) / 2) + 1;
    else
        half = (last - first) / 2;
    
    //Out put the first value, last value, array length, and the half value
    cout << "First: " << first << " -> " << arr[first] << endl;
    cout << "Last: " << last << " -> " << arr[last] << endl;
    cout << "Array Length: " << length << endl;
    cout << "Half element is " << half << " -> " << arr[first + half] << endl;
    cout << endl;
    
    //This is so the right value of half is used in recursion.
    half = first + half;
    
    //Base Cases
    if (arr[half] == target)
    {
        cout << "found!" << endl;
        return true;
    }
    if ((last - first) < 2)
    {
        cout << "not found!" << endl;
        return false;
    }
    
    //If target < arr[half]
    //Send in the array
    //The first value doesn't change
    //The last value becomes the half value
    if (arr[half] > target)
    {
        binary_contains1(arr, first, half, target);
    }
    
    
    //If target > arr[half]
    //Send in the array
    //The first value becomes the half value
    //The last value doesn't change
    if (arr[half] < target)
    {
        binary_contains1(arr, half, last, target);
    }

    return 0;

}

bool binary_contains2(const int* arr, unsigned int size, int target)
{
    return false;
}

int main()
{
    int target;
    int array[10] = {1, 6, 17, 22, 24, 26, 27, 35, 51, 98};
    for (unsigned int k = 0; k < 10; ++k)
        cout << array[k] << " ";
    cout << endl;
    cout << "Enter a number to search for: ";
    cin >> target;
    if (binary_contains1(array, 0, 9, target))
        cout << "target " << target << " found" << endl;
    else
        cout << "target " << target << " not found" << endl;
    //	if (binary_contains2(array, 10, target))
    //		cout << "target " << target << " found" << endl;
    //	else
    //		cout << "target " << target << " not found" << endl;
    
}
