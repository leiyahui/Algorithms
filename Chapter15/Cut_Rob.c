#include<stdio.h>
int cut_rob(int A[],int n)
{
	int i,temp;
	int q=-10000	;	//as minimum as possible
	if(n==0)
	{
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		temp=A[i]+cut_rob(A,n-i);
		if(q<temp)
		{
			q=temp;
		}
	}
	return q;
}	
void main()
{
	int A[11];
	int n;
	int q;
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
	q=cut_rob(A,n); 
	printf("%d\n",q);
}
