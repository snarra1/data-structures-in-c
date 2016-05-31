#include "dlinklist.h"
#include <stdlib.h>


struct stack
{
  struct dlinklist *stk;

};
//allocate stack
struct stack* createStack();
//push item onto the stack
void pushStack(struct stack *s,struct data *dta);
//get item from top of stack
struct data* topStack(struct stack *s);
//pop item from the stack
void popStack(struct stack *s);
//test if stack is empty.  return 1 if empty and 0 is not
int isEmptyStack(struct stack *s);
//print stack. 
void printStack(struct stack *s);
//get number of elements from stack
int sizeStack(struct stack *s);
//clean stack memory
void cleanStack(struct stack *s);
//convert roman no. to decimal no
int convertRomanNumeralStack(struct stack* s);
