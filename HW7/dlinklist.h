#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct node
{
	struct node *next;
	struct node *prev;
	struct data *d;
};

struct dlinklist
{
	struct node *head;
	struct node *tail;
};

	//reserve space for a new dlinklist, set initial variables, and return dlinklist
struct dlinklist* createDLinkedList();
	//reserve space for new node, set variables and return
struct node* createNode(struct data *d);
	//reserve space for a new data struct,set variables and return
void addFront(struct dlinklist *ll,struct data *d);
	//create a new node, set the data pointer, and add to back of dlinklist
void addBack(struct dlinklist *ll,struct data *d);
	//remove node from front of linklist
void removeFront(struct dlinklist *dll);
	//remove node from back of linklist
void removeBack(struct dlinklist *dll);
	//get data item from front of linklist
struct data* getFront(struct dlinklist *dll);
	//get data item from front of linklist
struct data* getFront(struct dlinklist *dll);
	//test if linked list is empty
int isEmpty(struct dlinklist *dll);

#endif
