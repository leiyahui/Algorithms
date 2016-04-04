#include<stdio.h>
#include<stdlib.h>
int memorized_cut_rod(int A[],int B[],int n)
{
	int i;
	int p,temp;
	p=-10000;
	if(n==0)
	{
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(B[n-i]!=0)			//the value have been stored
		{
			temp=A[i]+B[n-i];
			if(temp>p)
			{
				p=temp;
			}
		}
		else
		{
			B[n-i]=memorized_cut_rod(A,B,n-i);		//the value haven't been stored
			temp=A[i]+B[n-i];
			if(temp>p)
			{
				p=temp;
			}
		}
	}
	return p;
}
void main()
{
	int A[11];
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
	for(i=0;i<=n;i++)
	{
		B[i]=0;
	}
	sum=memorized_cut_rod(A,B,n);
	printf("\n%d\n",sum);
}
