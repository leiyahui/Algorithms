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
	int dest;		//destination
			
}item;
bool graph_create(item vertex[],int numV,int numE);
