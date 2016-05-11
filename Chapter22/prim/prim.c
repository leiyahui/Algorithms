

/*************************************************************************
	> File Name: prim.c
	> Author:leiyahui 
	> Mail:13269398812@163.com 
	> Created Time: 2016年05月08日 星期日 18时45分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
#include"edge_stack.h"
void prim(item vertex[],int numV,int s)
{
    int i;
    edge_link* link;
    link=(edge_link*)malloc(sizeof(edge_link));
    edge_adj* curr_node;
    edge* curr_edge;
    for(i=0;i<numV;i++)
    {
        vertex[i].color=WHITE;
        vertex[i].par=0;
    }
    vertex[s].color=BLACK;
    init_link(link);
    curr_edge=vertex[s].adj;
    while(curr_edge!=NULL)
    {
        if(vertex[curr_edge->dest].color==WHITE)
        {
            insert_link(link,curr_edge->dest,s,curr_edge->weight);
        }
        curr_edge=curr_edge->next;
    }
    while(!is_empty(link))
    {
        curr_node=del_min_link(link);
        vertex[curr_node->dest].color=BLACK;
        printf("%c %c %d\n",vertex[curr_node->par].data,vertex[curr_node->dest].data,curr_node->weight);
        curr_edge=vertex[curr_node->dest].adj;
        while(curr_edge!=NULL)
        {
           if(vertex[curr_edge->dest].color==WHITE)
           {
                insert_link(link,curr_edge->dest,curr_node->dest,curr_edge->weight);
           }
           curr_edge=curr_edge->next;
        }
        free(curr_node);
    }
}
void main()
{
    item vertex[9];
    graph_create(vertex,9,14);
    prim(vertex,9,0);
}
























