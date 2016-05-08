scc: scc.o graph.o stack.o
	gcc -g scc.o graph.o stakc.o -o scc
scc.o:scc.c graph.h stack.h
	gcc -g -c scc.c -o scc.o
graph.o:graph.c graph.h 
	gcc -g -c graph.c -o graph.o
stack.o:stack.c stack.h graph.h
	gcc -g -c stakc.c -o stack.o
