// #3

#include <iostream>
#include <random>
#include <string>
#include <fstream>

struct Node {
	std::string value = "";
	Node* next = nullptr;
};

struct Queue {
	Node* head = nullptr, * tail = nullptr;
	int nrElem = 0;

	void push(std::string elem) {
		Node* newNode = new Node;
		newNode->value = elem;
		if (head != nullptr)
			tail->next = newNode;
		else
			head = newNode;
		tail = newNode;
		nrElem++;
	}

	void pop() {
		if (head != nullptr) {
			Node* current = head;
			if (head != tail) {
				head = head->next;
			}
			else {
				head = nullptr;
				tail = nullptr;
			}
			delete current;
			nrElem--;
		}
	}

	std::string front() {
		return head->value;
	}

	std::string back() {
		return tail->value;
	}

	bool empty() {
		if (head != nullptr)
			return 0;
		else
			return 1;
	}

	void clear() {
		while (!empty()) {
			pop();
		}
	}

	int size() {
		Node* it = head;
		int c = 0;
		while (it != nullptr) {
			it = it->next;
			c++;
		}
		return c;
	}
};

int genDurata() {
	srand(time(NULL));
	return rand() % 11 + 5;
}

void main() {
	Queue q;
	std::ifstream in("file.in");
	int t; in >> t; t *= 60;
	int n; in >> n;
	std::string val;
	for (int i = 0; i < n; i++) {
		in >> val;
		q.push(val);
	}
	in.close();
	std::ofstream out("file.out");
	std::cout << "	Prima zi de examen:\n";
	while (t > 0 || q.head == nullptr) {
		int durata = genDurata();
		std::cout << "Durata elev " << q.front() << " : " << durata << "\n";
		t -= durata;
		q.pop();
	}
	// A doua zi
	while (!q.empty()) {
		out << q.front() << "\n";
		q.pop();
	}
	out.close();
}