#ifndef STACK_H_
#define STACK_H_

#include <stdlib.h>
#include "structures.h"
#include "dlinklist.h"


//allocate stack
struct stack* createStack();
//push item onto the stack
void pushStack(struct stack *s,struct leaf *dta);
//get item from top of stack
struct leaf* topStack(struct stack *s);
//pop item from the stack
void popStack(struct stack *s);
//test if stack is empty.  return 1 if empty and 0 is not
int isEmptyStack(struct stack *s);
//clean stack memory
void cleanStack(struct stack *s);

#endif
