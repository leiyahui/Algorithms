/*************************************************************************
	> File Name: disjoint_forest.c
	> Author:leiyahui 
	> Mail:13269398812@163.com 
	> Created Time: 2016年05月06日 星期五 09时29分11秒
 ************************************************************************/

#include<stdio.h>
typedef struct _node
{
    struct _node* parent;
    int rank;
}node;
node*  s[1000];     //save parent node;
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

