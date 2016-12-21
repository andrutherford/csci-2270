//Andrew Rutherford
//CSCI 2270

#include <cstdlib>    // Provides EXIT_SUCCESS, unsigned int
#include <iostream>
#include <algorithm>

using namespace std;

void reheapify_down(int* data, unsigned int n);

unsigned int left_child(unsigned int k)
{
	return (2*k + 1);
}

unsigned int right_child(unsigned int k)
{
	return (2*k + 2);
}

unsigned int parent(unsigned int k)
{
	return (2*k);
}

void make_heap(int* data, unsigned int n)
{
	unsigned int i, k;
    int x;
    unsigned int y;
    unsigned int z;
    
    //Insert data into appropriate sub tree
	for (i = 1 ; i < n ; i++)
	{
		int val = data[i] ;
		unsigned int b = i ;
		int c = ( b - 1 ) / 2 ;
		while ( b > 0 && data[c] < val )
		{
			data[b] = data[c] ;
			b = c ;
			c = ( b - 1 ) / 2 ;
		}
		data[b] = val ;
	}
    
    //Find right most sub tree's parent
    for(i = n/2; i > 0; i--) 
    {
        k = i;
        x = data[k];        
        y = 0;
        
        //check whether the array is already heapified
        while( !y && 2*k <= n) 
        {
            z = 2 * k;
            
            //check whether the sub tree has 2 children
            if(z < n)          
            {
				//z is greater node between sub trees
                if(data[z] < data[z+1])
                {
					z++; 
				} 
            }
            //If parent of subtree is greater than or equal to z, no change needed
            if (x >= data[z])
            {  
                y = 1;
			}
			
			//Else, swap child and parent
            else               
            {
                data[k] = data[z]; 
                k = z;
            }
        }
        data[k]=x;
    }
}

void heapsort(int* data, unsigned int n)
// Library facilities used: stdlib.h
{
    unsigned int unsorted = n;

    make_heap(data, n);

    while (unsorted > 1)
    {
		--unsorted;
		swap(data[0], data[unsorted]);
		reheapify_down(data, unsorted);
    }
}

int main( )
{
    const unsigned int N = 3000000;
    const int MANY_TESTS = 10;
    unsigned int i;
    int test;

	
    for (test = 0; test < MANY_TESTS; test++)
    {
		int* data = new int[N];
		cout << test << endl;
		for (i = 0; i < N; i++) data[i] = rand( );
		heapsort(data, N);
		bool sorted = true;
		for (i = 0; i < N - 1; ++i)
		{
			if (data[i] > data[i + 1])
			sorted = false;
		}
		if (!sorted)
			cout << "not sorted" << endl;

		delete [] data;
    }

    return 0;
}
    
