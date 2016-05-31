	//including libraries
#include <stdio.h>
#include "random.h"
#include "timing.h"
#include "structures.h"
#include "bst.h"
#include "avl.h"

	//main finction definition
int main(int argc,char* argv[])
{
	randSeed();	//randSeed function call
	if(argc==1 || argc>2)
	{
		printf("\n %s (int)\n",argv[0]);
		exit(1);
	}
	else
	{
		clock_t stime,etime;
		int i=0,loop=0;
		struct avlTree* avl =createAvlTree();
		struct tree* t =createTree();
		struct data* dta=NULL;

		loop= 1000000 * atof(argv[1]);
		stime=getTime();		//getting start time for insertAvl
		for(i=0;i<loop;i++)
		{
			insertAvl(avl,randomData());	//inserting into avl trees
		}
		etime=getTime();		//getting end time for insertAvl
		printf("\n %f",timeDiff(stime,etime));	//printing the time taken by avl to insert into it
		stime=getTime();	//getting start time for insertBst
		for(i=0;i<loop;i++)
		{
			insertBst(t,randomData());	//inserting into bst
		}
		etime=getTime();		//getting end time for insertBst
		printf("\n %f",timeDiff(stime,etime));	//printing the time differnce to insert into bst
//		inOrderAvl(avl);
//		inOrderBst(t);
		stime=getTime();		//getting start time for searchAvl
		for(i=0;i<loop;i++)
		{
			dta=randomData();
			searchAvl(avl,dta);	//searching Avl
			free(dta);
		}
		etime=getTime();		//getting end time for searchAvl
		printf("\n %f",timeDiff(stime,etime));	//printing the time taken to search avl
		stime=getTime();		//getting start time for  searchBst
		for(i=0;i<loop;i++)
		{
			dta=randomData();
			searchBst(t,dta);	//searching Bst
			free(dta);
		}
		etime=getTime();		//getting end time for searchBst
		printf("\n %f",timeDiff(stime,etime));	//printing time difference for searching bst

		printf("\n");
		cleanAvl(avl);	//clean AVL trees
		cleanBST(t);	//clean BST
		return 0;
	}
}
