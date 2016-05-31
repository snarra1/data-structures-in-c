#include "stack.h"
#include "data.h"

	//convertRomanNumeralStack function definition
int convertRomanNumeralStack(struct stack* s)
{
	int sum=0, romanVal=0, prevVal=0, maxVal=0;
//	int serialcnt=0;
	struct stack* s1=createStack();
	for(sum=0;!isEmptyStack(s);)
	{
		struct data* dta=topStack(s);	//gets the top elememt in the stack
		switch(dta->numeral)		//calculates the decimal value of the roman number
		{
			case 'I':
				romanVal=1;
				break;
			case 'V':
				romanVal=5;
				break;
			case 'X':
				romanVal=10;
				break;
			case 'L':
				romanVal=50;
				break;
			case 'C':
				romanVal=100;
				break;
			case 'D':
				romanVal=500;
				break;
			case 'M':
				romanVal=1000;
				break;
			default:
				break;
		}			//evaluates the decimal conversion
		if(romanVal>prevVal && romanVal>=maxVal)
		{
			maxVal=romanVal;
		}
		if(maxVal>romanVal)
		{
			sum=sum-romanVal;;
		}
		else
		{
			sum=sum+romanVal;
		}
		prevVal=romanVal;
		pushStack(s1,createDataNumeral(dta->numeral));
		popStack(s);
	}
	while(!isEmptyStack(s1))
	{
		struct data* dta=topStack(s1);
		pushStack(s,createDataNumeral(dta->numeral));
		popStack(s1);
	}
	cleanStack(s1);
	return sum;
}

	//cleanStack function definition
void cleanStack(struct stack *s)
{
	while(!isEmptyStack(s))
	{
		popStack(s);	//removes the topmost element
	}
	free(s->stk);	//deallocates memory
	free(s);
}

	//sizeStack function definition
int sizeStack(struct stack *s)
{
	int size;
	struct stack* s1=createStack();
	for(size=0;!isEmptyStack(s);size++)	//calculates the no of elements (size of stack)
	{
		struct data* dta=topStack(s);
		pushStack(s1,createDataNumeral(dta->numeral));
		popStack(s);
	}
	for(;!isEmptyStack(s1);)
	{
		struct data* dta=topStack(s1);
		pushStack(s,createDataNumeral(dta->numeral));
		popStack(s1);
	}
	cleanStack(s1);
	return size;
}

	//printStack function definition
void printStack(struct stack *s)
{
	struct stack* s1=createStack();
	while(!isEmptyStack(s))
	{
		struct data* dta=topStack(s);
		printData(dta);
		pushStack(s1,createDataNumeral(dta->numeral));
		popStack(s);
	}
	while(!isEmptyStack(s1))
	{

		struct data* dta=topStack(s1);
		pushStack(s,createDataNumeral(dta->numeral));
		popStack(s1);
	}
	cleanStack(s1);		//frees the temporary stack
}

	//get item from top of stack
struct data* topStack(struct stack *s)
{
	return getFront(s->stk);	//gets the topmost element
}

	//isEmptyStack function
int isEmptyStack(struct stack *s)
{
	return isEmpty(s->stk);	//checks if stack is empty
}

	//popStack function
void popStack(struct stack *s)
{
	removeFront(s->stk);	//removes the front elememt
}

	//pushStack function definition
void pushStack(struct stack *s,struct data *dta)
{
	addFront(s->stk,dta);	//adds element on the front side
}

	//createStack function definition
struct stack* createStack()
{
	struct stack *s = malloc(sizeof(struct stack));
	s->stk = createDLinkedList();
	return s;
}
