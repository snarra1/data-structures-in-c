#ifndef AVL_H_
#define AVL_H_

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "data.h"

	//Function declarations
int searchAvl_r(struct avlLeaf* current, struct data* d);
int searchAvl(struct avlTree* t, struct data* d);
void cleanAvl_r(struct avlLeaf* lf);
void cleanAvl(struct avlTree* t);
void inOrderAvl(struct avlTree *t);
void inOrderAvl_r(struct avlLeaf *current);
int isRightChild( struct avlLeaf* current);
int isLeftChild( struct avlLeaf* current);
int isRoot( struct avlLeaf* current);
int getBalanceFact(struct avlLeaf *lf);
int maxHeight(int a,int b);
int getHeight(struct avlLeaf *lf);
void rotateLeft(struct avlTree *t,struct avlLeaf *current);
void rotateRight(struct avlTree *t,struct avlLeaf *current);
void insertAvl_r(struct avlTree *t,struct avlLeaf* current,struct avlLeaf* newLeaf);
void insertAvl(struct avlTree *t,struct data *d);
struct avlLeaf* createAvlLeaf(struct data *d);
struct avlTree* createAvlTree();
#endif
