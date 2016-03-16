#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	node* p;
	node* left;
	node* right;
}Node;
typedef struct Snode
{
	Node node
	NodeList next;
}SNode,*SNodeList;
void Push(SNodeList* head,Node n)
{	
	SNodeList sList=(SNodeList)malloc(sizeof(SNode));
	sList.node=n;
	sList.next=*head;
	*head=sList;
}
bool Pop(SNodeList* head,Node* node)
{	
	if(head==NULL)
	{
		return false;
	}
	SNodeList sList;
	*node=head->node;
	sList=*head;
	*head=head->next;
	free(sList);
	return true;
}	
void Inorder_Walk_Tree(Node x);
{
	SNodeList head;
	Node n;
	head=NULL;
	n=x;
	while(n.left!=NULL)
	{
		n=n.left;
		Push(&head,n);
	}
	printf("%d ",n.data);
	while(head!=NULL)
	{
		Pop(&head,&n);
		printf("%d ",n.data);
		if(n.right!=NULL)
		{
			n=n.right;
			Push(&head,n);
		}
		while(n.left!=NULL)		//Search the right tree
		{
			n=n.left;
			Push(&head,n);
		}
		printf("%d ",n.data);
	}
}
void main()
{	
}
	
		
