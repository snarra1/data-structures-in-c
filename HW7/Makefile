CFLAGS = -Wall -g
CC = gcc

all : main

data.o : data.h data.c

dlinklist.o : dlinklist.h dlinklist.c

stack.o : stack.h stack.c

queue.o : queue.h queue.c

main.o : main.c

main : data.o dlinklist.o stack.o queue.o main.o

clean:
	rm -f *.o *.~ main
