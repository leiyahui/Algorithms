#include"dynamic_malloc_array.h"
int** dynamic_malloc_array(int m,int n)
{
    int** pointer;
    int i;
    pointer=(int**)malloc(sizeof(int*)*m);
    if(pointer==NULL)
    {
        return NULL;
    }
    pointer[0]=(int*)malloc(sizeof(int)*m*n);
    if(pointer[0]==NULL)
    {
        free(pointer);
        return NULL;
    }
    for(i=1;i<m;i++)
    {
        pointer[i]=pointer[i-1]+n;
    }
    return pointer;
}
void free_array(int** pointer)
{
    free(pointer[0]);
    free(pointer);
}
