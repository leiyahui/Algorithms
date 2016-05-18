#include"graph.h"
int** create_graph(int n)
{
    FILE* fp;
    int **vertex;
    int x,y,weight;
    int i,j;
    /*malloc for the two-dimension array*/
    vertex=dynamic_malloc_array(n,n);
    if(vertex==NULL)
    {
         return NULL;
    }
    /*init two-dimension array*/
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            vertex[i][j]=INT_MAX;
        }
    }
    fp=fopen("edge.txt","r");
    fscanf(fp,"%d,%d,%d",&x,&y,&weight);
    while(!feof(fp))
    {
         vertex[x][y]=weight;
         printf("%d\n",weight);
         fscanf(fp,"%d,%d,%d",&x,&y,&weight);
    }
    return vertex;
    
}
