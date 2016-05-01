#include<stdio.h>
#include<stdlib.h>
typedef int bool;
#define M 1024
#define true 1
#define false 0
typedef struct _b_tree
{
	_b_tree* p_node;		//parent node
	_b_tree* c_node[M];		//child node pointer
	int key_num;		//key_num<1024
	int key[M];		//key_pointer,first one isn't used
	bool is_leaf;
}b_tree;
typedef struct _ret_node
{
	b_tree* node;
	int i;
}ret_node;
ret_node* b_tree_search(b_tree* x,int key)
{
	int i;
	ret_node* p_ret;
	while(i<=x->key_num&&key<x->key[i])
	{
		i++;
	}
	if(i<=x->key_num&&key==x->key[i])
	{
		p_ret=(ret_node*)malloc(sizeof(ret_node));
		p_tre->node=x;
		p_tre->i=i;
	}
	else if(x->leaf==true)
	{
		return NULL;
	}
	else 
	{
		DISK_READ(x,ci);
		return b_tree_search(x->key[i],k);
	}
}
void b_tree_split(b_tree* x,int i)
{
	int j;
	b_tree* left_node;
	b_tree* right_node;
	right_node=x->c_node[i];
	//corporate left_node
	left_node=(b_tree*)malloc(sizeof(b_node));
	left_node->key_num=M/2-1;
	left_node->p_node=x;
	left_node->is_leaf=right_node->is_leaf;
	for(j=1;j<=M/2-1;j++)
	{
		left_node->key[j]=right_node->key[j];
	}
	if(right_node->is_leaf!=true)
	{
		for(j=0;j<M/2;j++)
		{
			left_node->c_node[j]=right_node->c_node[j+M/2];
		}
	}
	//corporate parent_node
	for(j=x->key_num+1;j>=i+1;j--)
	{
		x->key[j]=x->key[j-1];
	}
	x->key[i]=right_node->key[M/2];
	for(j=x->key_num+2;j<=i+2;j--)
	{
		x->c_node[j]=x->c_node[j-1];
	}
	x->cnode[i+1]=left_node;
	x->key_num+=1;
	//corporate right_node
	right_node->key_num=M/2-1;
	DISK_WRITE(right_node);
	DISK_WRITE(left_node);
	DISL_WRITE(x);
}	
		
b_tree* b_tree_insert(b_tree* x,int k)		//is change root node return pointer else return null
{
	if(x->key_num==M/2-1)			//root is full
	{
		b_tree* new_root;
		new_root=(b_tree*)malloc(sizeof(b_tree));
		new_root->is_leaf==false;
		new_root->c_node[1]=x;
		new_root->key_num=0;
		b_tree_split(new_root,1);
		b_tree_insert_nonfull(new_root,k);
		return new_root;
	}
	b_tree_insert_nonfull(x,k);
	return null;
}
void b_tree_insert_nonfull(b_tree* x,k)
{
	int i;
	i=x->key_num;
	if(x->is_leaf==true)
	{
		while(i>=1&&k<x->key[i])
		{
			i--;
			x->key[i+1]=x->key[i];
		}
		x->key[i+1]=k;
	}
	else
	{
		while(i>=1&&k<x->key[i])
		{
			i--;
		}
		i+=1;
		DISK_READ(x->c_node[i])
		if((x->c_node[i])->key_num==M/2-1)
		{
			b_tree_split(x,i);
			if(k>x->key[i])
			{
				i+=1;
			}
		}
		b_tree_insert_nonfull(x->key[i],k);
	}
}	
































		
		
		























	

