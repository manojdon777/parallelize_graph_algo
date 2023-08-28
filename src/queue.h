#ifndef GRAPH_H
#define GRAPH_H

struct Node {
	int data;
	struct Node* next;
};

struct Queue {
	struct Node* front;
	struct Node* rear;
};

struct Queue* createQueue();

int isEmpty(struct Queue* queue);

void enqueue(struct Queue* queue, int data);

int dequeue(struct Queue* queue);

void displayQueue(struct Queue* queue);

#endif
