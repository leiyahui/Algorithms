/*************************************************************************
	> File Name: kruskal.c
	> Author:leiyahui 
	> Mail:13269398812@163.com 
	> Created Time: 2016年05月06日 星期五 10时35分55秒
 ************************************************************************/

#include<stdio.h>
#include"graph.h"
#include"heap_sortion.h"
typedef struct _node
{
    struct _node* parent;
    int rank;
}node;
node*  s[26];     //save parent node;
void make_set(int x)
{
    s[x]=(node*)malloc(sizeof(node));
    s[x]->rank=0;
    s[x]->parent=s[x];
}
node* find_set(int x)       
{
    if(s[x]->parent!=x)
    {
        s[x]->parent=find_set(s[x]);
    }
    return s[x];
}
void link_set(int x,int y)
{
    if(s[x]->rank>s[y]->rank)
    {
        s[y]->parent=s[x];
    }
    else 
    {
        s[x]->parent=s[y];
        if(s[x]->rank==s[y]->rank)
        {
            s[y]->rank++;
        }
    }
}
void union_set(int x,int y)
{
    link_set(find_set(x),find_set(y));
}
int hash_vertex(Vertex v)
{
    int i;
    i=(int)v-97;
    return i;
}
void kruskal(item vertex[],int numV,int numE)
{
    edge_node e[numE];
    int i,j;
    Vertex front,rear;
    int hash_value_front,hash_value_rear;
    edge* curr_edge;
    j=0;
    for(i=0;i<numE;i++)     //get edge
    {
        curr_edge=vertex[i].adj;
        while(curr_edge!=NULL)
        {
            e[j].front=vertex[i].data;
            e[j].rear=vertex[curr_edge->dest].data;
            e[j].weight=curr_edge->weight;
            curr_edge=curr_edge->next;
            j++;
        }
    }
    heap_sortion(e,numE);
    for(i=0;i<numV;i++)
    {
        hash_value_front=hash_vertex(vertex[i].data);
        make_set(hash_value_front);
    }
    for(i=0;i<numE;i++)
    {
        front=e[i].front;
        rear=e[i].rear;
        hash_value_front=hash_vertex(front); 
        hash_value_rear=hash_vertex(rear);
        if(find_set(hash_value_front)!=find_set(hash_value_rear))
        {
            union_set(hash_value_front,hash_value_rear);
            printf("%d %d\n",front,rear);
        }
    }
}
void main()
{
    item vertex[100];
    graph_create(vertex,9,14);
    kruskal(vertex,8,14);
}
    
    




     


