all : main

main : hw3.o main.o
	gcc -Wall hw3.o main.o -o main

main.o : main.c
	gcc -Wall -c main.c

hw3.o : hw3.h hw3.c
	gcc -Wall -c hw3.c

clean :
	rm -f *.o main
