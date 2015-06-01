test: tests.o binaryTree.o
	g++ -Wall -g -o tests tests.o binaryTree.o

%.o : %.c binaryTree.h
	g++ -Wall -g -c $<
