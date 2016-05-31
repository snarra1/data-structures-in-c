#ifndef QUEUE_H_
#define QUEUE_H_


#include <stdlib.h>
#include "structures.h"
#include "dlinklist.h"

//allocate queue
struct queue* createQueue();
//push item onto the queue
void pushQueue(struct queue *q,struct leaf *lf);
//get item from top of queue
struct leaf* topQueue(struct queue *q);
//pop item from the queue
void popQueue(struct queue *q);
//test if queue is empty.  return 1 if empty and 0 is not
int isEmptyQueue(struct queue *q);
//free all memory in queue
void cleanQueue(struct queue *q);

#endif 
