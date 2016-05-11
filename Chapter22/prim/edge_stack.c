/*************************************************************************
	> File Name: edge_stack.c
	> Author:leiyahui 
	> Mail:13269398812@163.com 
	> Created Time: 2016年05月09日 星期一 15时18分09秒
 ************************************************************************/

#include<stdio.h>
#include"edge_stack.h"
void init_link(edge_link* link)
{
    link->head=link->rear=(edge_adj*)malloc(sizeof(edge_adj));
    if((link->head)==NULL)
    {
        printf("init malloc fail\n");
        exit(0);
    }
}
    
void insert_link(edge_link* link,int dest,int par,int weight)
{
    edge_adj* in_node;
    in_node=(edge_adj*)malloc(sizeof(edge_adj));
    in_node->dest=dest;
    in_node->par=par;
    in_node->weight=weight;
    in_node->next=NULL;
    (link->rear)->next=in_node;
    link->rear=in_node;
}
int del_link(edge_link* link,int dest,int par)
{
    edge_adj* curr_node,* p_curr_node;
    int key;
    p_curr_node=link->head;
    curr_node=(link->head)->next;
    while(curr_node!=NULL)
    {
        if(curr_node->dest==dest&&curr_node->par==par)
        {
            p_curr_node->next=curr_node->next;
            key= curr_node->weight;
            free(curr_node);
            return key;
        }
        p_curr_node=curr_node;
        curr_node=curr_node->next;
    }
    printf("link don't have the node");
}
edge_adj* del_min_link(edge_link* link)
{
    edge_adj* curr_node,* ret_node,* p_ret_node;
    p_ret_node=(link->head);
    curr_node=(link->head)->next;
    ret_node=(link->head)->next;
    while((curr_node->next)!=NULL)
    {
        if((curr_node->next)->weight<curr_node->weight)
        {
            ret_node=curr_node->next;
            p_ret_node=curr_node;
        }
        curr_node=curr_node->next;
    }
    p_ret_node->next=ret_node->next;
    return ret_node;
}
bool is_empty(edge_link* link)
{
    if(link->head==link->rear)
    {
        return true;
    }
    return false;
}
