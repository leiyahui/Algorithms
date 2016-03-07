#include<stdio.h>
#include<math.h>
int Partition(int A[],int begin,int end);	
void QuickSortion(int A[],int begin,int end);
void main()
{
	int A[10];
	int i;
	printf("Please input 10 numbers\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&A[i]);
	}
	QuickSortion(A,0,9);
	for(i=0;i<10;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}
int Partition(int A[],int begin,int end)
{
	int i,j;
	int length;
	int center;
	int temp;
	length=end-begin+1;
	center=A[end];
	j=begin-1;
	for(i=begin;i<length-1;i++)
	{
		if(A[i]<center)
		{	
			j++;
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	temp=A[j+1];
	A[j+1]=center;
	A[end]=temp;
	return j+1;
}
void QuickSortion(int A[],int begin,int end)
{	
	if(begin<end)
	{
		int j;
		j=Partition(A,begin,end);
		QuickSortion(A,begin,j-1);
		QuickSortion(A,j+1,end);
	}
}
			
	
	
