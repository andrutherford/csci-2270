//Andrew Rutherford
//CSCI 2270
//Midterm #2
//Question 24

#include "bintree.h"
#include "binary_search_tree.h"
#include <iostream>

using namespace std;

int tree_sum_recursive(const binary_tree_node* root_ptr)
{
	//Using a signed int to ensure the sum is accurate if negative numbers are included
	int sum;
	
	//If there is no tree at all, the sum is zero
	if (root_ptr == NULL)
	{
		return 0;
	}
	else
	{
		//If the root_ptr exists as the sole node with out leaf nodes
		//The sum returned should be the value of root_ptr->data
		if (root_ptr->left == NULL && root_ptr->right == NULL)
		{
			return root_ptr->data;
		}
		//If there are leaf nodes, the sum starts as the first value
		//which is root_ptr->data
		sum = root_ptr->data;
		
		//Recursion of the left and right subtrees
		sum += tree_sum_recursive(root_ptr->left);
		sum += tree_sum_recursive(root_ptr->right);
		return sum;
	}
	
	
}

int tree_height_recursive(const binary_tree_node* root_ptr)
{
	//If the root_ptr is NULL the height of the tree is zero
	if (root_ptr == NULL)
	{
			return 0;
	}
	
	//If a left subtree does not exist, recursively call the height method
	//on the right subtree + 1
	else if (root_ptr->left == NULL)
	{
		return 1 + tree_height_recursive(root_ptr->right);
	}
	
	//If a right subtree does not exist, recursively call the height method
	//on the left subtree + 1
	else if (root_ptr->right == NULL)
	{
		return 1 + tree_height_recursive(root_ptr->left);
	}
	else
	//If the root_ptr, root_ptr->left, and root_ptr->right all != null
	//recursively call the height method on each subtree + 1
	{
		unsigned int left_height = tree_height_recursive(root_ptr->left);
		unsigned int right_height = tree_height_recursive(root_ptr->right);
		//If the left subtree has a larger height than the right subtree
		//return 1 + the height of the left subtree
		if (left_height > right_height)
		{
			return 1 + left_height;
		}
		//If the other way around is true, than return 1 + height of the right subtree
		else
		{
			return 1 + right_height;
		}
	}
		
}

int main()
{
	binary_tree_node* root_ptr1 = nullptr;  
	
	cout << "Empty tree " << endl;
	
	print(root_ptr1, 0);
	
	cout << "Sum of empty tree " << tree_sum_recursive(root_ptr1) << endl;
	cout << "Height of empty tree " << tree_height_recursive(root_ptr1) << endl;
	
	for (unsigned int k = 0; k < 20; ++k)
	{
		int number = rand() % 100;
		insert(root_ptr1, number);
	}
	
	print(root_ptr1, 0);
	
	cout << "Sum of random tree " << tree_sum_recursive(root_ptr1) << endl;
	cout << "Height of random tree " << tree_height_recursive(root_ptr1) << endl;
	
	tree_clear(root_ptr1);
	
	for (unsigned int k = 0; k < 10; ++k)
	{
		int number;
		cout << "Enter a number: ";
		cin >> number;
		insert(root_ptr1, number);
	}

	print(root_ptr1, 0);
	
	cout << "Sum of manually entered tree " << tree_sum_recursive(root_ptr1) << endl;
	cout << "Height of manually entered tree " << tree_height_recursive(root_ptr1) << endl;

	tree_clear(root_ptr1);			
}
