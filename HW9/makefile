CFLAGS = -Wall -g
CC = gcc

all : main

data.o : data.h data.c

dlinklist.o : dlinklist.h dlinklist.c

random.o : random.h random.c

timing.o : timing.h timing.c

bst.o : bst.h bst.c

avl.o : avl.h avl.c

main.o : main.c

main : data.o dlinklist.o bst.o random.o timing.o avl.o main.o

clean :
	rm -f *.o *~ main
