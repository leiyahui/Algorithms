#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	node* left;
	node* right;
}Node,*NodeList;
typedef struct snode
{
	Node node;
	snode* next;
}SNode,*SNodeList;
void Push(SNodeList* head,Node node)
{
	SNodeList nList;
	nList=(SNodeList)malloc(sizeof(SNode));
	nList->next=*head;
	nList->node=node;
	*head=nList;
}
bool Pop(SNodeList* head,Node* node)
{
	SNodeList nList;
	if(*head==NULL)
	{
		return 0;
	}
	node=(*head)->node;
	nList=*head;
	*head=(*head)->next;
	free(nList);
	return 1;
}
bool IsEmpty(SNodeList head)
{
	if(head==NULL)
	{
		return true;
	}
	return false;
}
void GetTop(SNodeList head,Node* node)
{
	*node=head->node;
} 			
Postorder_Walk_Tree(Node node)
{
	SNodeList head;
	head=NULL;
	Node tempNode;
	Push(&head,node);
	tempNode=node;
	while(tempNode.left!=NULL)
	{
		tempNode=*(tempNode.left)
		Push(&head,tempNode);
	}
	printf("%d ",tempNode.data);
	Pop(&head,&tempNode);
	while(!IsEmpty(head))
	{
		GetTop(head,&tempNode)
		{
			if(tempNode.right!=NULL)
			{
				tempNode=*(tempNode.right);
				Push(&head,tempNode);
			}
		}
		while(tempNode.left!=NULL)
		{
			tempNode=*(tempNode.left)
			Push(&head,tempNode);
		}
		
			

