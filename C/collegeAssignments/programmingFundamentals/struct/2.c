#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <string.h>

const int INVALID_VALUE = -1000000;

struct Node {
	int info;
	struct Node* next;
};

typedef struct Node Node;

struct Queue {
	Node* head;
	Node* tail;
};

typedef struct Queue Queue;

void pushQueue(Queue* q, int x) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->info = x;
	newNode->next = NULL;

	if (q->head == NULL)
		q->head = newNode;
	else
		q->tail->next = newNode;
	q->tail = newNode;
}

void popQueue(Queue* q) {
	if (q->head != NULL) {
		Node* temp = q->head;
		q->head = temp->next;
		free(temp);
	}
}

int getInfoQueue(Queue q) {
	if (q.head != NULL)
		return q.head->info;
	return INVALID_VALUE;
}

void emptyQueue(Queue* q) {
	while (q->head != NULL) {
		printf("%d ", getInfoQueue(*q));
		popQueue(q); // &(*q)
	}
}

int main() {
    Queue q;
	q.head = NULL;
	q.tail = NULL;

	pushQueue(&q, 9);
	pushQueue(&q, 5);
	pushQueue(&q, 3);
	pushQueue(&q, 1);

	emptyQueue(&q);
}