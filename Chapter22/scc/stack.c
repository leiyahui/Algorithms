#include "stack.h"
void stack_init(stack* s)
{
	s->top=s->bottom=(node*)malloc(sizeof(node));
	if(s->bottom==NULL)
	{
		printf("stack_init malloc fail\n");
		exit(0);
	}
}
void push(stack* s,edge* stack_edge)
{
	node* curr_node;
	curr_node=(node*)malloc(sizeof(node));
	if(curr_node==NULL)
	{
		printf("push malloc fail\n");
		exit(0);
	}
	curr_node->search_edge=stack_edge;
	curr_node->next=s->top;
	s->top=curr_node;
}
edge* pop(stack* s)
{
	edge* out_edge;
	node* free_node=s->top;
	out_edge=free_node->search_edge;
	s->top=free_node->next;
	free(free_node);
	return out_edge;
}
edge* get_top(stack* s)
{
	return (s->top)->search_edge;
}
bool is_empty(stack* s)
{
	if(s->top==s->bottom)
	{
		return true;
	}
	return false;
}
void clear_stack(stack* s)
{
	p_node curr_node;
	while(s->top!=s->bottom)
	{
		curr_node=s->top;
		s->top=(s->top)->next;
		free(curr_node);
	}
}
void destroy(stack* s)
{
	clear_stack(s);
	free(s->bottom);
}
		
