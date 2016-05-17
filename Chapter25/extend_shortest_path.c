#include"graph.h"
int min_num(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}
void extend_short_path(int** vertex,int** vertex_before,int** adj_vertex,int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;i<n;j++)
        {
            vertex[i][j]=INT_MAX;
            for(k=0;k<n;k++)
            {
                vertex[i][j]=min_num(vertex[i][j],vertex_befor[i][k]+adj_vertex[k][j]);
            }
        }
    }
}
                
