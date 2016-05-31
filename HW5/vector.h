#ifndef VECTOR_H_
#define VECTOR_H_

		//includes user defined library
#include "data.h"
		//includes standard libraries
#include <stdio.h>
#include <stdlib.h>

		//declaring user defined structure vector
struct vector
{
  int size;
  struct data **array;
};

		//declaring functions
void addBack(struct vector* vec, struct data* dta);
void removeFront(struct vector* vec);
float sumVector(struct vector* vec);
struct vector* cloneVector(struct vector* vec);
int compareVectors(struct vector* vec1, struct vector* vec2);
void reverseVector(struct vector* vec);
void cleanVector(struct vector* vec);
void addFront(struct vector* vec,struct data* dta);
void removeBack(struct vector* vec);
void printVector(struct vector* vec);
struct vector* createVector();
void freeData(struct data* dta);

#endif
