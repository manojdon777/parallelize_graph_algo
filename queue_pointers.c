#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
struct Node {
	int data;
	struct Node* next;
};

// Queue structure
struct Queue {
	struct Node* front;
	struct Node* rear;
};

// Initialize an empty queue
struct Queue* createQueue() {
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = queue->rear = NULL;
	return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
	return (queue->front == NULL);
}

// Enqueue an element at the rear of the queue
void enqueue(struct Queue* queue, int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

	if (isEmpty(queue)) {
		queue->front = queue->rear = newNode;
	} else {
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
}

// Dequeue an element from the front of the queue
int dequeue(struct Queue* queue) {
	if (isEmpty(queue)) {
		printf("Queue is empty.\n");
		return -1; // Return some sentinel value
	}

	struct Node* temp = queue->front;
	int data = temp->data;
	queue->front = temp->next;

	if (queue->front == NULL) {
		queue->rear = NULL; // Reset rear if queue becomes empty
	}

	free(temp);
	return data;
}

// Display the queue elements
void displayQueue(struct Queue* queue) {
	if (isEmpty(queue)) {
		printf("Queue is empty.\n");
		return;
	}

	struct Node* current = queue->front;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

int main() {
	struct Queue* queue = createQueue();

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	for (int i = 0; i < 10000000; ++i)
	{
		enqueue(queue, i);
	}

	printf("Queue elements: ");
	// displayQueue(queue);

	printf("Dequeued element: %d\n", dequeue(queue));
	printf("Dequeued element: %d\n", dequeue(queue));
	printf("Dequeued element: %d\n", dequeue(queue));
	printf("Dequeued element: %d\n", dequeue(queue));

	printf("Queue elements after dequeue: ");
	displayQueue(queue);

	return 0;
}
