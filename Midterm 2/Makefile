EXPENDABLES = question24.o question24 bintree.o 

all:
	@make $(EXPENDABLES)

bintree.o: bintree.cpp bintree.h
	g++ -Wall -std=c++0x -g -c bintree.cpp -o bintree.o

# this compiles your test program and your binary_search_tree classes together
question24: question24.o binary_search_tree.o bintree.o
	g++ -Wall -std=c++0x -g question24.o bintree.o binary_search_tree.o -o question24

question24.o: binary_search_tree.h binary_search_tree.o bintree.h question24.cpp
	g++ -Wall -std=c++0x -g -c question24.cpp -o question24.o

# this deletes all the output files
clean:
	rm $(EXPENDABLES)
