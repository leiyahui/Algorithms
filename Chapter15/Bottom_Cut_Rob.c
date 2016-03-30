#include<stdio.h>
#include<stdlib.h>
int bottom_cut_rod(int A[],int B[],int n)
{
	int i,j;
	int p,temp;
	B[0]=0;
	for(i=1;i<=n;i++)
	{
		p=-10000;
		for(j=1;j<=i;j++)
		{
			temp=B[i-j]+A[j];
			if(p<temp)
			{
				p=temp;
			}
		}
		B[j-1]=p;
	}
	return p;
}
void main()
{
	int A[10];
	int* B;
	int i;	
	int n;
	int sum;
	A[1]=2;
	A[2]=5;
	A[3]=8;
	A[4]=9;
	A[5]=10;
	A[6]=17;
	A[7]=17;
	A[8]=20;
	A[9]=24;
	A[10]=30;
	printf("Please input n\n");
	scanf("%d",&n);	
	B=(int*)malloc(sizeof(int)*(n+1));
	for(i=0;i<n;i++)
	{
		B[i]=0;
	}
	sum=bottom_cut_rod(A,B,n);
	printf("\n%d\n",sum);
}
