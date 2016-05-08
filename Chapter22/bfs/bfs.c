/*************************************************************************
	> File Name: bfs.c
	> Author:leiyahui 
	> Mail:13269398812@163.com 
	> Created Time: 2016年05月07日 星期六 20时30分27秒
 ************************************************************************/

#include<stdio.h>
#include"queue.h"
void bfs(item vertex[],int numV,int s)
{
    int i;
    queue que;
    edge* curr_edge;
    for(i=0;i<numV;i++)
    {
        vertex[i].color=WHITE;
        vertex[i].par=0;
    }
    vertex[s].color=GRAY;
    queue_init(&que);
    queue_insert(&que,s);
    printf("%c\n",vertex[s].data);
    while(!is_empty(&que))
    {
        i=queue_del(&que);
        curr_edge=vertex[i].adj;
        while(curr_edge!=NULL)
        {
            if(vertex[curr_edge->dest].color==WHITE)
            {
                vertex[curr_edge->dest].color=GRAY;
                 vertex[curr_edge->dest].par=i;
                queue_insert(&que,curr_edge->dest);
                 printf("%c\n",vertex[curr_edge->dest].data);
             }
            curr_edge=curr_edge->next;
        }
        vertex[i].color=BLACK;
    }
    queue_destroy(&que);
}
 void main()
{
    item vertex[10];
    graph_create(vertex,9,14);
    bfs(vertex,9,0);
}
    
