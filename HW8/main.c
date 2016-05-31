#include <stdio.h>
#include "bst.h"

int main(int argc,char* argv[])
{
	if(argc==1 || (argc-1)%2!=0)
	{
		printf("\n ./main arg1-v1 arg1-v2 arg2-v1 arg-v2 .....\n\n");
		exit(1);
	}
	int i=0;
	struct tree* t=createTree();
	for(i=1;i<argc;i+=2)
	{
		insertBst(t,createData(atof(argv[i]),atof(argv[i+1])));
	}
	inOrderBst(t);
	printf("\n");
	preOrderBst(t);
	printf("\n");
	postOrderBst(t);
	printf("\n");
	printf(" %f \n",totalSum(t));
	printBreadthFirstSearch(t);
	printf("\n");
	printDepthFirstSearch(t);
	printf("\n");
	printData(getMaxData(t));
	printf("\n");
	printData(getMimData(t));
	printf("\n %d \n",getBstHeight(t));
	printf("\n");
	printInRange(t,0,200);
	printf("\n");
	printf("\n %d \n",isFullBst(t));
	printf("\n %f \n",sumLeaves(t));
	printf("\n %d \n",isCompleteBst(t));
	reverseBST(t);
	printf("\n");
	inOrderBst(t);
	printf("\n");
	cleanBST(t);
	return 0;

}
