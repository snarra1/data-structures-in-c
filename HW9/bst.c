
#include "bst.h"
#include <assert.h>

	//cleanBST_r recursive function definition
void cleanBST_r(struct leaf* lf)
{
	if(lf!=NULL)
	{
		cleanBST_r(lf->left);	//recursively calls left child
		free(lf->dta);		//frees the data of leaf
		cleanBST_r(lf->right);	// recursively calls the right child
	}
	free(lf);	//frees the leaf
}

	//cleanBST function definition definition
void cleanBST(struct tree* t)
{
	if(t->root!=NULL)
	{
		cleanBST_r(t->root);
	}
	free(t);	//frees the pointer to tree
}

	//searchBst_r recursive function definition
int searchBst_r(struct leaf* lf, struct data* d)
{
	if(lf==NULL)
	{
		return 0;
	}
	else
	{
		if(compareData(lf->dta,d)==1)
		{
			return 1;
		}
		else if(sumData(lf->dta)>=sumData(d))
		{
			return searchBst_r(lf->left,d);
		}
		else
		{
			return searchBst_r(lf->right,d);
		}
	}
}

	//searchBst function definition
int searchBst(struct tree* t, struct data* d)
{
	if(t->root==NULL)
	{
		return 0;
	}
	else
	{
		return searchBst_r(t->root,d);
	}
}
	//reverseBST_r recursive function definition
void reverseBST_r(struct leaf* lf)
{
	if(lf!=NULL)
	{
			//reverses the left and right pointers to trees
		struct leaf* lleaf=lf->left;
		lf->left=lf->right;
		lf->right=lleaf;
		reverseBST_r(lf->left);
		reverseBST_r(lf->right);
	}
	else
	{
		return;	//returns if leaf is null
	}
}

	//reverseBST function definition
void reverseBST(struct tree* t)
{
	if(t->root==NULL)
	{
		return;
	}
	reverseBST_r(t->root);	//calls reverseBST_r if root is not null
}

	//sumLeaves_r recursive function
float sumLeaves_r(struct leaf* lf)
{
	if(lf==NULL)
	{
		return 0;	//if null then returns 0
	}
	else if(lf->left!=NULL || lf->right!=NULL)
	{
		return sumLeaves_r(lf->left)+sumLeaves_r(lf->right);	//calls the left and right children
	}
	else
	{
		return sumData(lf->dta);	//adds the values of leaves
	}
}

	//sumLeaves function definition
float sumLeaves(struct tree* t)
{
	if(t->root==NULL)
	{
		return 0.0;
	}
	else
	{
		return sumLeaves_r(t->root);	//calls sumLeaves_r function
	}
}

	//isFullBst_r recursive function
int isFullBst_r(struct leaf* lf)
{
	if(lf==NULL)
	{
		return 1;
	}
			//Full tree is when node having 0 or max 2 children
	if(lf->left==NULL && lf->right==NULL)
	{
		return (isFullBst_r(lf->left) && isFullBst_r(lf->right));
	}
	if(lf->left!=NULL && lf->right!=NULL)
	{
		return (isFullBst_r(lf->left) && isFullBst_r(lf->right));
	}
	else
	{
		return 0;
	}
}

	//getBstHeight_r recursive function
int getBstHeight_r(struct leaf* lf)
{
	int lh=0,rh=0;
	if(lf==NULL)
	{
		return 0;
	}
	else
	{
		lh=getBstHeight_r(lf->left);	//returns height of left subtree
		rh=getBstHeight_r(lf->right);	//returns height of right subtree
		return 1 + (lh > rh ? lh : rh);	//selects height of subtree which is maximum
	}
}

	//getBstHeight function
int getBstHeight(struct tree* t)
{
	if(t->root==NULL)
	{
		return 0;
	}
	else
	{
		return getBstHeight_r(t->root);
	}
}


	//isFullBst function definition
