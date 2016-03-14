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

typedef struct Queue
{
	QLink front;
	QLink rear;
}
void InQueue(
void Preorder_Walk_Tree(Node	
