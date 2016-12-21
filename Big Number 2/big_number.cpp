//Andrew Rutherford
//CSCI 2270
//Homework 1
//Part 1


#include "big_number.h"

using namespace std;

// default constructor, creates a 0
big_number::big_number()
{
	head_ptr = tail_ptr = 0;
	add_node(head_ptr, tail_ptr, '1');
	positive = true;
	base = 10;
	digits = 1;
}

// int constructor; create big_number from base 10 integer
big_number::big_number(int i)
{
	head_ptr = tail_ptr = 0;
	digits = 0;
	if (i == 0)
	{
		big_number zero;
		*this = zero;
	}
	else
	{
		if (i < 0)
		{
			positive = false;
			i *= -1;
		}
		else
		{
			positive = true;
		}
		while (i > 0)
		{
			if (head_ptr != nullptr)
			{
				head_ptr -> prev = new node;
				head_ptr -> prev -> data = (i % 10) + '0';
				head_ptr -> prev -> next = head_ptr;
				head_ptr = head_ptr -> prev;
			}
			else
			{
				head_ptr = new node;
				head_ptr -> data = (i % 10) + '0';
				tail_ptr = head_ptr;
				head_ptr -> prev = nullptr;
				head_ptr -> next = nullptr;
			}
			++ digits;
			i /= 10;
		}
	}
}

// copy constructor, creates a deep copy of m
big_number::big_number(const big_number& m)
{
	positive = m.positive;
	base = m.base;
	digits = m.digits;
	copy_list(m.head_ptr,  head_ptr, tail_ptr);
}

// create a big_number from a string
big_number::big_number(const string& s, unsigned int b)
{
	digits = 0;
	unsigned int index = 0;
	positive = true;
	if (s[0] == '-')
	{
		positive = false;
		++index;
	}
	if (s[0] == '+')
	{
		++index;
	}
	
	head_ptr = new node;
	head_ptr -> data = s[index++];
	head_ptr -> next = nullptr;
	head_ptr -> prev = nullptr;
	tail_ptr = head_ptr;
	
	while (index < s.length())
	{
		//node* cursor = head_ptr;
		tail_ptr -> next = new node;
		tail_ptr -> next -> data = s[index++];
		tail_ptr -> next -> next = nullptr;
		tail_ptr -> next -> prev = tail_ptr;
		tail_ptr = tail_ptr -> next;
		++digits;
	}
}

// destructor
big_number::~big_number()
{
	
}

// assignment operator
big_number& big_number::operator=(const big_number& m)
{
	//big_number copy = big_number(m);
	digits = m.digits;
	base = m.base;
	positive = m.positive;
	copy_list(m.head_ptr,  head_ptr, tail_ptr);
	return *this;
}

// set value to original value + b; return answer in original number's base
big_number& big_number::operator+= (const big_number& b)
{
	return *this;
}

// set value to original value * b; return answer in original number's base
big_number& big_number::operator*= (const big_number& b)
{
	
	return *this;
}

// set value to original value - b; return answer in original number's base
big_number& big_number::operator-= (const big_number& b)
{
	return *this;
}

// set value to original value / b; return answer in original number's base
big_number& big_number::operator/= (const big_number& b)
{
	return *this;
}

// set value to original value * b; return answer in original number's base
big_number& big_number::operator%= (const big_number& b)
{
	return *this;
}

// prefix increment
big_number& big_number::operator++()
{
	return *this;
}

// prefix decrement
big_number& big_number::operator--()
{
	return *this;
}

bool operator >(const big_number& a, const big_number& b)
{
	node* cursor_a = a.head_ptr;
	node* cursor_b = b.head_ptr;
	if (cursor_a->data > cursor_b->data)
	{
		return true;
	}
	if (cursor_a->data < cursor_b->data)
	{
		return false;
	}
	while(cursor_a->data == cursor_b->data)
	{
		cursor_a = cursor_a->next;
		cursor_b = cursor_b->next;
		if (cursor_a->data > cursor_b->data)
		{
			return true;
		}
		if (cursor_a->data < cursor_b->data)
		{
			return false;
		}
		if (cursor_a->next == nullptr && cursor_b->next != nullptr)
		{
			return false;
		}
		if (cursor_b->next == nullptr && cursor_a->next != nullptr)
		{
			return true;
		}
	}

	return false;
}

