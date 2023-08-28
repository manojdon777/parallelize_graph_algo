#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "serialbfs.h"

void serial_bfs(int **graph, int vertices) {
	struct Queue* queue = createQueue();
	int* visited = (int *)malloc(vertices * sizeof(int));
	
	for (int i = 0; i < vertices; i++) {
		visited[i] = 0;
	}

	enqueue(queue, 0);
	visited[0] = 1;
	while (!isEmpty(queue)) {
		int current = dequeue(queue);
		printf("%d ", current + 1);

		for (int i = 0; i < vertices; i++) {
			if (graph[current][i] == 1 && visited[i] == 0) {
				enqueue(queue, i);
				visited[i] = 1;
			}
		}
	}
}