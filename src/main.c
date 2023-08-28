#include <stdio.h>
#include <sys/time.h>
#include "generategraph.h"
#include "serialbfs.h"
#include "inputcheck.h"


int main(int argc, char* argv[]) {
	int vertices = atoi(argv[1]);
	int edges = atoi(argv[2]);
	int **graph;
	int i;
    double exe_time;
    struct timeval stop_time, start_time;

	graph = (int **)malloc(vertices * sizeof(int*));
    for (i = 0; i < vertices; i++)
        graph[i] = (int *)malloc(vertices * sizeof(int));

	generateGraph(graph, vertices, edges);
	if(ifUndirected(graph, vertices)){
		printf("** Graph is Undirected **\n");
	}
	else{
		printf("Graph is Directed\n");
	}
	printf("Components = %d\n", countComponents(graph, vertices));

	gettimeofday(&start_time, NULL);
	serial_bfs(graph, vertices);
	gettimeofday(&stop_time, NULL);
    exe_time = (stop_time.tv_sec + (stop_time.tv_usec / 1000000.0)) - (start_time.tv_sec + (start_time.tv_usec / 1000000.0));
    printf("\nExecution time is = %lf seconds\n", exe_time);	
	printf("\nAll working fine upto here");
	printf("\n");
	return 0;
}