bool operator >=(const big_number& a, const big_number& b)
{
	node* cursor_a = a.head_ptr;
	node* cursor_b = b.head_ptr;
	if (cursor_a->data > cursor_b->data)
	{
		return true;
	}
	if (cursor_a->data < cursor_b->data)
	{
		return false;
	}
	while(cursor_a->data == cursor_b->data)
	{
		cursor_a = cursor_a->next;
		cursor_b = cursor_b->next;
		if (cursor_a->data > cursor_b->data)
		{
			return true;
		}
		if (cursor_a->data < cursor_b->data)
		{
			return false;
		}
		if (cursor_a->next == nullptr && cursor_b->next != nullptr)
		{
			return false;
		}
		if (cursor_b->next == nullptr && cursor_a->next != nullptr)
		{
			return true;
		}
		if (cursor_a->next == nullptr && cursor_b->next == nullptr && cursor_a->data == cursor_b->data)
		{
			return true;
		}
	}
	return false;
}

bool operator <(const big_number& a, const big_number& b)
{
	node* cursor_a = a.head_ptr;
	node* cursor_b = b.head_ptr;
	if (cursor_a->data > cursor_b->data)
	{
		return false;
	}
	if (cursor_a->data < cursor_b->data)
	{
		return true;
	}
	while(cursor_a->data == cursor_b->data)
	{
		cursor_a = cursor_a->next;
		cursor_b = cursor_b->next;
		if (cursor_a->data > cursor_b->data)
		{
			return false;
		}
		if (cursor_a->data < cursor_b->data)
		{
			return true;
		}
		if (cursor_a->next == nullptr && cursor_b->next != nullptr)
		{
			return true;
		}
		if (cursor_b->next == nullptr && cursor_a->next != nullptr)
		{
			return false;
		}
	}

	return false;
}
			
bool operator <=(const big_number& a, const big_number& b)
{
	node* cursor_a = a.head_ptr;
	node* cursor_b = b.head_ptr;
	if (cursor_a->data > cursor_b->data)
	{
		return false;
	}
	if (cursor_a->data < cursor_b->data)
	{
		return true;
	}
	while(cursor_a->data == cursor_b->data)
	{
		cursor_a = cursor_a->next;
		cursor_b = cursor_b->next;
		if (cursor_a->data > cursor_b->data)
		{
			return false;
		}
		if (cursor_a->data < cursor_b->data)
		{
			return true;
		}
		if (cursor_a->next == nullptr && cursor_b->next != nullptr)
		{
			return true;
		}
		if (cursor_b->next == nullptr && cursor_a->next != nullptr)
		{
			return false;
		}
		if (cursor_a->next == nullptr && cursor_b->next == nullptr && cursor_a->data == cursor_b->data)
		{
			return true;
		}
	}
	return false;
}
			
bool operator==(const big_number& a, const big_number& b)
{
	node* cursor_a = a.head_ptr;
	node* cursor_b = b.head_ptr;
	if(cursor_a->data != cursor_b->data)
	{
		return false;
	}
	while(cursor_a->next != nullptr || cursor_b->next != nullptr)
	{
		cursor_a = cursor_a->next;
		cursor_b = cursor_b->next;
		if (cursor_a->data != cursor_b->data)
		{
			return false;
		}
	}
	return true;
}
	
bool operator!=(const big_number& a, const big_number& b)
{
	node* cursor_a = a.head_ptr;
	node* cursor_b = b.head_ptr;
	if(cursor_a->data != cursor_b->data)
	{
		return true;
	}
	while(cursor_a->next != nullptr || cursor_b->next != nullptr)
	{
		cursor_a = cursor_a->next;
		cursor_b = cursor_b->next;
		if (cursor_a->data != cursor_b->data)
		{
			return true;
		}
	}
	return false;
}

ostream& operator <<(ostream& out, const big_number& n)
{
	print_list(n.head_ptr);
	return out;
}

istream& operator >>(istream& in, big_number& n)
{
	return in;
}

big_number operator+(const big_number& a, const big_number& b)
{
	big_number answer;
	return answer;
}

big_number operator-(const big_number& a, const big_number& b)
{
	big_number answer;
	return answer;
}

big_number operator*(const big_number& a, const big_number& b)
{
	big_number answer;
	return answer;
}

big_number operator/(const big_number& a, const big_number& b)
{
	big_number answer;
	return answer;
}

big_number operator%(const big_number& a, const big_number& b)
{
	big_number answer;
	return answer;
}

big_number factorial(const big_number& a)
{
	big_number answer;
	return answer;
}


