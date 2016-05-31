#ifndef STRUCTURES_H_
#define STRUCTURES_H_

struct data
{
  float v1;
  float v2;
};


struct avlLeaf
{
  struct avlLeaf *parent;
  struct avlLeaf *left;
  struct avlLeaf *right;
  struct data *dta;
  int height;
};

struct leaf
{
  struct leaf *left;
  struct leaf *right;
  struct data *dta;
};


struct node
{
  struct node *next;
  struct node *prev;
  struct leaf *lf;
};

struct dlinklist
{
  struct node *head;
  struct node *tail;
};


struct tree
{
  struct leaf* root;
};

struct avlTree
{
  struct avlLeaf *root;
};

#endif
