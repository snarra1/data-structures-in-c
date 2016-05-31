#ifndef HW4_H_	//if not defined hw4
#define HW4_H_	// define hw4

		//includes user defined and standard libraries
#include "random.h"
#include <stdio.h>
#include <stdlib.h>

		//user defined structure data declaration
struct data
{
	int Start;
	int End;
	int Max;
};
		//structure input declaration
struct input
{
	int* array;
	int size;
};
		//Function declarations

void freeallpointers(struct data** dtarray, int size, struct input* ip);

struct input* generateArray(int size);

struct data* generateData(int s, int e);

struct data** generateDataArray(int size);

void printData(struct data** d, int dataSize);

void getMax(struct input* ip, struct data* dtarray);

void findMax(struct data** dt, int size, struct input* ip);

		//ends if
#endif
