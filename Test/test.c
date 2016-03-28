#include<stdio.h>
#include<stdlib.h>
void main()
{
	int* a;
	int i,n;
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		a[i]=i;
	}
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
