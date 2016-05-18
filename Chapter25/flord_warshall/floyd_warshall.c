#include"graph.h"
static int min_num(long a,long b)
{
    if(a>b)
    {
        return b;
    }
    return a;
}
int** floyd_warshall(int** vertex_adj,int n)
{
    int **vertex_a;
    int **vertex_b;
    int i,j,k;
    vertex_a=dynamic_malloc_array(n,n);
    vertex_b=dynamic_malloc_array(n,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            vertex_b[i][j]=vertex_adj[i][j];
        }
    }
    for(k=1;k<n;k++)
    {
        if(k%2)
        {
             for(i=0;i<n;i++)
            {
                 for(j=0;j<n;j++)
                  {
                        vertex_a[i][j]=min_num(vertex_b[i][j],(long)vertex_b[i][k]+vertex_b[k][j]);
                  }
            }
        }
        else
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    vertex_b[i][j]=min_num(vertex_a[i][j],(long)vertex_a[i][k]+vertex_a[k][j]);
                }
            }
        }
    }
    if(n%2)
    {
        free_array(vertex_a);
        return vertex_b;
    }
    else
    {
        free_array(vertex_b);
        return vertex_a;
    }
}
void main()
{
    int** vertex;
    int** vertex_adj;
    int i,j;
    vertex_adj=create_graph(5);
    vertex=floyd_warshall(vertex_adj,5);
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d ",vertex[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
