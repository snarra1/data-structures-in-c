#include "linkedList.h"

int main(int argc, char* argv[])
{
	int j=0;
	char* str;
	struct linkedList* l1=createLinkedList();
	if(argc < 2)
	{
		printf("\n %s numArgs, arg1, arg2,...\n\n",argv[0]);
		free(l1);
		exit(1);
	}
	else
	{
		for(j=1;j<argc;j++)
		{
			addNPos(l1,createDataLetters(argv[j]),j-1);
		}
		printLinkedList(l1);
		printf("\n");
		removeNPos(l1,2);
		printLinkedList(l1);
		printf("\n");
		str=getLetterCount(l1);
		printf("\n%s\n",str);
		cleanLinkedList(l1);
		free(str);
	}
	return 0;
}
