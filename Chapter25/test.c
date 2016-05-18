#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void array()
{
    int i;
    int a[5][5];
    printf("%d\n",a);
    for(i=0;i<5;i++)
    {
            printf("%d\n",a[i]);
    }
}

void dynamic_array()
{
    int **a;
    int i,j;
    a=(int**)malloc(sizeof(int*)*5);
    for(i=0;i<5;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*5);
    }
    printf("%d\n",a);
    for(i=0;i<5;i++)
    {
        printf("%d\n",a[i]);
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            a[i][j]=i*5+j;
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d ",a[i][j]);
        }
    }
    printf("\n");
}
void dynamic_malloc_all()
{
    int **a;
    int i,j;
    a=(int**)malloc(sizeof(int*)*5);
    a[0]=(int*)malloc(sizeof(int)*25);
    for(i=1;i<5;i++)
    {
        a[i]=a[i-1]+5;
    }
    printf("%d\n",a);
    for(i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            a[i][j]=i*5+j;
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d ",a[i][j]);
        }
    }
}
void stack_overflow(int a,int b)
{
    long c;
    c=(long)a+b;
    printf("%d\n",c);
}
void main()
{
 /*   array();
    dynamic_array();
    dynamic_malloc_all();*/
    printf("%d\n",sizeof(int));
    stack_overflow(INT_MAX,INT_MAX);
}
