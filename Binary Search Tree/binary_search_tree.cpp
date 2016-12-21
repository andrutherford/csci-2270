#include <cassert>
#include <cstdlib>
#include "binary_search_tree.h"
#include <iostream>
//#include "bintree.h"

	void bst_remove_max(binary_tree_node*& root_ptr, int& removed)
	// Precondition: root_ptr is a root pointer of a non-empty binary 
	// search tree.
	// Postcondition: The largest item in the binary search tree has been
	// removed, and root_ptr now points to the root of the new (smaller) 
	// binary search tree. The reference parameter, removed, has been set 
	// to a copy of the removed item.
	{

	}

	bool bst_remove(binary_tree_node*& root_ptr, const int& target)
	// Precondition: root_ptr is a root pointer of a binary search tree 
	// or may be nullptr for an empty tree).
	// Postcondition: If target was in the tree, then one copy of target
	// has been removed, and root_ptr now points to the root of the new 
	// (smaller) binary search tree. In this case the function returns true.
	// If target was not in the tree, then the tree is unchanged (and the
	// function returns false).
	{
		return true;
	}

	unsigned int bst_remove_all(binary_tree_node*& root_ptr, const int& target)
	// Precondition: root_ptr is a root pointer of a binary search tree 
	// or may be nullptr for an empty tree).
	// Postcondition: All copies of target have been removed from the tree
	// has been removed, and root_ptr now points to the root of the new 
	// (smaller) binary search tree. The return value tells how many copies
	// of the target were removed.
	{
		return 0;
	}

    void init(binary_tree_node*& root_ptr)
	{
		root_ptr = nullptr;
	}
	
	void init(binary_tree_node*& root_ptr, const binary_tree_node* source_root_ptr)
	// Library facilities used: bintree.h
	{
		root_ptr = nullptr;
	}

	void destr(binary_tree_node*& root_ptr)
	// Header file used: bintree.h
	{
	
	}

	binary_tree_node* binary_search_tree_copy(const binary_tree_node* source_root_ptr)
	{
		binary_tree_node* n = nullptr;
		return n;
	}
	
	unsigned int size(const binary_tree_node* root_ptr)
	// Header file used: bintree.h
	{
		if (root_ptr == NULL)
		{
			return 0;
		}
		else
			return (1 + size(root_ptr->left) + size(root_ptr->right));
	}

	void insert(binary_tree_node*& root_ptr, const int& entry)
	// Header file used: bintree.h
	{
		if( root_ptr == NULL ) 
		{
			
			root_ptr = new binary_tree_node();
			root_ptr->data = entry;
			//root_ptr->left=NULL;
			//root_ptr->right=NULL;
			std::cout << "ENTRY ADDED TO ROOT" << std::endl;
			return;
			
		}
		if( root_ptr->data > entry )
		{
			std::cout << "check1" << std::endl;
			insert( root_ptr->left, entry );
			
		
			/*if (root_ptr->left == NULL)
			{
				std::cout << "ENTRY ADDED TO LEFT" << std::endl; 
				root_ptr->left->data = entry;
			}*/
		}
				
		else
		{
			std::cout << "check2" << std::endl;
			insert( root_ptr->right, entry ); 
			
			/*if (root_ptr->right == NULL)
			{
				std::cout << "ENTRY ADDED TO RIGHT" << std::endl; 
				root_ptr->right->data = entry;
			}*/
		}
		
	}

    unsigned int frequency(const binary_tree_node* root_ptr, const int& target)
	{
		unsigned int freq=0;
		if (root_ptr == NULL)
		{
			return freq;
		}
		if (root_ptr != NULL)
		{
			if (root_ptr->data == target)
			{
				freq++;
			}				
			frequency(root_ptr->left, target);
			frequency(root_ptr->right, target);
			
			
		}
		return freq;
	}

	unsigned int erase(binary_tree_node*& root_ptr, const int& target)
	{
		return 0;
	}

	bool erase_one(binary_tree_node*& root_ptr, const int& target)
	{
		return false;
	}

	void combine(binary_tree_node*& root_ptr, const binary_tree_node* addend_root_ptr)
	{

	}

	binary_tree_node* add(const binary_tree_node* b1, const binary_tree_node* b2)
	{
		binary_tree_node* answer = nullptr;
		return answer;
	}

	void insert_all(binary_tree_node*& root_ptr, const binary_tree_node* addroot_ptr)
        // Precondition: addroot_ptr is the root pointer of a binary search tree that
        // is separate from the binary search tree that activated this
        // method.
        // Postcondition: All the items from the addroot_ptr's binary search tree
        // have been added to the binary search tree that activated this
        // method.
	{
		
	}
