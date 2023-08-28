#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// struct Node {
// 	int data;
// 	struct Node* next;
// };

// struct Queue {
// 	struct Node* front;
// 	struct Node* rear;
// };

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