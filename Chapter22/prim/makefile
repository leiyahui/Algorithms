prim:prim.o graph.o edge_stack.o
	gcc -g -o prim prim.o graph.o edge_stack.o
prim.o:prim.c graph.h edge_stack.h
	gcc -g -c -o prim.o prim.c
graph.o:graph.h graph.c 
	gcc -g -c -o graph.o graph.c
edge_stack.o:edge_stack.h edge_stack.c
	gcc -g -c -o edge_stack.o edge_stack.c
