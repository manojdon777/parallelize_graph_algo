#include<stdio.h>
#define N 10

int queue[N];
int visited[N];
int front = -1, rear = -1;

void enqueue(int vertex) {
	if (rear == N - 1)
		printf("Queue is full.\n");
	else {
		if (front == -1)
			front = 0;
		rear++;
		queue[rear] = vertex;
	}
}

int dequeue() {
	int vertex;
	if (front == -1)
		printf("Queue is empty.\n");
	else {
		vertex = queue[front];
		front++;
		if (front > rear)
			front = rear = -1;
		return vertex;
	}
	return -1;
}

void serial_bfs(int graph[N][N]) {
	enqueue(0);
	visited[0] = 1;
	while (front != -1) {
		int current = dequeue();
		printf("%d ", current + 1);

		for (int i = 0; i < N; i++) {
			if (graph[current][i] == 1 && visited[i] == 0) {
				enqueue(i);
				visited[i] = 1;
			}
		}
	}
}

void display_graph(int graph[N][N]) {
	int i, j;
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
		printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}



int main() {
	int graph[N][N] = {0};
	int i, j;
	FILE *file;
	int source, destination;
	
	if (file = fopen("input_file.txt", "r")) {
	while (fscanf(file, "%d %d", &source, &destination) == 2)
		graph[source - 1][destination - 1] = 1;
	
	// display_graph(graph);
	serial_bfs(graph);
	}
	else
		printf("Error in reading file\n");
	printf("\n");
	
	return 0;
}
