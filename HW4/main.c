#include "hw4.h"	//includes hw4.h

	//main function definition
int main()
{
	SeedRand(); //seeds the rand() with system time
	int size=6;
	struct input* ip = NULL;
	struct data** dt = NULL;

	ip=generateArray(size);	//input structure is generated and initialized
	dt=generateDataArray(size);	//generates and initializes data structure
	findMax(dt,size,ip);	//calls findMax function
	printData(dt,size);	//printData function called

				//frees the allocated space from the heap
	freeallpointers(dt,size,ip);
	return 0;	//successful termination of program
}
