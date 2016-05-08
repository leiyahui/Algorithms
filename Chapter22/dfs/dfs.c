#include "stack.h"
void dfs(item vertex[],int num,int s)
{
	int i,time;
	edge* curr_edge;
    edge* temp_edge;
	stack sta;
	stack_init(&sta);
	for(i=0;i<num;i++)
	{
		vertex[i].color=WHITE;
	}
	time=1;
	for(i=0;i<num;i++)
	{
		if(vertex[i].color==WHITE)
		{
            printf("visit %c\n",vertex[i].data);
			curr_edge=vertex[i].adj;
            vertex[i].color=GRAY;
            vertex[i].d=time;
            time++;
            vertex[curr_edge->dest].color=GRAY;
            vertex[curr_edge->dest].d=time;
            time++;
            printf("visit %c\n",vertex[curr_edge->dest].data);
			push(&sta,curr_edge);
			curr_edge=get_top(&sta);
			while(curr_edge!=NULL)
			{
                temp_edge=vertex[curr_edge->dest].adj;
				while(temp_edge!=NULL&&vertex[temp_edge->dest].color!=WHITE)
				{
					temp_edge=temp_edge->next;
				}
				if(temp_edge!=NULL)
				{
					push(&sta,temp_edge);
                    vertex[temp_edge->dest].d=time;
                    time++;
                    printf("visit %c\n",vertex[temp_edge->dest].data);
					vertex[temp_edge->dest].color=GRAY;
				}
				else
				{
                    temp_edge=pop(&sta);
                    vertex[temp_edge->dest].f=time;
                    vertex[temp_edge->dest].color=BLACK;
                    time++;
				}
				curr_edge=get_top(&sta);
			}
            vertex[i].color=BLACK;
            vertex[i].f=time;
            time++;
		}
	}
}
void main()
{
    item vertex[10];
    graph_create(vertex,4,6);
    dfs(vertex,4,0);
    graph_time(vertex,4);
}



