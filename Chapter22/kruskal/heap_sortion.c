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
    y->front=tmp->front;
    y->rear=tmp_rear;
}
void max_heapify(edge_node e[],int num,int i)
{
    int left,right;
    int largest;
    int temp;
    if(i%2)
    {
        left=i/2;
        right=i/2+1;
    }
    else
    {
        left=right=i/2;
    }
    largest=i;
    if(right<=num&&e[right].weight>e[i].weight)
    {
        largest=right;
    }
    if(A[left]>A[largest])
    {
        largest=left;
    }
    if(largest!=i)
    {
        exchange_edeg(e+i,e+largest);
        max_heapify(e,num,largest);
    }
}
void create_max_heap(edge_node e[],int num)
{
    int i;
    i=num/2;        //max none leaf node
    for(i=num/2;i>=0;i--)
    {
        max_heapify(e,num,i);
    }
}
void heap_sortion(edge_node e[],int num)
{
    int i;
    create_max_heap(e,num);
    for(i=0;i<num-1;i++)
    {
        exchange(e+0,e+num-i-1);
        max_heapify(e,num-i-1,0);
    }
}
    
    
