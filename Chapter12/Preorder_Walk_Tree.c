#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	int p;
	node* left;
	node* right;
}Node;
typedef struct qNode
{
	Node node;
	qNode* next;
}QNode,*QLink;

typedef struct queue
{
	QLink front;
	QLink rear;
}Queue;
bool CreateQueue(Queue* que)
{
      	que->rear=que->front=(QLink)malloc(sizeof(QNode));
	if(que->rear==NULL)
	{
		return false;
	}
	que->front->next==NULL:
	return true;
}
void InQueue(Queue* que,Node node)
{
	QLink qLink=(QLink)malloc(sizeof(QNode));
	qLink->node=node;
	qLink->next=NULL;
	que->rear->next=qLink;
	que->rear=qLink;
}
bool DeQueue(Queue* que,Node* node)
{
	QLink qLink;
	if(IsEmpty(que))
	{
		return false;
	}
	*node=que->front->next->node;
	qLink=que->front;
	que->front=que->front->next;
	free(que->front);
	return true;
}
bool IsEmpty(Queue* que)
{
	if(que->rear==que->front)
	{
		return true;
	}
	return false;
}
void Preorder_Walk_Tree(Node node)
{
	Queue que;
	if(CreateQueue(&que))
	{
		InQueue(&que,node);
		Node tempNode;
		while(!IsEmpty(&que))
		{
			if(Dequeue(&que,&tempNode))
			{
				printf("%d ",tempNode.data);
				if(tempNode.left!=NULL)
				{
					InQueue(que,*(tempNode.left));
				}
				if(tempNode.right!=NULL)
				{
					InQueue(que,*(tempNode.right));
				}
			}
		}
	}	
}
				
				
