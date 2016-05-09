/*************************************************************************
	> File Name: edge_stakc.h
	> Author:leiyahui 
	> Mail:13269398812@163.com 
	> Created Time: 2016年05月09日 星期一 15时06分15秒
 ************************************************************************/

#ifndef _edge_adj_STAKC_H
#define _edge_adj_STAKC_H
#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
typedef struct _edge_adj
{
    int dest;
    int par;
    int weight;
    struct _edge_adj* next;
}edge_adj;
typedef struct _edge_link
{
    edge_adj* head;
    edge_adj* rear;
}edge_link;
void init_link(edge_link* link);
void insert_link(edge_link* link,int dest,int par,int weight);
int del_link(edge_link* link,int dest,int par);
edge_adj* del_min_link(edge_link* link);
bool is_empty(edge_link* link);
#endif
