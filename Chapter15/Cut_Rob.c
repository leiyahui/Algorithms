#include<stdio.h>
int cut_rob(int A[],int n,int c)
{
	int i,temp;
	int q=-10000	;	//as minimum as possible
	if(n==0)
	{
		return 0;
	}
	for(i=0;i<n;i++)
	{
		temp=A[i+1]+cut_rob(A,n-i-1,c+1);
		if(q<temp)
		{
			q=temp;
		}
	}
	return q;
}	
void main()
{
	int A[10];
	int n;
	int q;
	int i;
	A[1]=1;
	A[2]=5;
	A[3]=8;
	A[4]=9;
	A[5]=10;
	A[6]=17;
	A[8]=20;
	A[9]=24;
	A[10]=30;
	printf("Please input n\n");
	scanf("%d",&n);
	q=cut_rob(A,n,0); 
	printf("%d\n",q);
}
