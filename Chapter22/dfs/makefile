dfs:dfs.o stack.o graph.o
	gcc -g -o dfs dfs.o stack.o graph.o
dfs.o:dfs.c 
	gcc -g -o dfs.o -c dfs.c
stack.o:stack.c stack.h graph.h
	gcc -g -o stack.o -c stack.c 
graph.o:graph.c graph.h
	gcc -g -o graph.o -c graph.c
