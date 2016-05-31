all : main

data.o : data.h data.c
	gcc -Wall -g -c data.c

vector.o : vector.h vector.c
	gcc -Wall -g -c vector.c

main.o : main.c
	gcc -Wall -g -c main.c

main : data.o vector.o main.o
	gcc -Wall -g data.o vector.o main.o -o main

clean:
	rm *.o main
