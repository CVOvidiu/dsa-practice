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

void pushStack(Node** head, int x) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->info = x;
	newNode->next = *head;
	*head = newNode;
}

void popStack(Node** head) {
	if (*head != NULL) {
		Node* temp = *head;
		*head = temp->next;
		free(temp);
	}
}

int getInfoStack(Node* head) {
	if (head != NULL)
		return head->info;
	return INVALID_VALUE;
}

void emptyStack(Node** head) {
	while (*head != NULL) {
		printf("%d ", getInfoStack(*head));
		popStack(head); // &(*head)
	}
}

int main() {
    Node* head = NULL;
	pushStack(&head, 9);
	pushStack(&head, 5);
	pushStack(&head, 3);
	pushStack(&head, 1);

	emptyStack(&head);
}