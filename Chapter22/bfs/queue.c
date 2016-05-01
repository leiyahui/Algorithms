#include"queue.h"
bool queue_init(queue* que)
{
	que->front=que->rear=(node*)malloc(sizeof(node));
	if(que->front==NULL)
	{
		printf("init fail\n");
		return false;		//malloc failed
	}
	return true;
}
bool is_empty(queue* que)		// not empty
{
	if(que->front==que->rear)
	{
		return true;
	}
	return false;
}
void queue_insert(queue* que,int in_dest)
{
	node* in_node=(node*)malloc(sizeof(node));
	if(in_node==NULL)
	{
		printf("queue insert malloc fail\n");
		exit(0);
	}
	in_node->vertex_dest=in_dest;
	in_node->next=NULL;
	(que->rear)->next=in_node;
	que->rear=in_node;
}
int queue_del(queue* que)  //unfinished
{
	int out_dest;
	node* free_node;
	out_dest=((que->front)->next)->vertex_dest;
	free_node=que->front;
	que->front=(que->front)->next;
	free(free_node);
	return out_dest;
}
void queue_destroy(queue* que)
{
	while(que->front!=NULL)
	{
		que->rear=que->front->next;
		free(que->front);
		que->front=que->rear;
	}
}
