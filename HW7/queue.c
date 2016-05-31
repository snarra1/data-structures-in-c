 #include "queue.h"

	//convertRomanNumeralQueue function definition
int convertRomanNumeralQueue(struct queue* q)
{
	int sum=0, romanVal=0, prevVal=0, maxVal=0;
	struct queue* qtmp=createQueue();
	while(!isEmptyQueue(q))
	{
		struct data* dta=topQueue(q);
		reverseQueue(qtmp,createDataNumeral(dta->numeral));	//reverseQueue function called to reverse the elements
		popQueue(q);
	}
	for(sum=0;!isEmptyQueue(qtmp);)	//computes till queue is not empty
	{
		struct data* d=topQueue(qtmp);
		switch(d->numeral)		//calculates the values of roman numbers
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
		}			//comparing the previous and current numbers
		if(romanVal>prevVal && romanVal>maxVal)
		{
			maxVal=romanVal;
		}
		if(maxVal>romanVal)
		{
			sum=sum-romanVal;
		}
		else
		{
			sum=sum+romanVal;
		}
		prevVal=romanVal;

		reverseQueue(q,createDataNumeral(d->numeral));
		popQueue(qtmp);
	}
	cleanQueue(qtmp);
	return sum;
}

	//cleanQueue function definition
void cleanQueue(struct queue *q)
{
	while(!isEmptyQueue(q))
	{
		popQueue(q);	//removes the element from the queue
	}
	free(q->que);	//frees the memory allocated
	free(q);
}

	//sizeQueue function definition
int sizeQueue(struct queue *q)
{
	int size=0;
	struct queue* qtmp=createQueue();
		//increments the size till queue is not empty
	for(size=0;!isEmptyQueue(q);size++)
	{
		struct data* d=topQueue(q);
		pushQueue(qtmp,createDataNumeral(d->numeral));
		popQueue(q);
	}
	while(!isEmptyQueue(qtmp))
	{
		struct data* d=topQueue(qtmp);
		pushQueue(q,createDataNumeral(d->numeral));
		popQueue(qtmp);
	}
	cleanQueue(qtmp);	//cleans the temporary queue
	return size;		//returns the size of the queue
}

	//printQueue function definition
void printQueue(struct queue *q)
{
	struct queue* qtmp=createQueue();
	for(;!isEmptyQueue(q);)
	{
		struct data* d=topQueue(q);
		pushQueue(qtmp,createDataNumeral(d->numeral));
		popQueue(q);
	}
	for(;!isEmptyQueue(qtmp);)
	{
		struct data* d=topQueue(qtmp);
		printData(d);			//print elements from the queue and not from dlinklist
		pushQueue(q,createDataNumeral(d->numeral));
		popQueue(qtmp);
	}
	cleanQueue(qtmp);
}

	//isEmptyQueue function definition
int isEmptyQueue(struct queue* q)
{
	return isEmpty(q->que);	//tests if queue is empty.  return 1 if empty and 0 if not
}

	//topQueue function
struct data* topQueue(struct queue* q)
{
	return getFront(q->que);	//gets item from top of queue
}

	//popQueue function
void popQueue(struct queue* q)
{
	removeFront(q->que);		//pops topmost item from the queue
}

	//reverseQueue function definition
void reverseQueue(struct queue* q,struct data* dta)
{
	addFront(q->que,dta);		//push item into queue in reverse manner
}

	//function definition of pushQueue
void pushQueue(struct queue *q,struct data *dta)
{
	addBack(q->que,dta);		//push item from the front onto the queue
}

	//allocate queue
struct queue* createQueue()
{
	struct queue *q = malloc(sizeof(struct queue));
	q->que = createDLinkedList();
	return q;

}
