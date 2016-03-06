#include<stdio.h>
#include<math.h>
void Max_Heapify(int A[],int i,int heap_size);		//adjust the complete binary tree to max heap
void Build_Max_Heap(int A[],int heap_size);		//build max heap
void Heap_Sortion(int A[],int heap_size);
void main()
{	
	int A[10];
	int i;
	printf("Please input 10 numbers\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&A[i]);
	}
	Heap_Sortion(A,10);
	for(i=0;i<10;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}	
void Max_Heapify(int A[],int i,int heap_size)
{
	int self,left,right,largest;
	int j;
	int s;
	int temp;		
	self=i;
	left=2*i;
       	right=2*i+1;
	largest=self;
	if(left<=heap_size)
	{
			
		if(A[self-1]<A[left-1])
		{
			largest=left;
		}
	}
	if(right<=heap_size)
	{
		if(A[right-1]>A[largest-1])
		{
			largest=right;
		}
	}
	if(largest==left)
	{
		temp=A[left-1];
		A[left-1]=A[self-1];
		A[self-1]=temp;
		Max_Heapify(A,left,heap_size);
	}
	else if(largest==right)
	{
		temp=A[right-1];
		A[right-1]=A[self-1];
		A[self-1]=temp;
		Max_Heapify(A,right,heap_size);
	}
	else
	{
	}	
}
void Build_Max_Heap(int A[],int heap_size)
{
	int i,j;
	int s;
	s=0;
	j=1;
	while(s<heap_size)
	{
		j=j*2;
		s+=j;
	}
	s=s-j;
	for(i=s;i>0;i--)
	{	
		Max_Heapify(A,i,heap_size);
	}
}				
void Heap_Sortion(int A[],int heap_size)
{
	int temp;
	int i;
	Build_Max_Heap(A,heap_size);
	for(i=0;i<heap_size;i++)
	{
		temp=A[0];
		A[0]=A[heap_size-i-1];
		A[heap_size-i-1]=temp;
		Max_Heapify(A,1,heap_size-i-1);
	}
}
		



