int isFullBst(struct tree* t)
{
	if(t->root==NULL)
	{
		return 0;
	}
	else
	{
		return isFullBst_r(t->root);
	}
}

	//isCompleteBst_r recursive function definition
int isCompleteBst_r(struct leaf* lf)
{
	int lh=0,rh=0;
			//Tree is complete when all nodes except leaves have left and right children
	if(lf==NULL)
	{
		return 1;
	}
	lh=getBstHeight_r(lf->left);
	rh=getBstHeight_r(lf->right);
	return (lh==rh) && isCompleteBst_r(lf->left) && isCompleteBst_r(lf->right);
}

	//isCompleteBst function definition
int isCompleteBst(struct tree* t)
{
	if(t->root==NULL)
	{
		return 0;
	}
	else
	{
		return isCompleteBst_r(t->root);
	}
}

	//printInRange_r recursive function
void printInRange_r(struct leaf* lf, float begin, float end)
{
	if(lf!=NULL)
	{
		printInRange_r(lf->left,begin,end);	//prints data having sum greater than begin and less than end
		if(sumData(lf->dta) > begin && sumData(lf->dta) < end)
		{
			//printf("\n");
			printData(lf->dta);
		}
		printInRange_r(lf->right,begin,end);
	}
	else
		return;
}

	//printInRange_r function definition
void printInRange(struct tree* t, float begin, float end)
{
	if(t->root==NULL)
	{
		return;
	}
	else
	{
		printInRange_r(t->root,begin,end);
	}
}
	//getMimData_r recursive function
struct data* getMimData_r(struct leaf* lf)
{
	struct data* dta=NULL;
	if(lf==NULL)
	{
		return NULL;
	}
	else
	{	//returnsthe node which has minimum sum of v1 and v2
		if(lf->left==NULL && lf->right==NULL)
		{
			return lf->dta;
		}
		else if(lf->left==NULL)
		{
			return lf->dta;
		}
		else
		{
			if(sumData(lf->dta) == sumData(lf->left->dta))
			{
				return lf->dta;
			}
			else
			{
				dta=getMimData_r(lf->left);
				return dta;
			}
		}
	}
}

	//getMimData function
struct data* getMimData(struct tree* t)
{
	if(t->root==NULL)
	{
		return NULL;
	}
	else
	{
		return getMimData_r(t->root);
	}
}

	//getMaxData_r recursive function
struct data* getMaxData_r(struct leaf* lf)
{
	struct data* dta=NULL;
	if(lf==NULL)
	{
		return NULL;
	}
	else
	{		//returns the node which has maximum sum of v1 and v2
		if(lf->left==NULL && lf->right==NULL)
		{
			return lf->dta;
		}
		else if(lf->right==NULL)
		{
			return lf->dta;
		}
		else
		{
			if(sumData(lf->dta) == sumData(lf->right->dta))
			{
				return lf->dta;
			}
			else
			{
				dta=getMaxData_r(lf->right);
				return dta;
			}
		}
	}
}

	//getMaxData function
struct data* getMaxData(struct tree* t)
{
	if(t->root==NULL)
	{
		return NULL;
	}
	else
	{
		return getMaxData_r(t->root);
	}
}

	//totalSum_r recursive function
float totalSum_r(struct leaf* current)
{
	float left=0,right=0,self=0;
	if(current->left==NULL && current->right==NULL)
	{
		return sumData(current->dta);
	}
	else
	{
		self=sumData(current->dta);
		if(current->left!=NULL)
		{
			left=totalSum_r(current->left);
		}
		else
		{
			left=0.0;
		}
		if(current->right!=NULL)
		{
                	right=totalSum_r(current->right);
		}
        	else
        	{
	       		right=0.0;
		}
		return left+right+self;
	}
}

	//totalSum function
float totalSum(struct tree *t)
{
	if(t->root==NULL)
	{
		return 0.0;
	}
	else
	{
		return totalSum_r(t->root);
	}
}

	//postOrderBst_r recursive function
