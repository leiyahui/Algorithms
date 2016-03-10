#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Randomized_Partition(int A[],int begin,int end);
int Randomized_Select(int A[],int begin,int end,int r);
void main()
{
	int A[10];
	int i;
	int s;
	int n;
	printf("please input 10 numbers\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("Please input which one you want output\n");
	scanf("%d",&n);
	s=Randomized_Select(A,0,9,n);
	printf("%d\n",s);
}
int Randomized_Partition(int A[],int begin,int end)
{
	int length;
	int i,j;
	int s;
	int temp;
	length=end-begin+1;
	srand((unsigned)time(NULL));
	i=rand()%length+begin;
	temp=A[begin];
	s=A[begin]=A[i];
	A[i]=temp;
	j=begin;
	for(i=begin+1;i<=end-1;i++)
	{
		if(A[i]<s)
		{
			j++;
			temp=A[j];
			A[j]=A[i];
			A[i]=temp;
		}
	}
	A[begin]=A[j];
	A[j]=s;
	return j;
}
int Randomized_Select(int A[],int begin,int end,int r)
{
	if(begin==end)
	{
		return A[begin];	
	}
	int k;
	int p;
	k=Randomized_Partition(A,begin,end);
	p=k-begin+1;
	if(p==r)
	{
		return A[r];
	}
	else if(p>r)
	{
		return Randomized_Select(A,begin,k-1,r);
	}
	else
	{
		return Randomized_Select(A,k+1,end,r-p);
	}
}
		
