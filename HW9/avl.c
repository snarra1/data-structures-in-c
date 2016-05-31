#include "avl.h"

	//searchAvl_r recursive function definition
int searchAvl_r(struct avlLeaf* alf, struct data* d)
{
	if(alf==NULL)
	{
		return 0;
	}
	else
	{
		if(compareData(alf->dta,d)==1)	//found the data searching for
		{
			return 1;
		}
		else if(sumData(alf->dta)>=sumData(d))	//iterates left if data less than current data
		{
			return searchAvl_r(alf->left,d);
		}
		else 	//if(sumData(alf->dta)<sumData(d))	//otherwise iterates right
		{
			return searchAvl_r(alf->right,d);
		}
	}
}

	//searchAvl function definition
int searchAvl(struct avlTree* avl, struct data* d)
{
	if(avl->root==NULL || d==NULL)
	{
		return 0;	//return 0 if tree is empty
	}
	else
	{
		return searchAvl_r(avl->root,d);	//searching data
	}
}

	//cleanAvl_r recursive function definition
void cleanAvl_r(struct avlLeaf* lf)
{
	if(lf==NULL)
	{
		return;
	}
	else
	{
		free(lf->dta);
		cleanAvl_r(lf->right);	//right recursion
		cleanAvl_r(lf->left);	//left recursion
		free(lf);
	}
}

	//cleanAvl function definition
void cleanAvl(struct avlTree* avl)
{
	if(avl->root==NULL)
	{
		return;
	}
	else
	{
		cleanAvl_r(avl->root);	//frees the memory allocated to avl
	}
	free(avl);
}

	//inOrderAvl function definition
void inOrderAvl(struct avlTree* avl)
{
	if(avl->root==NULL)
	{
		return;
	}
	else
	{
		inOrderAvl_r(avl->root);
	}
}

	//inOrderAvl_r recursive function definition
void inOrderAvl_r(struct avlLeaf* current)
{
	if(current!=NULL)
	{
		inOrderAvl_r(current->left);
		printData(current->dta);
		inOrderAvl_r(current->right);
	}
	else
	{
		return;
	}
}

	//isRoot function definition
int isRoot( struct avlLeaf* current)
{
	return (current->parent==NULL);		//checks if node is root
}

	//isLeftChild function definition
int isLeftChild( struct avlLeaf* current)
{
	return !isRoot(current) && (current->parent->left==current);	//checks if node is left child
}

	//isRightChild function definition
int isRightChild( struct avlLeaf* current)
{
	return !isRoot(current) && (current->parent->right==current);	//checks if node is right child
}

	//maxHeight function definition
int maxHeight(int a,int b)
{
	return a > b? a : b;	//returns max height
}

	//getHeight function definition
int getHeight(struct avlLeaf *lf)
{
	if(lf!=NULL)
	{
		return lf->height;	//return height of tree
	}
	else
	{
		 return 0;
	}
}

	//getBalanceFact function definition
int getBalanceFact(struct avlLeaf *lf)
{
	return (getHeight(lf->right) - getHeight(lf->left));	//returns banlance factor of node
}

	//rotateLeft function definition
void rotateLeft(struct avlTree *avl, struct avlLeaf *current)
{
	struct avlLeaf* ptr = current->right;	//holds the right child of node
	current->right = ptr->left;	//updates right child of node

	if(ptr->left!=NULL)
	{
		ptr->left->parent=current;
	}
	ptr->left = current;
	ptr->parent = current ->parent;

	if(ptr->parent==NULL)
	{
		avl->root = ptr;
	}
	if(isRightChild(current))
	{
		ptr->parent->right=ptr;
	}
	if(isLeftChild(current))
	{
		ptr->parent->left=ptr;
	}
	current->parent=ptr;
	current->height=maxHeight(getHeight(current->left),getHeight(current->right))+1;	//updates height
	ptr->height=maxHeight(getHeight(ptr->right),getHeight(ptr->left))+1;	//updates height of node
}

	//rotateRight function definition
void rotateRight(struct avlTree* avl, struct avlLeaf* current)
{
	struct avlLeaf* ptr = current->left;	//points to the left child of node
	current->left = ptr->right;	//updates left child of node

	if(ptr->right!=NULL)
	{
		ptr->right->parent = current;
	}
	ptr->right = current;
	ptr->parent = current -> parent;

	if(ptr->parent == NULL)
	{
		avl->root = ptr;
	}
	else if( isLeftChild(current))
	{
		ptr->parent->left=ptr;
	}
	else
	{
		ptr->parent->right=ptr;
	}
	current->parent = ptr;
	current->height=maxHeight(getHeight(current->right),getHeight(current->left))+1;	//updates new height
	ptr->height=maxHeight(getHeight(ptr->right),getHeight(ptr->left))+1;	//updates height of node
}

	//insertAvl_r recursive function definition
void insertAvl_r(struct avlTree* avl,struct avlLeaf* current,struct avlLeaf* lf)
{
	int bf=0;
	if(sumData(current->dta)>=sumData(lf->dta))
	{
		if(current->left==NULL)
		{
			current->left=lf;
			lf->parent=current;
		}
		else
		{
			insertAvl_r(avl,current->left,lf);
		}
		current->height=maxHeight(getHeight(current->left),getHeight(current->right))+1;
	}
	else
	{
		if(current->right==NULL)
		{
			current->right=lf;
			lf->parent=current;
		}
		else
		{
			insertAvl_r(avl,current->right,lf);
		}
		current->height=maxHeight(getHeight(current->left),getHeight(current->right))+1;
	}
	bf=getBalanceFact(current);
	if(bf==2)
	{
		if(getBalanceFact(current->right)==1)
		{
			rotateLeft(avl,current);
		}
		else if(getBalanceFact(current->right)==-1)
		{
			rotateRight(avl,current->right);
			rotateLeft(avl,current);
		}
	}
	if(bf==-2)
	{
		if(getBalanceFact(current->left)==-1)
		{
			rotateRight(avl,current);
		}
		else if(getBalanceFact(current->left)==1)
		{
			rotateLeft(avl,current->left);
			rotateRight(avl,current);
		}
	}
}

	//insertAvl function definition
void insertAvl(struct avlTree* avl,struct data* d)
{
	if(avl->root==NULL)
	{
		avl->root=createAvlLeaf(d);
		avl->root->parent=NULL;
	}
	else
	{
		insertAvl_r(avl,avl->root,createAvlLeaf(d));
	}
}

	//createAvlLeaf function definition
struct avlLeaf* createAvlLeaf(struct data* d)
{
	struct avlLeaf* alf = malloc(sizeof(struct avlLeaf));
	alf->right = NULL;
	alf->left = NULL;
	alf->parent = NULL;
	alf->dta = d;
	alf->height = 1;
	return alf;
}

	//createAvlTree function definition
struct avlTree* createAvlTree()
{
	struct avlTree* avl = malloc(sizeof(struct avlTree));
	avl->root = NULL;
	return avl;
}
