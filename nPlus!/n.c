#include<stdio.h>
int Calculate(int Sum[],int length,int n)
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
			if(j==length-1)
			{
				if(temp2!=0)
				{
					if(i<n)
					{
						return 0;
					}
				}
			}	
		}
	}
	return 1;
}
int main()
{
	int Sum[10000];
	int i,j;
	int n;
	printf("please input a number:\n");
	scanf("%d",&n);
	j=Calculate(Sum,10000,n);
	if(j==0)
	{
		printf("overflow\n");
		return 0;
	}
	j=9999;
	while(Sum[j]==0)
	{
		j--;
	}
	for(i=j;i>=0;i--)
	{
		if(i==j)
		{
			printf("%d",Sum[i]);
		}
		else
		{
			printf("%04d",Sum[i]);
		}
	}
	printf("\n");
	return 1;
}
		
		
		 
