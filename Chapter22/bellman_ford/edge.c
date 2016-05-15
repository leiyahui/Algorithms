#include"edge.h"
queue* init_queue(int num_v)
{
    queue* que;
    que=(queue*)malloc(sizeof(queue));
    if(que==NULL)
    {
        return NULL;
    }
    que->all_edge=(w_edge*)malloc(sizeof(w_edge)*num_v);
    if(que->all_edge==NULL)
    {
        free(que);
        return NULL;
    }
    return que;
}
int in_queue(queue* que,item vertex[],int num_v)
{
    int i,j;
    edge* curr_edge;
    j=0;
    for(i=0;i<num_v;i++)
    {
        curr_edge=vertex[i].adj;
        while(curr_edge!=NULL)
        {
             que->all_edge[j].from=i;
             que->all_edge[j].end=curr_edge->dest;
             que->all_edge[j].weight=curr_edge->weight;
             curr_edge=curr_edge->next;
             j++;
        }
    }
}
w_edge* get_queue(queue* que,int i)
{
    return que->all_edge+i*sizeof(w_edge);
}
void destroy_queue(queue* que)
{
    free(que->all_edge);
    free(que);
}
