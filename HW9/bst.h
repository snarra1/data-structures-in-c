#ifndef BST_H_
#define BST_H_

	//Header files
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "data.h"
//#include "stack.h"
//#include "queue.h"

	//function declarations
struct leaf* createLeaf(struct data *d);
struct tree* createTree();
void insertBst(struct tree *t,struct data *d);
void insertBst_r(struct leaf* current,struct leaf* newLeaf);
void preOrderBst(struct tree *t);
void preOrderBst_r(struct leaf *current);
void inOrderBst(struct tree *t);
void inOrderBst_r(struct leaf *current);
void postOrderBst(struct tree *t);
void postOrderBst_r(struct leaf *current);
float totalSum(struct tree *t);
float totalSum_r(struct leaf* current);
struct data* getMaxData(struct tree* t);
struct data* getMaxData_r(struct leaf* lf);
struct data* getMimData(struct tree* t);
struct data* getMimData_r(struct leaf* lf);
int getBstHeight(struct tree* t);
int getBstHeight_r(struct leaf* lf);
void printInRange(struct tree* t, float begin, float end);
void printInRange_r(struct leaf* lf, float begin, float end);
int isCompleteBst(struct tree* t);
int isCompleteBst_r(struct leaf* lf);
int isFullBst(struct tree* t);
int isFullBst_r(struct leaf* lf);
void reverseBST(struct tree* t);
void reverseBST_r(struct leaf* lf);
float sumLeaves(struct tree* t);
float sumLeaves_r(struct leaf* lf);
void printBreadthFirstSearch(struct tree *t);
void printDepthFirstSearch(struct tree* t);
int searchBst(struct tree* t, struct data* d);
int searchBst_r(struct leaf* lf, struct data* d);
void cleanBST(struct tree* t);
void cleanBST_r(struct leaf* lf);

#endif
