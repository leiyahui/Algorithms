#include"faster_all_pairs_shortest_path.h"
static int min_num(long a,long b)
{
    if(a>b)
    {
        return b;
    }
    return a;
}
static void extend_short_path(int** vertex,int** vertex_before,int** vertex_adj,int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            vertex[i][j]=INT_MAX;
            for(k=0;k<n;k++)
            {
                vertex[i][j]=min_num((long)vertex[i][j],(long)(vertex_before[i][k]+vertex_adj[k][j]));
            }
        }
    }
}
int** faster_all_pairs_shortest_path(int** vertex_adj,int n)
{
    int i,j;
    int **vertex_a;
    int **vertex_b;
    vertex_a=dynamic_malloc_array(n,n);
    vertex_b=dynamic_malloc_array(n,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
             vertex_b[i][j]=vertex_adj[i][j];
        }
    }
    for(i=1;i<n-1;i++)
    {
        if(i%2)
        {
            extend_short_path(vertex_a,vertex_b,vertex_adj,n);
        }
        else
        {
            extend_short_path(vertex_b,vertex_a,vertex_adj,n);
        }
    }
    if((n-1)%2)
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
    int** vertex_adj;
    int** vertex;
    int i,j;
    vertex_adj=create_graph(5);
    vertex=faster_all_pairs_shortest_path(vertex_adj,5);
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d ",vertex[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    free_array(vertex_adj);
    free_array(vertex);
}

        

                
