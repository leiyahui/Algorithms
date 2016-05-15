bellman_ford:bellman_ford.o graph.o edge.o relax.o
	gcc -g -o bellman_ford bellman_ford.o graph.o edge.o relax.o
bellman_ford.o:bellman_ford.c graph.h edge.h relax.h
	gcc -g -c -o bellman_ford.o  bellman_ford.c
edge.o:graph.h edge.h edge.c 
	gcc -g -c -o edge.o edge.c
graph.o:graph.c graph.h 
	gcc -g -c -o graph.o graph.c
relax.o: relax.c relax.h graph.h edge.h
	gcc -g -c -o relax.o relax.c
clean:
	rm -rf bellman_ford.o edge.o graph.o relax.o 
