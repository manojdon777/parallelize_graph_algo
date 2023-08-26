#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
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

void bfs(struct Node** adjacencyList, int vertices, int startVertex) {
    int visited[vertices];
    for (int i = 0; i < vertices; ++i) {
        visited[i] = 0;
    }

    struct Queue* queue = createQueue();
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct Node* temp = adjacencyList[currentVertex];
        while (temp != NULL) {
            int adjacentVertex = temp->data;
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = 1;
                enqueue(queue, adjacentVertex);
            }
            temp = temp->next;
        }
    }

    free(queue);
}

int main() {
    int vertices = 6;
    struct Node* adjacencyList[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjacencyList[i] = NULL;
    }

    // Add edges to the adjacency list (assuming an undirected graph)
    // ...

    int startVertex = 0; // Starting vertex for BFS
    bfs(adjacencyList, vertices, startVertex);

    return 0;
}
