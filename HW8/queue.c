#include "queue.h"


struct queue* createQueue()
{
  struct queue *q = malloc(sizeof(struct queue));
  q->que = createDLinkedList();
  return q;

}


void pushQueue(struct queue *q,struct leaf *lf)
{
  addBack(q->que,lf);
}

struct leaf* topQueue(struct queue *q)
{
  return getFront(q->que);
}
void popQueue(struct queue *q)
{
  removeFront(q->que);
}

int isEmptyQueue(struct queue *q)
{
  return isEmpty(q->que);
}

void cleanQueue(struct queue *q)
{
  while(!isEmptyQueue(q))
    {
      popQueue(q);
    }
  free(q->que);
  free(q);
}
