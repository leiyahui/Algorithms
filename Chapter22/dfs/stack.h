#include"graph.h"
typedef struct _node
{
	int dest;		//vertex's subscript
	struct _node* next;
}node,p_node;
typedef struct _stack
{
	node* top;
	node* bottom;
}stack,p_stack;
void stack_init(p_stack* s);
void push(p_stack* s,int dest);
int pop(p_stack* s);
bool is_empty(p_stack* s);
void clear_stack(p_stack* s);
void destroy(p_stack* s);
void stack_init(p_stack* s)
{
	s->top=s->bottom=(node*)malloc(sizeof(node));
	if(s->bottom=NULL)
	{
		printf("stack_init malloc fail\n");
		exit(0);
	}
}
void push(p_stack* s,int dest)
{
	node* curr_node;
	curr_node=malloc(sizeof(node));
	if(curr_node=NULL)
	{
		printf("push malloc fail\n");
		exit(0);
	}
	curr_node->dest=dest;
	curr_node->next=s->top;
	s->top=curr_node;
}
int pop(p_stack* s)
{
	int out_dest;
	node* free_node=s->top;
	out_dest=free_node->dest;
	s->top=free_node->next;
	free(free_node);
	return out_dest;
}
bool is_empty(p_stack* s)
{
	if(s->top==s->bootom)
	{
		return true;
	}
	return false;
}
void clear_stack(p_stack* s)
{
	pnode curr_node;
	while(s->top!=s->bottom)
	{
		curr_node=s->top;
		s->top=(s->top)->next;
		free(curr_node);
	}
}
void destroy(p_stack* s)
{
	clear_stack(s);
	free(s->bottom);
}
		
	
	
		
