#include<stdio.h>
int Sort_Rank(int A[],int length);
int main(void)
{
	int A[10];
	int i;
	printf("Please input 10 numbers\n");
	for(i=0;i<10;i++)		//Input
	{
		scanf("%d",&A[i]);
	}	
	Sort_Rank(A,10);			//SortRank Algorithm
	for(i=0;i<10;i++)			//output
	{
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}
int Sort_Rank(int A[],int length)
{
	int i,j;
	int temp;
	for(i=1;i<length;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(A[j+1]<A[j])
			{
				temp=A[j+1];
				A[j+1]=A[j];
				A[j]=temp;			
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}
