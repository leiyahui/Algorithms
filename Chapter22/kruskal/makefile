kruskal:kruskal.o graph.o heap_sortion.o 
	gcc -g kruskal.o graph.o heap_sortion.o -o kruskal
kruskal.o:kruskal.c graph.h heap_sortion.h
	gcc -c -g -o kruskal.o kruskal.c
graph.o:graph.h graph.c
	gcc -c -g -o graph.o graph.c
heap_sortion.o:heap_sortion.h heap_sortion.c graph.h
	gcc -c -g -o heap_sortion.o heap_sortion.c
