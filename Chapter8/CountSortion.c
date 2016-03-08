#include<stdio.h>
void Count_Sortion(int A[],int C[],int length,int k);		//all the element in array A is below k
void main()
{
	int A[10];
	int C[10];
	int i;
	printf("Please input 10 number under 100:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&A[i]);
	}
	Count_Sortion(A,C,10,100);
	for(i=0;i<10;i++)
	{
		printf("%d ",C[i]);
	}
	printf("\n");
}
	
void Count_Sortion(int A[],int C[],int length,int k)		
{
	int B[k];
	int i;
	for(i=0;i<k;i++)
	{
		B[i]=0;
	}
	for(i=0;i<length;i++)
	{
		B[A[i]]++;
	}
	for(i=0;i<k;i++)
	{
		if(i!=0)
		{
			B[i]+=B[i-1];		//recode the count smaller than A[i] or equal to A[i]
		}
		else
		{
			B[i]=0;			//there is no one element before the B[0];
		}
	}
	for(i=0;i<length;i++)
	{
		C[B[A[i]]-1]=A[i];
		B[A[i]]-=1;	
	}
}
	
	
	
