#include <iostream>
#include "dynamic_size_array_unsorted.h"

struct array_queue {
	int_array arr;
	unsigned int front;
	unsigned int back;
};

void init(array_queue& que);

void destr(array_queue& que);

void clear(array_queue& que);

void add(array_queue& que, const int& payload);

void remove(array_queue& que);

int front(const array_queue& que);

bool empty(const array_queue& que);

void print(const array_queue& que);

