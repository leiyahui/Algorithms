dijkstra:dijkstra.o graph.o
	gcc -g -o dijkstra dijkstra.o graph.o
dijkstra.o:dijkstra.c graph.h
	gcc -g -c -o dijkstra.o dijkstra.c
graph.o:graph.h graph.c
	gcc -g -c -o graph.o graph.c
