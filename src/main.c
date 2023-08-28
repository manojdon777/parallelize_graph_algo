#include <stdio.h>
#include "generategraph.h"
#include "serialbfs.h"


int main(int argc, char* argv[]) {
	int vertices = atoi(argv[1]);
	int edges = atoi(argv[2]);
	int **graph;
	int i;
	// Edge graph[edges];

	graph = (int **)malloc(vertices * sizeof(int*));
    for (i = 0; i < vertices; i++)
        graph[i] = (int *)malloc(vertices * sizeof(int));

	generateGraph(graph, vertices, edges);
	// for (int i = 0; i < edges; i++) {
	// 	printf("(%d, %d)\n", graph[i].x, graph[i].y);
	// }
	serial_bfs(graph, vertices);	
	printf("\nAll working fine upto here");
	printf("\n");
	return 0;
}
