#include "stack.h"


struct stack* createStack()
{
  struct stack *s = malloc(sizeof(struct stack));
  s->stk = createDLinkedList();
  return s;
}

//push item onto the stack
void pushStack(struct stack *s,struct leaf *dta)
{
  addFront(s->stk,dta);
}
//get item from top of stack
struct leaf* topStack(struct stack *s)
{
  return getFront(s->stk);
}
//pop item from the stack
void popStack(struct stack *s)
{
  removeFront(s->stk);
}
//test if stack is empty.  return 1 if empty and 0 is not
int isEmptyStack(struct stack *s)
{
  return isEmpty(s->stk);
}
//clean stack memory
void cleanStack(struct stack *s)
{
  while(!isEmptyStack(s))
    {
      popStack(s);
    }
  free(s->stk);
  free(s);
}

