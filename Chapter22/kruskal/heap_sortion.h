/*************************************************************************
	> File Name: heap_sortion.h
	> Author:leiyahui 
	> Mail:13269398812@163.com 
	> Created Time: 2016年05月07日 星期六 10时30分55秒
 ************************************************************************/
#include"graph.h"
#ifndef _HEAP_SORTION_H
#define _HEAP_SORTION_H
typedef struct _edge_node
{
    Vertex front;
    Vertex rear;
    Dis_Vertex weight;
}edge_node;             
void max_heapify(edge_node e[],int i);        //maintain max heap
void build_max_heap(edge_node e[],int num);     //creat max heap
void heap_sortion(edge_node e[],int num);       //sort edge_node by edge_node.weight
    
#endif
