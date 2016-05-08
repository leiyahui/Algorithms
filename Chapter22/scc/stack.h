#include"graph.h"
typedef struct _node
{
	edge* search_edge;		//vertex's subscript
	struct _node* next;
}node,* p_node;
typedef struct _stack
{
	node* top;
	node* bottom;
}stack,* p_stack;
void stack_init(stack* s);
void push(stack* s,edge* dest);
edge* pop(stack* s);
edge* get_top(stack* s);
bool is_empty(stack* s);
void clear_stack(stack* s);
void destroy(stack* s);
		
	
	
		
