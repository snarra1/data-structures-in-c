#include "dlinklist.h"
#include <stdlib.h>


struct queue
{
  struct dlinklist* que;

};
//allocate queue
struct queue* createQueue();
//push item onto the queue
void pushQueue(struct queue* q,struct data* dta);
//push itemm in reverse manner
void reverseQueue(struct queue* q, struct data* dta);
//get item from top of queue
struct data* topQueue(struct queue* q);
//pop item from the queue
void popQueue(struct queue* q);
//test if queue is empty.  return 1 if empty and 0 is not
int isEmptyQueue(struct queue* q);
//print queue
void printQueue(struct queue* q);
//get number of elements from queue
int sizeQueue(struct queue* q);
//clean queue memory
void cleanQueue(struct queue* q);
//convert roman to decimal no. using queue
int convertRomanNumeralQueue(struct queue* q);
