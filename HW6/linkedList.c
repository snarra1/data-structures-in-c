#include "linkedList.h"

	//getCount function definition
struct lettercount* getCount(char* str,struct lettercount* lc)
{
	int i=0,j=0,pos=0;
	while(i<strlen(str))
	{
		j=0;
		while(j<26)
		{
			pos=(lc->letter[j])-'a';
			if(str[i]==lc->letter[pos])
			{
				lc->count[pos]++;	//updating count of letters in structure lettercount
				printf("%d",lc->count[pos]);
				break;
			}
			j++;
		}
		i++;
	}
	return lc;
}

	//getLetterCount function definition
char* getLetterCount(struct linkedList* l1)
{
	int i=0,j=0,k=0,len1=0,len2=0,pos=0;
	int cnt1=0;
	char *str1,* str2;
	struct node* ptr=l1->head;
	struct lettercount* lc=malloc(sizeof(struct lettercount));
	strcpy(lc->letter,"abcdefghijklmnopqrstuvwxz");
	for(i=0;i<26;i++)
	{
		lc->count[i]=0;
	}
	len1=strlen(ptr->dta->letters)+1;
	str1=malloc(len1*sizeof(char));
	strcpy(str1,ptr->dta->letters);
	lc=getCount(str1,lc);		//calls getCount Function

	len2=strlen(str1)+1;
	str2=malloc(len2*sizeof(char));

	for(ptr=l1->head->next;ptr!=NULL;ptr=ptr->next)
	{
		while(i<strlen( ptr->dta->letters))
		{
		 cnt1=0;
		 for(j=0;j<26;j++)
		 {
			pos=(lc->letter[j])-'a';
			if(lc->letter[pos]==ptr->dta->letters[i])
			{
				str2[k]=ptr->dta->letters[i];
				cnt1++;
				k++;
				break;
			}
			j++;
		 }
		 if(cnt1==lc->count[pos])
		 {
			break;
		 }
		 i++;
		}
		len2=k;
		k=0;
		strcpy(str1,str2);
	}
	free(lc);
	free(str2);
	return str1;
}

/*
	for(ptr=ptr->next;ptr!=NULL;ptr=ptr->next)
	{
		for(i=0;i<len1;i++)
		{
		 for(j=0;j<len2;j++)
		 {
			if(ptr->dta->letters[i]==ptr->next->dta->letters[i]);
			{
				str2[k]=ptr->dta->letters[i];
				k++;
			}
		 }
		 break;
		}
		len1=k;
		k=0;
		strcpy(str1,str2);
	}
	free(lc);
	free(str2);
	return str1;
*/

	//cleanLinkedList function definition
void cleanLinkedList(struct linkedList* l1)
{
	struct node* ptr;
        for(ptr=l1->head;ptr!=NULL;ptr=l1->head)
        {
		l1->head=l1->head->next;
			//frees the memory allocated to each pointer of structure
		free(ptr->dta->letters);
		free(ptr->dta);
		free(ptr);
        }
	//free(l1->head);		//frees the pointer to head of linked list
	free(l1);	//frees the pointer to linked list

}

	//prints Linked list
void printLinkedList(struct linkedList *l1)
{
	struct node* ptr=l1->head;
	while(ptr!=NULL)
	{		//prints data in nodes of the linked list
		printData(ptr->dta);
		ptr=ptr->next;
	}
}

	//removeNPos function definition
void removeNPos(struct linkedList* l1,int n)
{
	int i=0;
	struct node* prev=NULL;
	struct node* ptr=l1->head;
	if(n==0)
	{
		l1->head=ptr->next;	//removes node in first position i.e. head of linked list
	}
	else
	{		//traverses till n-1 position and removes nth node
        	for(i=0; i<n && ptr->next!=NULL; i++)
        	{
			prev=ptr;
		 	ptr=ptr->next;
		}
		prev->next=ptr->next;
        }
		//deallocates the memory allocated to the data structure and node
	free(ptr->dta->letters);
	free(ptr->dta);
	free(ptr);
}

	//addNPos function definition
void addNPos(struct linkedList* l1,struct data* dta,int n)
{
	int i=0;
	struct node* ptr=l1->head;
	struct node* temp=createNode(dta);
	if(n==0)	//adds node at first position and changes head of linked list
	{
		temp->next=l1->head;
		l1->head=temp;
	}
	else		//traverses till n-1 position to add at nth position
	{
        	while(ptr->next!=NULL)
        	{
        		ptr=ptr->next;
			i++;
			if(i==n-1)
			{
				break;
			}
		}
		temp->next=ptr->next;
		ptr->next=temp;
        }
}

	//createNode function definition
struct node* createNode(struct data* dta)
{
		//allocates space and assigns values to created node
	struct node* temp= malloc(sizeof(struct node));
	temp->next=NULL;
	temp->dta=dta;
	return temp;
}

	//createLinkedList function definition
struct linkedList* createLinkedList()
{
		//allocates space to pointer of linked list and points head to NULL
	struct linkedList* listTemp = malloc(sizeof(struct linkedList));
	listTemp->head=NULL;
	return listTemp;
}
