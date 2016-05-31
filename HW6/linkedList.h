#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "data.h"

	//structure declarations
struct lettercount{
	char letter[26];
	int count[26];
};

struct node{
  struct node* next;
  struct data* dta;
};

struct linkedList{
  struct node* head;
};

	//function declarations
struct node* createNode(struct data* dta);
struct linkedList* createLinkedList();
void addNPos(struct linkedList* l1, struct data* dta, int n);
void removeNPos(struct linkedList* l1, int n);
void cleanLinkedList(struct linkedList* l1);
void printLinkedList(struct linkedList* l1);
char* getLetterCount(struct linkedList* l1);
struct lettercount* getCount(char* str, struct lettercount* lc);

#endif
