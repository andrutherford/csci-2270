# All compilations occur with -Wall to print warnings, and -g to allow gdb debugging.
# The clean command uses rm to remove all expendable files (rm is part of
# the cs1300 compiler tools from www.cs.colorado.edu/~main/cs1300/README.html).

# define the different outputs of all g++ commands
# on Ubuntu, the .exe suffix disappears
EXPENDABLES = test_array_queue.o test_array_queue array_queue.o dynamic_size_array_unsorted.o

# make all is listed first, which lets you type "make" to recompile 
# anything that has changed in either your class, your test code, 
# or my test code.
all:
	@make $(EXPENDABLES)

# this compiles your test program and your stack class together
test_array_queue: test_array_queue.o array_queue.o dynamic_size_array_unsorted.o
	g++ -std=c++0x -Wall -g test_array_queue.o array_queue.o dynamic_size_array_unsorted.o -o test_array_queue 

# this compiles your test program, which is executable
array_queue.o: array_queue.cpp array_queue.h dynamic_size_array_unsorted.h
	g++ -std=c++0x -Wall -g -c array_queue.cpp -o array_queue.o

dynamic_size_array_unsorted.o: dynamic_size_array_unsorted.cpp dynamic_size_array_unsorted.h
	g++ -std=c++0x -Wall -g -c dynamic_size_array_unsorted.cpp -o dynamic_size_array_unsorted.o

# this compiles your test program, which is executable
test_array_queue.o: array_queue.h test_array_queue.cpp dynamic_size_array_unsorted.h
	g++ -std=c++0x -Wall -g -c test_array_queue.cpp -o test_array_queue.o

# this deletes all the output files
clean:
	rm $(EXPENDABLES)
