#include<stdio.h>
#include<stdlib.h>
int bottom_cut_rod(int A[],int B[],int n)
{
	int i;
	int temp,sum;
	if(n==0)
	{
		return 0;
	}
	for(i=n-1;i>=0;i--)
	{
		if(B[n-i-1]==0)
		{
			
			B[n-i-1]=bottom_cut_rod(A,B,n-i-1);
		}	
		temp=A[i]+B[n-i-1];
		if(temp>sum)
		{
			sum=temp;
		}
	}
	return sum;	
}
void main()
{
	int A[10];
	int* B;
	int i;	
	int n;
	int sum;
	A[0]=1;
	A[1]=5;
	A[2]=8;
	A[3]=9;
	A[4]=10;
	A[5]=17;
	A[6]=17;
	A[7]=20;
	A[8]=24;
	A[9]=30;
	printf("Please input n\n");
	scanf("%d",&n);	
	B=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		B[i]=0;
	}
	sum=bottom_cut_rod(A,B,n);
	printf("\n%d\n",sum);
}
