#include<stdio.h>
void Calculate(int Sum[],int A[],int B[],int length,int n)
{
	int i,j;
	int a,b;
	int temp;
	int temp1,temp2;
	for(i=0;i<length;i++)
	{
		Sum[i]=A[i]=B[i]=0;
	}
	Sum[0]=1;
	for(i=1;i<=n;i++)
	{	
		a=i%10;
		b=i/10;
		for(j=0;j<length-1;j++)
		{
			temp=Sum[j]*a;
			temp1=temp%10;
			temp2=temp/10;
			A[j]+=temp1;
			A[j+1]+=temp2;
		}
		for(j=0;j<length-2;j++)
		{
			temp=Sum[j]*b;
			temp1=temp%10;
			temp2=temp/10;
			B[j+1]+=temp1;
			B[j+2]+=temp2;
		}
		for(j=0;j<length;j++)
		{
			Sum[j]=0;
		}
		for(j=0;j<length-1;j++)
		{
			temp=A[j]+B[j+1];
			temp1=temp%10;
			temp2=temp/10;
			Sum[j]+=temp1;
			Sum[j+1]+=temp2;
		}
		for(j=0;j<length;j++)
		{
			A[j]=B[j]=0;
		}
	}
}
void main()
{
	int Sum[1000];
	int A[1000];
	int B[1000];
	int i,j;
	int n;
	printf("please input a number:\n");
	scanf("%d",&n);
	Calculate(Sum,A,B,1000,n);
	j=999;
	while(Sum[j]==0)
	{
		j--;
	}
	for(i=j;i>=0;i--)
	{
		printf("%d",Sum[i]);
	}
	printf("\n");
}
		
		
		 
