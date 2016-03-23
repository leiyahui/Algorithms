#include<stdio.h>
void left_rotate(node* x)
{
	node* y;
	y=x.right;
	y->p=x->p;
	if(x->p==NULL)
	{
		y->p=NULL;
	}
	else if(x==(x->p)->left)
	{
		y=(x->p)->left;
	}
	else
	{
		y=(x->p)->right;
	}
	x->right=y->left;
	if(x->right!=NULL)
	{
		(x->right)->p=x;
	}
	y->left=x;
	x->p=y;
}
void right_rotate(node* x)
{
	node* y;
	y=x->left;
	y->p=x->p;
	if(x->p==NULL)
	{
		;
	}
	else if(x=(x->p)->left)
	{
		y=(x->p)->left;
	}
	else
	{
		y=(x->p)->right;
	}
	x->left=y->right;
	if(y->right!=NULL)
	{
		(y->right)->p=x;
	}
	x->p=y;
	y->right=x;
}	
