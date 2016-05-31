#include "vector.h"		//includes user defined directive

		//function definition for reverseVector
void reverseVector(struct vector* vec)
{
	struct data* tempI=NULL;		//points to the ith element
	int size=vec->size, i=0, j=size-1;
	while(i < size/2)				//checks half the array elements
	{
					//swaps the ith and (size-i)th element
		tempI=vec->array[i];
		vec->array[i]=vec->array[j];
		vec->array[j]=tempI;
		i++;	//increment i and decrement j
		j--;
	}
			//assigning NULL to pointer
	tempI=NULL;
}

		//compareVectors function definition
int compareVectors(struct vector* vec1, struct vector* vec2)
{
	int i=0, flag=0;
			//checks if size of both vectors is equal
	if(vec1->size==vec2->size)
	{
		i=0;
		while(i < vec1->size)
		{
				//compares Data of both vectors
			flag=compareData(vec1->array[i],vec1->array[i]);
			if(flag==1)
			{
				i++;	//if data is equal then continue
			}
			else
			{	//return 0 if data of the vectors is not equal
				return 0;
			}
		}
		return 1;	//return 1 if vectors are equal
	}
	else
	{
		return 0;	//return 0 if sizes of both vectors is not equal
	}

}

		//function definition of cloneVector
struct vector* cloneVector(struct vector* vec)
{
	int i=0;
	float v1, v2;
			//allocate space for new vector and assign values
	struct vector* tempVec=malloc(sizeof(struct vector));
	tempVec->size=vec->size;
	tempVec->array=malloc(vec->size* sizeof(struct data*));
	while( i < tempVec->size)
	{
		v1=(vec->array[i])->v1;		//stores temporary data v1 of ith element of the vector
		v2=(vec->array[i])->v2;		//stores temporary data v2 of ith element of thr vector
		tempVec->array[i]=createData(v1,v2);	//create new data and assign it to pointer
		i++;
	}
	return tempVec;	//return the new clone vector
}

		//addFront function definition
void addFront(struct vector *vec, struct data *dta)
{
	struct data** temp;
	int i;
	vec->size++;			//increments vector size to add element to the array
	temp=vec->array;		//pointing temporary pointer to the array
	vec->array=malloc(vec->size* sizeof(struct data*));	//allocating new memory of new size
	vec->array[0]=dta;		//allocating data to the array's 0th element
	for(i=1;i< vec->size;i++)
	{
		vec->array[i]=temp[i-1];	//copy other elements
	}
	free(temp);			//free the memory of temporary pointer
}

		//removeFront function definition
void removeFront(struct vector *vec)
{
	struct data** temp;
	int i;
	vec->size--;			//decrementing vector size
	temp=vec->array;		//temporary pointer
	free(temp[0]);			//deallocating the 0th element
	vec->array=malloc(vec->size* sizeof(struct data*));	//holds the address of array
	for(i=0;i< vec->size;i++)
	{
		vec->array[i]=temp[i+1];	//copies other elements
	}
	free(temp);			//deallocates the temp pointer
}

		//addBack function definition
void addBack(struct vector* vec, struct data* dta)
{
	struct data** temp = NULL;
	int i=0;			//adds element to the back of the array
	vec->size++;
	temp=vec->array;		//temporary pointer
	vec->array=malloc(vec->size* sizeof(struct data ));	//reallocating size
	for(i=0;i< vec->size-1; i++)
	{
		vec->array[i]=temp[i];		//copying old elements
	}
	vec->array[vec->size-1]=dta;	//assigning data pointer to the double pointer
	free(temp);			//frees the pointer
}

		//removeBack function definition
void removeBack(struct vector *vec)
{
		//removes element from the back of the array
	struct data** temp;
	int i=0;
	temp=vec->array;		//temporary pointer pointing to vector's array
	vec->size--;			//decrements the array size of vector
	vec->array=malloc(vec->size * sizeof(struct data*));	//resizing the array
	for(i=0;i< vec->size; i++)
	{
		vec->array[i]=temp[i];	//copies the data of array
	}
	free(temp[vec->size]);		//frees the last element
	free(temp);			//deallocates the temporary pointer

}

		//defining sumVector function
float sumVector(struct vector* vec)
{
	int j=0;
	float fsum=0;			//holds float sum of data elements in the array of vector
	for(j=0; j< vec->size; j++)
	{
		fsum=fsum+sumData(vec->array[j]);	//calls sumData of data directive
	}
	return fsum;		//returns the sum
}

		//cleanVector function definition
void cleanVector(struct vector *vec)
{
	int k=0;		//deallocates the pointers to data structure
	while(k < vec->size)
	{
		freeData(vec->array[k]);	//calls the freeData function
		k++;
	}
	free(vec->array);	//frees the pointer to the array
	free(vec);		//frees the pointer to the pointer
}

		//defining printVector
void printVector(struct vector *vec)
{
	int i=0;
			//prints the data in the array
	while(i < vec->size)
	{
		printData(vec->array[i]);
		i++;
	}
	printf("\n");
}

		//createVector function definition
struct vector* createVector()
{
		//Allocates memory to pointer of type vector
	struct vector* vec=malloc(sizeof(struct vector));
	vec->size=0;
	vec->array=NULL;
	return vec;
}

		//freeData function definition
void freeData(struct data* dta)
{
	free(dta);	//frees the memory allocated to the pointer
}
