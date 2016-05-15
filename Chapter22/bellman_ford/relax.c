#include"relax.h"
void relax(queue* que,item vertex[],int i)
{
    int from=que->all_edge[i].from;
    int end=que->all_edge[i].end;
    int weight=que->all_edge[i].weight;
    if(vertex[end].dest>vertex[from].dest+weight)
    {
        vertex[end].dest=vertex[from].dest+weight;
        vertex[end].par=from;
    }
}
    
    
