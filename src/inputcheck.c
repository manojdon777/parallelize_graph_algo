#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool* visited;
void dfs(int ** graph, int vertex, int vertices) {
	visited[vertex] = true;
	for (int i = 0; i < vertices; ++i) {
		if (graph[vertex][i] && !visited[i]) {
			dfs(graph, i, vertices);
		}
	}
}

int countComponents(int ** graph, int vertices) {
	int components = 0;
	visited = (bool *)malloc(vertices * sizeof(bool));

	for (int i = 0; i < vertices; ++i) {
		if (!visited[i]) {
			dfs(graph, i, vertices);
			components++;
		}
	}
	return components;
}

bool ifUndirected(int **graph, int vertices){
	for(int i=0; i<vertices; i++){
		for(int j=0; j<=i; j++){
			if(i!=j){
				if(graph[i][j] != graph[j][i])
					return false;
			}
		}
	}
	return true;
}