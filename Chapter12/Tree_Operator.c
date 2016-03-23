#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	node* left;
	node* right;
}Node,*NodeList;
Node* Search_Tree(Node* node,k)	//Search a Node whose key equals to k in recursion
{
	if(node!=NULL)
	{
		if(node->data==k)
		{
			return node;
		}
		else if(node->data<k)
		{
			return Tree_Search(node.left,k);
		}
		else
		{
			return Tree_Search(node.right,k);
		}
	}
	else
	{
		return NULL;
	}
}	
Node* Search_Tree(Node* node,k)	//Search a Node whose key equals to k in loop
{
	while(node->data!=k&&node!=NULL)
	{
		if(node.data<k)
		{
			node=node->left;
		}
		else
		{
			node=node->right;
		}
		
	}
	return node;
}
Node* Tree_Maximum(Node* node)    //return the maximum value of the tree
{
	while(node->right!=NULL)
	{
		node=node->right;
	}
	return node;
}
Node* Tree_Minimum(Node* node)	//return the mimimum value of the tree
{
	while(node->left!=NULL)
	{
		node=node->left;
	}
	return node;
}
Node* Tree_Successor(Node* node)	//retrun the succesor of the node
{
	Node* y;
	if(node->right!=NULL)
	{
		return Tree_Minimum(node->right);
	}
	y=node->p;
	while(y!=NULL&&node==y->right)
	{
		node=y;
		y=node.p;
	}
	return y;
}
Node* Tree_Predecessor(Node* node)		//return the predecessor of the node
{
	Node* y;
	if(node->left!=NULL)
	{
		return Tree_Maximum(node->left);
	}
	y=node->p;
	while(y!=NULL&&node==y->left)
	{
		node=y;
		y=node->p;
	}
	return y;
}
void Tree_Insert(Node* T,int z)		//insert x to T
{
	Node nodeX;
	Node nodeY;
	NodeList nList;
	nodeX=*T;
	nodeY=NULL;
	while(X!=NULL)
	{
		nodeY=nodeX;
		if(z<nodeX.data)
		{
			nodeX=*(nodeX.left);
		}
		else
		{
			nodeY=*(nodeY.right);
		}
	}
	nList=(NodeList)malloc(sizeof(Node));
	nList->data=z;
	nList->p=&nodeY
	nList->left=nList->right=NULL;
	if(z<nodeY.data)
	{
		nodeY.left=nList;
	}
	else
	{
		nodeY.right=nList;
	}
}
void Transplant(Node* x,Node* y)
{
	if((x->p)->left==x)
	{
		(x->p)->left=y;
	}
	else
	{
		(x->p)->right=y;
	}
	if(y!=NULL)
	{
		y->p=x->p;
	}
}
	
void Tree_Delete(Node* x)		//Delete x from T
{
	Node* node_ptr;
	if(x->left==NULL)
	{
		Transplant(x,x->right);
	}
	else if(x->right==NULL)
	{
		Transplant(x,x->left);
	}
	else
	{
		node_ptr=Tree_Soccessor(x);
		if(node_ptr.p!=x)
		{
			Transplant(node_ptr,node_ptr.right);  //replace node_ptr while node_ptr's right child
			node_ptr->right=x->right;		//change z's right child into y's rightchild
			(node_ptr->right)->p=node_ptr;
		}
		Trasnplant(x,node_ptr);
		node_ptr->left=x->left;
		(node_ptr->left)->p=node_ptr;
	}	
}				 	







