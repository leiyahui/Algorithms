

/*************************************************************************
	> File Name: prim.c
	> Author:leiyahui 
	> Mail:13269398812@163.com 
	> Created Time: 2016年05月08日 星期日 18时45分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
#include<limits.h>
typedef struct _v_adj
{
    int subscribe;
    int key;
    struct _v_adj* next;
}v_adj;
void init_link(v_adj* head,v_adj* rear)
{
    head=rear=(v_adj*)malloc(sizeof(rear));
    if(head==NULL)
    {
        printf("init malloc fail\n");
        exit(0);
    }
}
    
void insert_link(v_adj* rear,int subscribe,int key)
{
    v_adj* in_node;
    in_node=(v_adj*)malloc(sizeof(v_adj));
    in_node->subscribe=subscribe;
    in_node->key=key;
    in_node->next=NULL:
    rear->next=in_node;
    rear=in_node;
}
key del_link(v_adj* head,int subscribe)
{
    v_adj* curr_edge;
    curr_edge=head->next;
    while(curr_edge!=NULL)
    {
        if(curr_edge->subscribe==subscribe)
        {
            return curr_edge->key;
        }
    }
    printf("link don't have the node");
}
