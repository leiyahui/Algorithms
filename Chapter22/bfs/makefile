bfs:bfs.o queue.o graph.o
	gcc -g -o bfs bfs.o queue.o graph.o
bfs.o:bfs.c queue.h graph.h
	gcc -g -c bfs.c -o bfs.o
queue.o:queue.c queue.h graph.h
	gcc -g -c queue.c -o queue.o
graph.o:graph.c graph.h
	gcc -g -c graph.c -o graph.o
