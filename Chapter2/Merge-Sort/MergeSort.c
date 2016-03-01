/*This is a Program to Sort the queue that you input using Merge-Sort*/

#include<stdio.h>
#include<math.h>
int Sort_Rank(int A[],int length);	//Insertion-Sort
void Merge(int A[],int i,int j); 	
void MergeSortion(int A[],int r);	

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
void Merge(int A[],int i,int j)
{
	int a,b;
	int m,n;
	int p;
	int L[i],R[j];
	for(m=0;m<i;m++)
	{
		L[m]=A[i];
	}
	for(m=0;m<j;m++)
	{
		R[m]=A[i+m];
	}
	
	Sort_Rank(L,i);		
	Sort_Rank(R,j);
	m=n=0;	
	for(int p=0;p<r;p++)
	{	
		if(L[m]<R[n])
		{
			A[p]=L[m];
			m++;
		}	
		else
		{
			A[p]=R[n];
			n++;
		}
	}
}
void MergeSortion(int A[],int r)
{
	int i,j;
	if(r>1)
	{	
		if(r/2)
		{
			i=r/2-1;
			j=r/2+1;
		}
		else
		{
			i=j=r/2;
		}
		MergeSortion(A,i);
		MergeSortion(A+i,j);
		Merge(A,i,j);
	}	
		
}