void postOrderBst_r(struct leaf *current)
{
	if(current!=NULL)
	{
		postOrderBst_r(current->left);
		postOrderBst_r(current->right);
		printData(current->dta);
	}
	else
		return;
}

	//postOrderBst function
void postOrderBst(struct tree *t)
{
	if(t->root==NULL)
	{
		return;
	}
	else
	{
		postOrderBst_r(t->root);
	}
}

	//preOrderBst_r recursive function
void preOrderBst_r(struct leaf *current)
{
	if(current!=NULL)
	{
		printData(current->dta);
		preOrderBst_r(current->left);
		preOrderBst_r(current->right);
	}
	else
		return;
}

	//preOrderBst function
void preOrderBst(struct tree *t)
{
	if(t->root==NULL)
	{
		return;
	}
	else
	{
		preOrderBst_r(t->root);
	}
}

/*
	//printBreadthFirstSearch function
void printBreadthFirstSearch(struct tree* t)
{
	if(t->root==NULL)
	{
		return;
	}
	else
	{		//displays the elements level wise
		struct queue* q = createQueue();
		pushQueue(q,t->root);
		while(!isEmptyQueue(q))
		{
			struct leaf* lf = topQueue(q);
			popQueue(q);
			printData(lf->dta);
			if(lf->left!=NULL)
			{
				pushQueue(q,lf->left);
			}
			if(lf->right!=NULL)
			{
				pushQueue(q,lf->right);
			}
		}
		cleanQueue(q);
	}
}

	//printDepthFirstSearch function
void printDepthFirstSearch(struct tree* t)
{
	if(t->root==NULL)
	{
		return;
	}
	else
	{		//displays the elements depth wise
		struct stack* s = createStack();
		pushStack(s,t->root);
		while(!isEmptyStack(s))
		{
			struct leaf* lf = topStack(s);
			printData(lf->dta);
			popStack(s);
			if(lf->left!=NULL)
			{
				pushStack(s,lf->left);
			}
			if(lf->right!=NULL)
			{
				pushStack(s,lf->right);
			}
		}
		cleanStack(s);
	}
}

*/

	//inOrderBst_r recursive function
void inOrderBst_r(struct leaf *current)
{
	if(current!=NULL)
	{
		inOrderBst_r(current->left);
		printData(current->dta);
		inOrderBst_r(current->right);
	}
	else
		return;
}

	//inOrderBst function
void inOrderBst(struct tree *t)
{
	if(t->root==NULL)
	{
		return;
	}
	else
	{
		inOrderBst_r(t->root);
	}
}

	//insertBst_r recursive function
void insertBst_r(struct leaf* current,struct leaf* lf)
{
	assert(current!=NULL);
		//inserts element to left of node if its sum is smaller or equal to that of node
	if(sumData(current->dta) >= sumData(lf->dta))
	{
		if(current->left==NULL)
		{
			current->left=lf;
		}
		else
		{
			insertBst_r(current->left,lf);
		}
	}
	else		//inserts element to the right otherwise
	{
		if(current->right==NULL)
                {
                        current->right=lf;
                }
                else
                {
                        insertBst_r(current->right,lf);
                }
	}
}

	//insertBst function
void insertBst(struct tree *t,struct data *d)
{
	struct leaf* lf=createLeaf(d);
	if(t->root==NULL)
	{
		t->root=lf;
	}
	else
	{
		insertBst_r(t->root,lf);
	}
}

	//createLeaf function
struct leaf* createLeaf(struct data *d)
{
	struct leaf* lf = malloc(sizeof(struct leaf));
	lf->right = NULL;
	lf->left = NULL;
	lf->dta = d;
	return lf;
}

	//createTree function
struct tree* createTree()
{
	struct tree* t = malloc(sizeof(struct tree));
	t->root = NULL;
	return t;
}
