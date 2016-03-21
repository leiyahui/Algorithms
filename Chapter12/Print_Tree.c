
#include<stdio.h>
#include<stdlib.h>
typedef struct _tnode
{
	char data;
	_tnode* left;
	_tnode* right;
	_tnode* parent;
}tnode,*tnode_ptr;
typedef struct _qnode
{
	tnode node;
	int depth;
	_qnode* parent;		//save the pointer of parent node;
	_qnode* next;		//save the pointer of next node;
}qnode,*qnode_list
typedef struct _queue
{
	qnode_list front;
	qnode_list rear;
}queue;
void create_queue(queue* q)
{
	q->front=(qnode_list)malloc(sizeof(qnode));
	(q->front)->next=NULL;
	q->rear=q->front;
}	
void en_queue(queue* q,tnode* tree_node)
{
	qnode_list node_list;
	node_list=(node_list)malloc(sizeof(qnode));
	node_list->node=*tree_node;
	node_list->next=NULL;	
	node_list->parent=
	(q->rear)->next=nodeLink;
	(q->rear)=nodeLink;
}
bool de_queue(queue* q,tnode* tree_node)
{
	qnode_list node_list;
	if(is_empty(q))
	{
		return false;
	}
	*tree_node=((q->front)->next)->node;
	node_list=q->front;
	q->front=(q->front)->next;
	free(node_list);
	return true;
}	
bool is_empty(queue* q)
{
	if(q->front==q->rear)
	{
		return true;
	}
	return false;
}
void destroy_queue(queue* q)
{
	qnode_list node_list;
	while(q->front!=NULL)
	{
		node_list=q->front;
		q->front=(q->front)->next;
		free(node_list);
	}
}

void print_tree(tnode_ptr root)
{
	queue que;
	tnode_ptr curr_node;
	tnode_ptr parent_node;
	int i;
	curr_node=root;
	i=0,j;
	while(curr_node!=NULL)		//calculate the left space
	{
		curr_node=curr_node->left;
		i++;
	}
	create_queue(&que);
	en_queue(&que,root);
	for(j=0;j++;j<i)		//print the left space of root node
	{
		printf("   ");
	}
	printf("%c",root->data);
	parent_node=root;
	while(de_queue(&que,curr_node))
	{
		if(curr_node->left!=NULL)
		{
			en_queue(&que,curr_node->left);
			if(curr_node->parent==parent_node)
			{
				
		}
		if(curr_node->right!=NULL)
		{
			en_queue(&que,curr_node->right);
		}
