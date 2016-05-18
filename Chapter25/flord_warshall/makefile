floyd_warshall:floyd_warshall.o graph.o dynamic_malloc_array.o
	gcc -g -o floyd_warshall floyd_warshall.o graph.o dynamic_malloc_array.o
floyd_warshall.o:floyd_warshall.c graph.h dynamic_malloc_array.h
	gcc -g -c -o floyd_warshall.o floyd_warshall.c
graph.o:graph.h graph.c dynamic_malloc_array.h
	gcc -g -c -o graph.o graph.c
dynamic_malloc_array.o:dynamic_malloc_array.h dynamic_malloc_array.c
	gcc -g -c -o dynamic_malloc_array.o dynamic_malloc_array.c
clean:
	rm -rf floyd_warshall.o graph.o dynamic_malloc_array.o 
