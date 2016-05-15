#include"graph.h"
int extract_min_vertex(item vertex[],int num_v)
{
    int min_subscript;
    int min_dest;
    int i;
    min_dest=INT_MAX;
    for(i=0;i<num_v;i++)
    {
        if(min_dest>vertex[i].dest&&vertex[i].color==WHITE)
        {
            min_dest=vertex[i].dest;
            min_subscript=i;
        }
    }
    return min_subscript;
}
void releax(item vertex[],int from,int end,int weight)
{
    if(vertex[end].dest>vertex[from].dest+weight)
    {
        vertex[end].dest=vertex[from].dest+weight;
    }
}
void dijkstra(item vertex[],int s,int num_v)
{
    int i;
    int min_subscript;
    edge* curr_edge;
    for(i=0;i<num_v;i++)
    {
        vertex[i].color=WHITE;
        vertex[i].dest=INT_MAX;
    }
    vertex[s].dest=0;
    for(i=0;i<num_v;i++)
    {
        min_subscript=extract_min_vertex(vertex,num_v);
        vertex[min_subscript].color=BLACK;
        curr_edge=vertex[min_subscript].adj;
        while(curr_edge!=NULL)
        {
            releax(vertex,min_subscript,curr_edge->dest,curr_edge->weight);
            curr_edge=curr_edge->next;
        }
    }
}
void main()
{
    item vertex[5];
    int i;
    graph_create(vertex,5,10);
    dijkstra(vertex,0,5);
    for(i=0;i<5;i++)
    {
        printf("%d\n",vertex[i].dest);
    }
}
               
        
