#include "dlinklist.h"

#include <assert.h>	//for assert function
#include <stdlib.h>

	//creates node
struct node *createNode(struct data *d)
{
	struct node *n = malloc(sizeof(struct node));
	n->d = d;
	n->next = n->prev = NULL;
	return n;
}

	//createDLinkedList
struct dlinklist *createDLinkedList()
{
	struct dlinklist *dll = malloc(sizeof(struct dlinklist));
	dll->head = dll->tail = NULL;
	return dll;
}

	//addFront function definition
void addFront(struct dlinklist *dll, struct data *d)
{
	struct node *nd = createNode(d);
	nd->next = dll->head;
	dll->head = nd;
	if (nd->next == NULL)// checks if list was empty
	{
        	assert(dll->tail == NULL); // tail should be NULL
		dll->tail = nd;
    	}
	else
	{
        	nd->next->prev = nd;	//adds to front before head
    	}
}

	//addBack function definition
void addBack(struct dlinklist *dll, struct data *d)
{
	struct node *nd = createNode(d);
	nd->prev = dll->tail;
	dll->tail = nd;
	if (nd->prev == NULL)  // if list was empty
	{
        	assert(dll->head == NULL); // tail should be NULL
	        dll->head = nd;
    	}
	else
	{
        	nd->prev->next = nd;	//adds to the back of list after tail
    	}
}

	//getFront function definition
struct data* getFront(struct dlinklist *dll)
{
	if(dll->head == NULL)
    	{
	      assert(dll->tail == NULL);	//checking if there our assertion failed i.e. if head is empty tail should be empty
	      return NULL;
	}
	return dll->head->d;	//returns data on the front side of list
}

	//defining getBack function
struct data* getBack(struct dlinklist *dll)
{
	if(dll->tail == NULL)
	{
	      assert(dll->head == NULL);
	      return NULL;
	}
	return dll->tail->d;		//returns data on the back
}

	//removeFront function
void removeFront(struct dlinklist *dll)
{
	if(dll->head == NULL)	//list is empty
	{
	      assert(dll->tail == NULL);
	      return;
	}

	if(dll->head == dll->tail)	//has only 1 element
	{
	      free(dll->head->d);
	      free(dll->head);
	      dll->head = NULL;
	      dll->tail = NULL;
    	}
	else		//removing front element
	{
	      free(dll->head->d);
	      dll->head = dll->head->next;
	      free(dll->head->prev);
	}
}

	//removeBack definition
void removeBack(struct dlinklist *dll)
{
	if(dll->tail == NULL)	//List is empty
	{
	      assert(dll->head == NULL);
	      return;
	}
	if(dll->head == dll->tail)	//list has only 1 element
    	{
	      free(dll->tail->d);
	      free(dll->tail);
	      dll->head = NULL;
	      dll->tail = NULL;
	}
	else	//removes the back element
	{
	      free(dll->tail->d);
	      dll->tail = dll->tail->prev;
	      free(dll->tail->next);
    	}
}
	//defining isEmpty function
int isEmpty(struct dlinklist *dll)
{
	if(dll->head == NULL)		//checks if list is empty
	{
	      assert(dll->tail == NULL);
	      return 1;		//returns 1 if true
	}
	return 0;	//list is not empty
}
