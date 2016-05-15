/*************************************************************************
	> File Name: edge.h
	> Author:leiyahui 
	> Mail:13269398812@163.com 
	> Created Time: 2016年05月11日 星期三 10时03分36秒
 ************************************************************************/

#ifndef _EDGE_H
#define _EDGE_H
#include"graph.h"
typedef struct _w_edge
{
    int from;
    int end;
    int weight;
}w_edge;
typedef struct _queue
{
    w_edge* all_edge;
}queue;
queue* init_queue(int num_v);
int in_queue(queue* que,item vertex[],int num_v);
w_edge* get_queue(queue* que,int i);
void destroy_queue(queue* que);
#endif
