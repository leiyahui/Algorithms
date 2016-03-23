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
void rb_insert_fix(node* x)
{
	node_list y;
	while(x->p==red)
	{
		if(((x->p)->p)->left==(x->p))
		{
			y=((x->p)->p)->right;
			if(y->color==RED)
			{
				y->color=BLACK;
				(x->p)->color=BLACK;
				((x->p)->p)->color=RED;
				x=(x->p)->p;
			}
			else if(x==(x->p)->right)
			{
				x=x.p;
				left_rotate(x);
			}
			else
			{
				(x->p)->color=BALCKk;
				((x->p)->p)->color=RED;
				right_rotate(((x->p)->p));
			}
		}
		else
		{
			y=((x->p)->p)->left;
			if(y->color==RED)
			{
				y->color=BLACK;
				(y->p)->color=RED;
				(x->p)->color=BLACK;
				x=(x->p)->P;
			}
			else if(x==(x->p)->left)
			{
				x=x->p;
				right_rotate(x);
			}
			else
			{
				(x->p)->color=BLACK;
				((x->p)->p)->color=RED;
				left_rotate(((x->p)->p));
			}
		}
	}
}
void Insert(nodelist root,nodelist x)
{
	node_list nlist;
	node_list par_list;
	nlist=par=root;
	while(nlist!=NULL)
	{
		par=nlist;
		if(nlist->data>x->data)
		{
			nlist=nlist->left;
		}
		else
		{
			nlist=nlist->right;
		}
	}
	if(nlist==root)
	{
		root=x;
	}
	else if(nlist==par->left)
	{
		x=par->left;
	}
	else
	{
		x=par->right;
	}	
	x->left=NULL;
	x->right=NULL;
	x->color=RED;
	x->p=par;
	rb_insert_fixup(x);
}
			
	
	      
