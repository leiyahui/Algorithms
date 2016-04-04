#include<stdio.h>
#include<stdlib.h>
int lcs_length(int X[],int a,int Y[],int b)
{
	int i,j;
	int length;
	int** p;
	p=(int**)malloc(sizeof(int*)*(a+1));		//dynamic malloc two dimension array a*b;
	for(i=0;i<=a;i++)
	{
		*(p+i)=(int*)malloc(sizeof(int)*(b+1));
	}
	for(i=0;i<=a;i++)
	{
		p[i][0]=0;
	}
	for(j=0;j<=b;j++)
	{
		p[0][j]=0;
	}
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			if(X[i]==Y[j])
			{
				p[i][j]=p[i-1][j-1]+1;
			}
			else
			{
				if(p[i][j-1]>p[i-1][j])
				{
					p[i][j]=p[i][j-1];
				}
				else
				{
					p[i][j]=p[i-1][j-1];
				}
			}
		}
	}
	return p[a][b];
}
void main()
{
	
	int X[11];
	int Y[11];
	int sum;
	X[1]='C';
	X[2]='C';
	X[3]='T';
	X[4]='C';
	X[5]='G';
	X[6]='C';
	X[7]='C';
	X[8]='G';
	X[9]='A';
	X[10]='C';
	Y[1]='C';
	Y[2]='C';
	Y[3]='T';
	Y[4]='C';
	Y[5]='T';
	Y[6]='T';
	Y[7]='C';
	Y[8]='G';
	Y[9]='A';
	Y[10]='C';
	sum=lcs_length(X,10,Y,10);
	printf("%d\n",sum);
}
