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
void graph_transpose(item vertex[],item vertex_trans,int numV)
{
    int i;
    edge* curr_edge,temp_edge;
    for(i=0;i<numV;i++)
    {
        curr_edge=vertex[i].adj;
        while(curr_edge!=NULL)
        {
            if(vertex[curr_edge->dest].adj==NULL)
            {
                vertex_trans[curr_edge->dest].adj=(edge*)malloc(sizeof(edge));
                vertex_trans[curr_edge->dest].adj->dest=i;
                vertex_trans[curr_edge->dest].adj->next=NULL:
                vertex_trans[curr_edge->dest].adj->weight=curr_edge->weight;
            }
            else
            {
                temp_edge=vertex_trans[curr_edge->dest].adj;
                while(temp_edge!=NULL)
                {
                    temp_edge=temp_edge->next;
                }
                temp_edge=(edge*)malloc(sizeof(edge));
                temp_edge->dest=i;
                temp_edge->next=NULL:
                temp_weight=curr_edge->weight;
            }
        }
    }
}

void graph_time(item vertex[],int num)
{
    int i;
    for(i=0;i<num;i++)
    {
        printf("%c d:%d f:%d\n",vertex[i].data,vertex[i].d,vertex[i].f);
    }
}
