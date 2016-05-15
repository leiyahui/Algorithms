#include"relax.h"
#include"edge.h"
#include"graph.h"
bool bellman_ford(item vertex[],int s,int num_v,int num_e)
{
    queue* que;
    int *dest;
    int i,j;
    que=init_queue(num_e);
    in_queue(que,vertex,num_v);
    for(i=0;i<num_v;i++)        //init 
    {
        vertex[i].dest=INT_MAX;
    }
    vertex[s].dest=0;
    for(i=0;i<num_v;i++)
    {
        for(j=0;j<num_e;j++)
        {
            relax(que,vertex,j);
        }
    }
    for(i=0;i<num_e;i++)
    {
        if(vertex[que->all_edge[i].end].dest>vertex[que->all_edge[i].from].dest+que->all_edge[i].weight)
        {
            printf("there is a loop\n");
            return false;
        }
    }
    return true;
}
void main()
{
    int i;
    item vertex[5];
    graph_create(vertex,5,10);
    bellman_ford(vertex,0,5,10);
    for(i=0;i<5;i++)
    {
        printf("%d\n",vertex[i].dest);
    }
}
