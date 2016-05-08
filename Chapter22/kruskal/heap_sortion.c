/*************************************************************************
	> File Name: heap_sortion.c
	> Author:leiyahui 
	> Mail:13269398812@163.com 
	> Created Time: 2016年05月07日 星期六 10时41分14秒
 ************************************************************************/

#include<stdio.h>
#include"heap_sortion.h"
void exchange_edge(edge_node* x,edge_node* y)
{
    Dis_Vertex tmp_weight;
    Vertex tmp_front,tmp_rear;
    tmp_weight=x->weight;
    tmp_front=x->front;
    tmp_rear=x->rear;
    x->weight=y->weight;
    x->front=y->front;
    x->rear=y->rear;
    y->weight=tmp_weight;
    y->front=tmp_front;
    y->rear=tmp_rear;
}
void max_heapify(edge_node e[],int num,int i)
{
    int left,right;
    int largest;
    int temp;
    left=2*i;
    right=2*i+1;
    largest=i;
    if(right<=num&&e[right-1].weight>e[i-1].weight)
    {
        largest=right;
    }
    if(left<=num&&e[left-1].weight>e[largest-1].weight)
    {
        largest=left;
    }
    if(largest!=i)
    {
        exchange_edge(e+i-1,e+largest-1);
        max_heapify(e,num,largest);
    }
}
void create_max_heap(edge_node e[],int num)
{
    int i;
    for(i=num/2;i>=1;i--)
    {
        max_heapify(e,num,i);
    }
}
void heap_sortion(edge_node e[],int num)
{
    int i;
    create_max_heap(e,num);
    for(i=1;i<num;i++)
    {
        exchange_edge(e,e+num-i);
        max_heapify(e,num-i,1);
    }
}
    
    
