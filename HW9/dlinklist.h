#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "structures.h"


//reserve space for a new dlinklist, set initial variables, and return dlinklist
struct dlinklist* createDLinkedList();
//reserve space for new node, set variables and return
struct node* createNode(struct leaf *lf);
//reserve space for a new leaf struct,set variables and return
void addFront(struct dlinklist *ll,struct leaf *lf);
//create a new node, set the leaf pointer, and add to back of dlinklist
void addBack(struct dlinklist *ll,struct leaf *lf);
//remove node from front of linklist
void removeFront(struct dlinklist *dll);
//remove node from back of linklist
void removeBack(struct dlinklist *dll);
//get leaf item from front of linklist
struct leaf* getFront(struct dlinklist *dll);
//get leaf item from front of linklist
struct leaf* getBack(struct dlinklist *dll);
//test if linked list is empty
int isEmpty(struct dlinklist *dll);
#endif
