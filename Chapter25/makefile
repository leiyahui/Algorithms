faster_all_pairs_shortest_path:faster_all_pairs_shortest_path.o graph.o dynamic_malloc_array.o 
	gcc -g -o faster_all_pairs_shortest_path faster_all_pairs_shortest_path.o graph.o dynamic_malloc_array.o
faster_all_pairs_shortest_path.o:faster_all_pairs_shortest_path.c faster_all_pairs_shortest_path.h graph.h dynamic_malloc_array.h
	gcc -g -c -o faster_all_pairs_shortest_path.o faster_all_pairs_shortest_path.c
graph.o:graph.c graph.h dynamic_malloc_array.h
	gcc -g -c -o graph.o graph.c
dynamic_malloc_array.o:dynamic_malloc_array.h dynamic_malloc_array.c
	gcc -g -c -o dynamic_malloc_array.o dynamic_malloc_array.c
clean:
	rm -rf dynamic_malloc_array.o graph.o faster_pairs_shortest_path.o
