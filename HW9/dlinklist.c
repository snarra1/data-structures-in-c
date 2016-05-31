#include "dlinklist.h"

#include <assert.h>
#include <stdlib.h>

struct node *createNode(struct leaf *lf) {
    struct node *n = malloc(sizeof(struct node));
    n->lf = lf;
    n->next = n->prev = NULL;
    return n;
}

struct dlinklist *createDLinkedList() {
    struct dlinklist *dll = malloc(sizeof(struct dlinklist));
    dll->head = dll->tail = NULL;
    return dll;
}

void addFront(struct dlinklist *dll, struct leaf *lf) {
    struct node *nd = createNode(lf); 
    nd->next = dll->head;
    dll->head = nd;
    if (nd->next == NULL) { // list was empty
        assert(dll->tail == NULL); // tail should be NULL
        dll->tail = nd;
    } else {
        nd->next->prev = nd;
    }
}

void addBack(struct dlinklist *dll, struct leaf *lf) {
    struct node *nd = createNode(lf); 
    nd->prev = dll->tail;
    dll->tail = nd;
    if (nd->prev == NULL) { // list was empty
        assert(dll->head == NULL); // tail should be NULL
        dll->head = nd;
    } else {
        nd->prev->next = nd;
    }
}


struct leaf* getFront(struct dlinklist *dll)
{
  if(dll->head == NULL)
    {
      assert(dll->tail == NULL);
      return NULL;
    }
  return dll->head->lf;
}
struct leaf* getBack(struct dlinklist *dll)
{
  if(dll->tail == NULL)
    {
      assert(dll->head == NULL);
      return NULL;
    }
  return dll->tail->lf;
}


void removeFront(struct dlinklist *dll)
{
  if(dll->head == NULL)
    {
      assert(dll->tail == NULL);
      return;
    }

  if(dll->head == dll->tail)
    {
      free(dll->head);
      dll->head = NULL;
      dll->tail = NULL;
    }
  else
    {
      dll->head = dll->head->next;
      free(dll->head->prev);
    }
  
}


void removeBack(struct dlinklist *dll)
{
  if(dll->tail == NULL)
    {
      assert(dll->head == NULL);
      return;
    }

  if(dll->head == dll->tail)
    {
      free(dll->tail);
      dll->head = NULL;
      dll->tail = NULL;
    }
  else
    {
      dll->tail = dll->tail->prev;
      free(dll->tail->next);

    }
  
}

int isEmpty(struct dlinklist *dll)
{
  if(dll->head == NULL)
    {
      assert(dll->tail == NULL);
      return 1;
    }
  return 0;
}
