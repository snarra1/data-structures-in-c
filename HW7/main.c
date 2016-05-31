#include "queue.h"
#include "stack.h"

int main(int argc, char* argv[])
{
        if(argc == 1)
	{
		exit(0);
	}
	int i=0;
	char* ptr=argv[1];
	struct stack* s=createStack();
	struct queue* q=createQueue();
	while(ptr[i]!='\0')
	{
		pushStack(s,createDataNumeral(ptr[i]));
		pushQueue(q,createDataNumeral(ptr[i]));
		i++;
	}
	printf("\n Stack : \n");
	printStack(s);
	i=sizeStack(s);
	printf("\nSize : %d\n",i);
	i=isEmptyStack(s);
	printf("\n %d\n\n",i);
	i=convertRomanNumeralStack(s);
	printf("\n %d \n\n",i);

	printf("\n Queue : \n");
	printQueue(q);
	i=sizeQueue(q);
	printf("\nSize : %d\n",i);
	i=isEmptyQueue(q);
	printf("\n %d\n\n",i);
	i=convertRomanNumeralQueue(q);
	printf("\n %d \n\n",i);

	cleanStack(s);
	cleanQueue(q);
	return 0;
}
