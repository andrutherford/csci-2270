//Andrew Rutherford
//CSCI 2270

#include <cctype>          // Provides toupper
#include <iostream>        // Provides cout and cin
#include <cstdlib>         // Provides EXIT_SUCCESS
#include <string>
using namespace std;


// PROTOTYPES for functions used by this test program:
void pattern(ostream& outs, unsigned int n, unsigned int i, unsigned int z);

int main()
{
  int i2;
  cout << "Enter an integer (a power of 2): ";
  cin >> i2;
  pattern(cout, i2, 0, 0);
  return (EXIT_SUCCESS);
}

// i is the offset
// n is the asterisks
void pattern(ostream& outs, unsigned int n, unsigned int i, unsigned int z)
{
	//Base case
	if (n == 0)
	{
		return;
	}
	
	pattern(outs, n/2, i, z++);
	
	//Print spaces
	for (unsigned int a = 0; a < i; a++)
	{
		outs << "  ";
	}
	
	//Print stars
	for  (unsigned int b = 0; b < n; b++) 
	{
		outs << " *";
	}
	
	cout << endl;
	
	pattern(outs, n/2, i+(n/2), z++);
	cout << endl;
	cout <<"z = " << z << endl;
	return;
		
}

