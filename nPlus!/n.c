#include<stdio.h>
void Calculate(int Sum[],int length,int n)
{
	int i,j;
	int temp;
	int temp1,temp2;
	for(i=0;i<length;i++)
	{
		Sum[i]=0;
	}
	Sum[0]=1;
	for(i=1;i<=n;i++)
	{	
		for(j=0;j<length;j++)
		{
			temp=Sum[j]*i+temp2;
			temp1=temp%10000;
			temp2=temp/10000;
			Sum[j]=temp1;
		}
	}
}
int main()
{
	int Sum[1000];
	int i,j;
	int n;
	printf("please input a number:\n");
	scanf("%d",&n);
	Calculate(Sum,1000,n);
	j=999;
	while(Sum[j]==0)
	{
		j--;
	}
	if(j==999)
	{
		printf("Overflow\n");
		return 0;
	}
	for(i=j;i>=0;i--)
	{
		printf("%d     ",Sum[i]);
	}
	printf("\n");
	return 1;
}
		
		
		 
