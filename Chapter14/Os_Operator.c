#include<stdio.h>
#define BLACK 	0
#define RED 	1
node* os_select(node* root,int i)		//select i from tree
{
	int l;
	l=(root->left)->size+1;
	if(l==i)
	{
		return root;
	}
	else if(l<i)
	{
		return os_select(root->left,i);
	}
	else
	{
		return os_select(root->right,i-l-1);
	}
}
int os_rank(node* x)			//count the rank of x 
{
	int count;	
	node* y;
	count=0;
	if(x->left!=NULL)
	{
		count+=(x->left)->size+1;
	}
	y=x->p;
	while(y!=NULL)
	{
		if(x==y->right)
		{
			count=count+(y->left)->size+1;
		}
		x=y;
		y=x->p;
	}
	return count;
}
void os_insert_fixup(node* x)		//fixup the order static tree which inserted node
{
	while((x->p)->color==RED)
	{
		if(((x->p)->p)->left==x->p) 	//parent is grandparents left child
		{
			y=(x->p)->right;
			if(y->color==RED)
			{
				(x->p)->color=y->color=BLACK;
				((x->p)->p)->color=RED;
				x=(x->p)->p;
			}
			else if(x=(x->p)->right)
			{
				x=x->p;
				left_rotate(x);
			}
			else
			{
				(x->p)->color=BLACK;
				((x->p)->p)-color=RED;
				right_rotate((x->p)->p);
			}
		}
		else
		{
			y=(x->p)->left;
			if(y->color==RED)
			{
				(x->p)->color=y->color=BLACK;
				((x->p)->p)->color=RED;
				x=(x->p)->p;
			}
			else if(x=(x->p)->left)
			{
				x=x->p;
				right_rotate(x);
			}
			else
			{
				(x->p)->color=BLACK;
				((x->p)->p)->color=RED;
				left_rotatte((x->p)->p);
			}
		}	
	}                           
}
				
		
void os_insert(node* root,node* x)		//insert x to the tree
{	
	node* y,p;
	y=root;
	if(root==NULL)
	{
		root=x;
		root->size=1;
	}
	else
	{
		while(y!=NULL)
		{
			p=y;
			p->size+=1;
			if(x->data<y->data)
			{
				y=y->left;
			}
			else	
			{
				y=y->right;
			}
		}
	}
	x->p=p;
	if(x->data<p->data)
	{
		p->left=x;
	}
	else
	{
		p->right=x;
	}
	x->left=x->right=NULL;
	x->color=RED;
	os_insert_fixup(x);
}
void os_delete_fixup(x)
{
	node* y;
	while(x->color==BLACK)
	{
		if(x=(x->p)->left)
		{
			y=(x->p)->right;
			if(y->color==RED)
			{
				(x->p)->color=BLACK;
				y->color=RED;
			 	left_rotate(x->p);
			}
			else if((y->right)->color==BLACK&&(y->left)->color==BLACK)
			{
				y->color=RED;
				x=x->p;
			}
			else if((y->right)->color==BLACK)
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
				left_rotate(x->p);
			}
		}
		else
		{
					//unfinished	
		}
	}
	x->color=BLACK;
void os_delete(node* x)
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
		y=tree_minimum(y->right);
		org_color=y->color;
		t=y->right;
		if(y=x->right)
		{
			y->left=x->left;
			transplant(x,y);
			if(x->left!=NULL)
			{
				(x->left)->p=y;
			}
			y->p=x->p;
		}
		else
		{
			transplant(y,y->right);
			(y->right)->p=y->p;
			(y->p)->left=y->right;
		}
		y->color=x->color;
	}
	if(org_color==BLACK)
	{
		os_delete_fixup(t);
	}
}
