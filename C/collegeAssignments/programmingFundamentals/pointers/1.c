// Circular Queue.
// Children's game. We always start counting from `p` child. We eliminate the `m`-th child from position of `p`.
// Last one standing wins.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int info;
	struct Node* next;
};

struct CircQ {
	struct Node* first;
	struct Node* last;
};

typedef struct Node Node;
typedef struct CircQ CircQ;

void push(CircQ* q, int x) { // x - info de adaugat
	Node* nn = (Node*)malloc(sizeof(Node)); // nn - new node
	nn->info = x;

	if (q->first == NULL) // Nu exista alte noduri
		q->first = nn;
	else
		q->last->next = nn;
	nn->next = q->first;
	q->last = nn;
}

void empty(CircQ* q) {
	Node* n;
	while (q->first != q->last) {
		n = q->first;
		q->last->next = q->first->next;
		q->first = n->next;
		free(n);
	}
	free(q->first);
	q->first = NULL;
	q->last = NULL;
}

Node* getNode(CircQ q, int n) {
	if (n <= 0) return NULL;
	Node* nn = q.first;
	for (int i = 1; i < n; i++)
		nn = nn->next;
	return nn;
}

void game(CircQ* q, int m, int p) { // m - al catalea copil elimin, p - de la care incep
	Node* n, * toDel;
	while (q->first != q->last) {
		n = getNode(*q, p);
		for (int i = 1; i < m; i++)
			n = n->next;
		toDel = n->next;
		n->next = toDel->next;
		if (toDel == q->first) {
			q->first = q->first->next;
		}
		else if (toDel == q->last)
			q->last = n;
		printf("%d ", toDel->info);
		free(toDel);
	}
	printf("Winner: %d\n", q->first->info);
}

int main() {
	CircQ q;
	q.first = NULL;
	q.last = NULL;
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i++)
		push(&q, i);
	game(&q, m, p);
	empty(&q);
	return 0;
}