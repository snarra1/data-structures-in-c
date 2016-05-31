#include "hw4.h"

		//getMax function definition
void getMax(struct input* ip, struct data* dtarray)
{
	int i, min, tmax;
	min=ip->array[dtarray->Start];	// stores the minimum no. in the array
	tmax=ip->array[dtarray->Start+1] - min;	//holds the maximum difference among the range of numbers
	for(i=dtarray->Start+1;i<= dtarray->End ;i++)	//range of search  [Start - End]
	{
		if(ip->array[i] - min > tmax)
		{
			tmax=ip->array[i]-min;	//holds temporary max difference
		}
		if(ip->array[i] < min)
		{
			min=ip->array[i];	//changes minimum no. if found
		}
	}
	dtarray->Max=tmax;	//updates the final maximum difference
}

		//findMax function definition
void findMax(struct data** dt, int size, struct input* ip)
{
	int i;		//calls getMax function for an array of pointers pointed by dt pointer
	for(i=0;i<size;i++)
	{
		getMax(ip, dt[i]);
	}
}
		//defining printData function
void printData(struct data** d, int dataSize)
{
	int i;		//prints the values of Start, End and Max for each pointer  in array
	for(i=0;i<dataSize;i++)
	{
		printf("\n %d   %d   %d",d[i]->Start,d[i]->End,d[i]->Max);
	}
	printf("\n\n");
}

		//generateData function definition
struct data* generateData(int startno, int endno)
{
		//allocating and assigning values to data structure
	struct data* dt = malloc(sizeof(struct data));
	dt->Start=startno;
	dt->End=endno;
	dt->Max=-99999;
	return dt;	//pointer to the structure with assigned values is returned
}

struct data** generateDataArray(int size)
{
	int i, start, end;
				//allocates space for pointer pointing other pointer
	struct data** dtarray=malloc(size*sizeof(struct data*));
	for(i=0;i<size;i++)
	{
			//gets random number between the range
		start=getRandBetween(0,size/2);
		end=getRandBetween(size/2,size);
		dtarray[i]=generateData(start,end);	//generateData function called
	//	printf("\n %p", dtarray[i]);
	//	printf(" s-%d c-%d",dtarray[i]->Start, dtarray[i]->End);

	}
	printf("\n");
	return dtarray;	//returns the double pointer
}
		//generateArray function definition
struct input* generateArray(int size)
{
	int i;
			//allocates space for variable of input structure
	struct input* ip = malloc(sizeof(struct input));
	ip->array=malloc(size * sizeof(int));	//allocating space for an array in input structure
	ip->size=size;
	for(i=0; i<size; i++)
	{
		ip->array[i]=getRand();		//calls getRand function to get random values
	//	printf(" %d",ip->array[i]);
	}
	printf("\n");
	return ip;	//returns pointer to input structure
}

		//freedtarray function definition
void freeallpointers(struct data** dtarray, int size, struct input* ip)
{
	int i;		//frees every pointer in dtarray
	for(i=0;i<size; i++)
	{
		free(dtarray[i]);
	}
	free(dtarray);	//frees the double pointer pointing the array of pointers
	free(ip->array);
	free(ip);
}
