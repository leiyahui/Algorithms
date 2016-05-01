#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
typedef struct _node
{
	int vertex_dest;
	struct _node* next;

}node;
typedef struct _queue
{
	node* front;
	node* rear;
}queue;
bool queue_init(queue* que);
void queue_insert(queue* que,int in_dest);
bool is_empty(queue* que);
int queue_del(queue* que);
void queue_destroy(queue* que);

