CFLAGS = -Wall -g
CC = gcc

all : main

data.o : data.h data.c

dlinklist.o : dlinklist.h dlinklist.c

queue.o : queue.h queue.c

stack.o : stack.h stack.c

bst.o : bst.h bst.c

main.o : main.c

main : data.o dlinklist.o stack.o queue.o bst.o main.o

clean :
	rm -f *.o *~ main
