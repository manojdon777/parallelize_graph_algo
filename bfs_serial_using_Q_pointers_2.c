#include<stdio.h>
#include <stdlib.h>


int *visited;
int vertices = 0;
struct Node {
	int data;
	struct Node* next;
};

struct Queue {
	struct Node* front;
	struct Node* rear;
};

struct Queue* createQueue() {
	struct Queue* queue = (struct Queue *) malloc(sizeof(struct Queue));
	queue->front = queue->rear = NULL;
	return queue;
}

int isEmpty(struct Queue* queue) {
	return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int data) {
	struct Node* newNode = (struct Node *) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

	if (isEmpty(queue)) {
		queue->front = queue->rear = newNode;
	} else {
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
}

int dequeue(struct Queue* queue) {
	if (isEmpty(queue)) {
		printf("Queue is empty.\n");
		return -1;
	}

	struct Node* temp = queue->front;
	int data = temp->data;
	queue->front = temp->next;

	if (queue->front == NULL) {
		queue->rear = NULL;
	}

	free(temp);
	return data;
}

void displayQueue(struct Queue* queue) {
	if (isEmpty(queue)) {
		printf("Queue is empty.\n");
		return;
	}

	struct Node* current = queue->front;
	while (current != NULL) {
		printf("%d ", current->data + 1);
		current = current->next;
	}
	printf("\n");
}

void serial_bfs(int **graph) {
	struct Queue* queue = createQueue();
	visited = (int *)malloc(vertices * sizeof(int));
	enqueue(queue, 0);
	visited[0] = 1;
	while (!isEmpty(queue)) {
		int current = dequeue(queue);
		// displayQueue(queue);
		printf("%d ", current + 1);

		for (int i = 0; i < vertices; i++) {
			if (graph[current][i] == 1 && visited[i] == 0) {
				enqueue(queue, i);
				visited[i] = 1;
			}
		}
	}
}

void display_graph(int graph[vertices][vertices]) {
	int i, j;
	for (i = 0; i < vertices; ++i) {
		for (j = 0; j < vertices; ++j) {
		printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char* argv[]) {
	// int graph[vertices][vertices] = {0};
	int** graph;

	int i;
	FILE *file;
	int source, destination;
	// vertices = (int)argv[0];
	vertices = 1000;
	graph = (int **)malloc(vertices * sizeof(int*));
	for (i = 0; i < vertices; i++)
		graph[i] = (int *)malloc(vertices * sizeof(int));
	
	// if (file = fopen("input/in10.txt", "r")) {
	if (file = fopen("input/in1000.txt", "r")) {
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
