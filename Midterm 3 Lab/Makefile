# All compilations occur with -Wall to print warnings, and -g to allow gdb debugging.
# The clean command uses rm to remove all expendable files (rm is part of
# the cs1300 compiler tools from www.cs.colorado.edu/~main/cs1300/README.html).

# define the different outputs of all g++ commands
# on Ubuntu, the .exe suffix disappears
EXPENDABLES = question13.o question13

# make all is listed first, which lets you type "make" to recompile 
# anything that has changed in either your class, your test code, 
# or my test code.
all:
	@make $(EXPENDABLES)

# this compiles your test program and your dynamic_size_array_unsorted class together
question13: question13.o heapsort-reheapify-down.o
	g++ -std=c++0x -Wall -g question13.o heapsort-reheapify-down.o -o question13 

# this compiles your test program, which is executable
question13.o: question13.cpp
	g++ -std=c++0x -Wall -g -c question13.cpp -o question13.o

# this deletes all the output files
clean:
	rm $(EXPENDABLES)
