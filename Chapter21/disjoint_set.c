#include<stdio.h>
#include<stdlib.h>
struct _set;
typedef struct _node
{
	int i;
	_set* head_set;
	_node* next;
}node;
typedef struct _set
{
	_node* head;
	_node* tail;
}set;
void make_set(int i)
{
	set* head_set;
	node* head;
	head_set=(set*)malloc(sizeof(set));
	head=(node*)malloc(sizeof(node));
	//corporate first node
	head->i=i;
	head->head_set=head_set;
	head->next=NULL;
	//corporate head_set
	head_set->head=head;
	head_set->tail=head;
}
set* find_set(int i)
{
	13161884446	
	

