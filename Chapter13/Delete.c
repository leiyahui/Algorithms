#include<stdio.h>
#define RED 0
#define BLACK 1
typedef struct  _node
{
	int data;
	bool color;	//true is black,false is red
	node* left;
	node* right;
	node* p;	
}node,node_list;
void transplant(Node* x,Node* y)
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
void rb_delete_fixup(node* x);
{
	node* y;
	while(x->p!=NULL&&x->color==BLACK)
	{
		if(x==(x->p)->left)
		{
			y=(x->p)->right;
			if(y->color==RED)
			{
				(x->p)->color=RED;
				y->color=BLACK;
				left_rotate(x->p);
			}
			else if(y->left==BLACK&&y->right==BLACK)
			{
				y->color=RED;
				x=x->p;
			}
			else if(y->right==BLACK)
			{
				y->color=RED;
				(y->left)->color=BLACK;
				right_rotate(y);
			}
			else
			{
				y->color=(x->p)->color;
				(x->p)->color=BLACK;
				(y->right)->color=BLACK;
				right_rotate(x->p);
			} 	
		}
		else
		{
			y=(x->p)->left;
			if(y==RED)
			{
				y->color=BLACK;
				(x->p)->color=RED;
				right_rotate(x->p);
			}
			else if(y->left==BLACK&&y->right=BLACK)
			{
				y->color=RED;
				x=x->p;
			}
			else if(y->left==BLACK)
			{
				y->color=RED;
				(y->right)->color=BLACK;
				left_rotate(y);
			}
			else
			{
				y->color=(x->p)->color;
				(x->p)->color=BLACK;
				(y->left)->color=BLACK:
				left_rotate(x->p);
			}
		}
}
	
void rb_delete(node* root,node* x)
{
	node* y,t;
	int org_color;
	org_color=x->color;
	if(x->left==NULL)
	{
		y=t=x->right;
		transplant(x,y);
	}
	else if(x->right==NULL)
	{
		y=t=x->left;
		transplant(x,y);
	}
	else
	{
		y=Tree_Successor(x);
		t=y->right;
		org_color=y->color;
		if(y=x->right)
		{
			transplant(x,y);
			y->left=x->left;
			if(x->left!=NULL)
			{
				(x->left)->p=y;
			}
		}
		else
		{
			transplant(y,y->right);
			transplant(x,y);
			y->left=x->left;
			y->right=x->right;
			if(x->left!=NULL)
			{
				(x->left)->p=y;
			}
			if(x->rigt!=NULL)
			{
				(x->right)->p=x;
			}
		}
		
		y->color=z->color;
	}
	if(org_color==BLACK)
	{
		rb_delete_fixup(t);
	}
}

		
