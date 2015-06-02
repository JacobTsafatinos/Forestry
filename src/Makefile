tests: test
	./test

test: tests.o binaryTree.o
	g++ -Wall -g -o test tests.o binaryTree.o

%.o: %.c binaryTree.h
	g++ -Wall -g -c $<

clean:
	rm test
