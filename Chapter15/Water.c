#include<stdio.h>
#include<stdlib.h>
int max_length_sum(int A[10][],int B[10][],int a1x,int a1y,int a2x,int a2y,int b1x,int b1y,int b2x,int b2y)		//a1 and a2 is beging ,b1,b2 is end
{
	int i,j;
	int min_length;	
	int m,n,p,q;
	int** C;
	m=b1x-a1x;
	n=b1y-a1y;
	C=(int**)malloc(sizeof(int*)*(m+1));
	for(i=0;i<=m;i++)
	{
		*(C+1)=(int*)malloc(sizeof(int)*(n+1));
	}
	p=b2x-a2x;
	q=b2y-a2y;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<n;i++)
		{
			
		
int max_length(int A[10][],int B[10][],int ax,int ay,int bx,int by)
{
	int i,j;
	int m,n;
	m=bx-ax;
	n=by-ay;
	C[0][0]=0;
	int x_min,y_max;
	for(i=0;i<=m;i++)
	{
		
		for(j=0;i<=n;j++)
		{
			if(j>0)
			{
				x_min=C[i][j-1]+A[i+ax][j+ay-1];
			}
			else 
			{
				x_min=10000;
			}
			if(i>0)
			{
				y_min=C[i-1][j]+B[i+ax-1][j+ay];
			}
			else
			{
				y_min=10000;
			}
			if(x_min>y_min)
			{
				C[i][j]=y_min;
			}
			else
			{
				C[i][j]=x_min;		
			}
		}
	}
	printf("%d\n",A[m][n]);
}
void main()
{
	
	
