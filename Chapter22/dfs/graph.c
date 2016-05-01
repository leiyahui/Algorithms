#include"graph.h"
bool graph_create(item vertex[],int numV,int numE)
{
	int vi,vj;
	Dis_Vertex weight;
	int i;
	edge* curr,*p;
	//input vertices
	printf("input vertex information\n");
	for(i=0;i<numV;i++)
	{
		printf("%d:",i);
		scanf("\n%c",&vertex[i].data);
		vertex[i].adj=NULL;
	}
	//input edges
	printf("input edge information\n");
	for(i=0;i<numE;i++)
	{
		printf("%d:",i);
		scanf("%d,%d,%d",&vi,&vj,&weight);
		curr=(edge*)malloc(sizeof(edge));
		if(curr==NULL)
		{
			printf("malloc fail\n");
			return false;
		}
		curr->dest=vj;
		curr->weight=weight;
		curr->next=NULL;
		if(vertex[vi].adj==NULL)		//first input edge of this vertice
		{
			vertex[vi].adj=curr;
		}
		else
		{
			p=vertex[vi].adj;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=curr;
		}
	}
	return true;
}
