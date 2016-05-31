#include <stdio.h> // Header File

    //getMinFans function definition
void getMinFans(int fsize[],int nfan,int cooling)
{
	int i=0,j=0,k=0,flag=0;
	int sum=0,min=9999,addn=0,len=0;
	int temp[nfan],finalarr[nfan];

	for(i=0;i<nfan;i++) //initializing all the arrays by zero
	{
		temp[i]=0; //temporary array for storing sequence that is currently checked
		finalarr[i]=0; //holds the final array satisfying all the conditions (min power consumption)
	}
     	for(i=0;i<nfan;i++)
	{
		k=0; //stores size of temp array
		sum=fsize[i];
		temp[k]=fsize[i]; //temp array holds first element of fan sizes
		k++;
		for(j=1;j<nfan;j++) // to check cooling condition
		{
        		if(i!=j)//not to repeat same size
        		{
				if(sum==cooling ) //breaks the innermost loop if sum equals cooling number
                		{
	    				flag=1;
					break;
				}
				else if(sum<cooling) //if less than req. cooling adds another  fan size
                		{
					sum=sum+fsize[j];
					temp[k]=fsize[j]; //next element is added
					k++;
                		}
				else if(sum>cooling) // delete last element  if not needed
                		{
	                		sum=sum-fsize[j-1];
					k--;
					temp[k]=0;
        			}
            		}
		}
		if(flag==1)
		{
			addn=0; //holds sum of squares of fan sizes
			for(j=0;j<k;j++)
			{	    // addition of squares of fan size is calculated
				addn=addn+temp[j]*temp[j];
			}
			if(min>addn) //checks if addn of current sequence is minimum
			{
				min=addn; //assigns new min value
				len=0; //holds length of final array
				for(j=0;j<k;j++)
				{
					finalarr[j]=temp[j]; //holds the sequence of min power consumption
					len++;
				}
			}
		}
	}
	printf("\n");
	for(i=0;i<len;i++) //prints the min power consumption sequence
	{
		printf(" %d",finalarr[i]);
	}
	printf("\n ");
}
	//minHardDrives function definition
int minHardDrives(int used[],int usize,int total[],int tsize)
{
	int i=0,j=0,cnt=0; //cnt stores the count of required hard drives
	int usedsum=0,tsum=0;
	while(i<usize)  //calculates the sum of used disk space
	{
		usedsum=usedsum+used[i];
		i++;
	}
	while(j<tsize)
	{
		tsum=tsum+total[j]; // holds the total sum of hard disk space
		cnt++;
		if(usedsum<tsum) //checks if j drives are sufficient to store usedsum
		{
			break;
		}
		else if(usedsum>tsum && j==tsize-1) // if more drives required but unavailable
		{
			printf("\n More than %d drives required ",j);
		}
		else
		{
			j++; //increments j if drives not suffient
		}
	}
	return cnt; // returns the hard drives required for used disk space
}

	//defining findProfit  function
int findProfit(int cost[], int sales[], int unitsales[], int arraysize)
{
	int i=0, j=0, max=0, pos=0;
	int profit[arraysize];
	for(i=0;i<arraysize;i++)
	{
		profit[i]=unitsales[i]*(sales[i]-cost[i]); //calculates profit of each item
	}
	max=profit[0]; //initial maximum value is first element
	j=1;
	while(j<i) //finding maximum profit item from all items
	{
		if(profit[j]>max)
		{
			max=profit[j];
			pos=j;
		}
		j++;
	}
	return pos; // returning position of item with maximum profit
}
	//main function definition
int main()
{

	int numFans=7, coolingNum=10, usedSize=4, totalSize=4, minhd=0, arraySize=3, pos=0;
	int fanSizes[]={1,2,3,4,5,6,10};
	int used[]={60,20,30,40}, total[]={80,120,120,80};
	int cost[]={1,2,7}, sales[]={2,6,9}, unitSale[]={1,2,6};

	getMinFans(fanSizes,numFans,coolingNum); //calls getMinFans function for 7 fan sizes and cooling 10
	minhd=minHardDrives(used,usedSize,total,totalSize); //calls minHardDrives function for input 'used={60,20,30,40}'
	printf("\n %d\n",minhd); //prints minimum hard drives required
	pos=findProfit(cost,sales,unitSale,arraySize);
	printf("\n %d \n",pos);
	printf("\n ");
	return 0; // successful termination of main
}
