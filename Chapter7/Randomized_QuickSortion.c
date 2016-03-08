#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Randomized_Partition(int A[],int begin,int end);
void Randomized_QuickSortion(int A[],int begin,int end);
void main()
{
	int i;
	int A[10];
	printf("Please input 10 numbers\n");
	for(i=0;i<10;i++)
	{	
		scanf("%d",&A[i]);
	}
	Randomized_QuickSortion(A,0,9);
	for(i=0;i<10;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}
		
int Randomized_Partition(int A[],int begin,int end)
{
	int i,j;
	int length;
	int temp;
	int s;
	length=begin-end+1;
	srand((unsigned)time(NULL));
	i=rand()%length+begin;		//create a random between begin and end
	temp=A[i];
	A[i]=A[begin];
	s=A[begin]=temp;
	j=begin;
	for(i=begin+1;i<=end;i++)
	{
		if(A[i]<s)		
		{
			j++;
			temp=A[j];
			A[j]=A[i];
			A[i]=A[j];
		}
	}
	A[begin]=A[i];
	A[i]=s;
	return i;
}		
void Randomized_QuickSortion(int A[],int begin,int end)
{
	int i;
	i=Randomized_Partition(A,begin,end);
	Randomized_QuickSortion(A,begin,i-1);
	Randomized_QuickSortion(A,i+1,end);
}

