#include<stdio.h>
#include<math.h>
typedef struct
{
	int n_L;
	int n_R;
	int max;
}Array;
Array Maximum_Crossing_Array(int A[],int low,int mid,int high);		//get the Maximum Crossing Array
Array Maximum_Array(int A[],int low,int high);			//get the Maximum Array
void main()
{	int i=0;
	int A[16];
	Array array;
	printf("Plesase input 16 number\n");
	for(i=0;i<16;i++)
	{
		scanf("%d",&A[i]);
	}
	array=Maximum_Array(A,0,15);
	printf("%d,%d,%d\n",array.n_L,array.n_R,array.max);
}
Array Maximum_Crossing_Array(int A[],int low,int mid,int high)
{	
	int i;
	int max_L,max_R;		//save the max value of two sides
	int n_L, n_R;
	int max;
	int s;	
	Array maximum;		
	max_L=A[mid];
	max_R=A[mid+1];
	n_L=mid;
	n_R=mid+1;
	s=0;
	for(i=mid;i>=low;i--)
	{
		s+=A[i];
		if(max_L<s)
		{
			max_L=s;
			n_L=i;
		}
	}
	s=0;
	for(i=mid+1;i<=high;i++)
	{
		s+=A[i];
		if(max_R<s)
		{
			max_R=s;
			n_R=i;
		}		
	}
	max=max_L+max_R;
	maximum.n_L=n_L;
	maximum.n_R=n_R;
	maximum.max=max;
	return maximum;
}
Array Maximum_Array(int A[],int low,int high)
{
	int mid;
	int i,j;
	int length;
	Array array_L;
	Array array_R;
	Array array_Mid;
	length=high-low+1;
	if(length>2)
	{	if((high+low)%2)
		{
			mid=(high+low-1)/2;
		}
		else
		{
			mid=(high+low)/2;
		}
		array_L=Maximum_Array(A,low,mid);
		array_R=Maximum_Array(A,mid+1,high);
		array_Mid=Maximum_Crossing_Array(A,low,mid,high);
		if(array_L.max>array_R.max)
		{
			if(array_L.max>array_Mid.max)
			{
				return array_L;
			}
			else
			{
				return array_Mid;
			}
		}
		else
		{
			if(array_R.max>array_Mid.max)
			{
				return array_R;
			}
			else
			{
				return array_Mid;
			}
		}
			
	}
}
		
				
