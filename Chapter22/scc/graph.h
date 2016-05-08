#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX_ VERTEX 	100		//max number of vertices
#define WHITE		1
#define GRAY		2
#define BLACK		3
#define true		1
#define false		0
typedef int bool;
typedef char Vertex;
typedef int  Dis_Vertex;
//graph struct
typedef struct _edge
{
	int dest;		//subscript of vertice
	Dis_Vertex weight;	//weight of edge
	struct _edge* next;		//next _edge
}edge;
typedef struct _item
{
	Vertex  data;
	edge* adj;
	int color;
	int par;
	int d;			//first time to be found
	int f;			//final time to be found
			
}item;
bool graph_create(item vertex[],int numV,int numE);
void graph_transpose(item vertex[],item vertex_trans[],int numV);
void graph_time(item vertex[],int numV);
