// #1

#include <iostream>
#include <string>

struct Node {
	int value = NULL;
	Node* prev = nullptr, * next = nullptr;
};

struct List {
	Node* head = nullptr, * tail = nullptr;
	int listSize = 0;

	void push_front(int value) {
		Node* newNode = new Node;
		newNode->value = value;
		newNode->next = head;
		if (tail == nullptr) { // Adaugam primul element
			tail = newNode;
		}
		else
			head->prev = newNode;
		head = newNode;
		listSize++;
	}

	void push_back(int value) {
		Node* newNode = new Node;
		newNode->value = value;
		newNode->prev = tail;
		if (tail == nullptr) // Adaugam primul element
			head = newNode;
		else
			tail->next = newNode;
		tail = newNode;
		listSize++;
	}

	void pop_front() {
		if (head != nullptr) {
			Node* current = head;
			if (head->next != nullptr) {
				head = head->next;
				head->prev = nullptr;
			}
			else {
				tail = nullptr;
				head = nullptr;
			}
			delete current;
			listSize--;
		}
	}

	void pop_back() {
		if (tail != nullptr) {
			Node* current = tail;
			if (tail->prev != nullptr) {
				tail = tail->prev;
				tail->next = nullptr;
			}
			else {
				tail = nullptr;
				head = nullptr;
			}
			delete current;
			listSize--;
		}
	}

	Node* find(int value) {
		Node* it = head;
		while (it != nullptr) {
			if (it->value == value)
				return it;
			it = it->next;
		}
		return nullptr;
	}

	void erase(Node* node) {
		if (node != nullptr) {
			if (node == head)
				pop_front();
			else if (node == tail)
				pop_back();
			else {
				node->prev->next = node->next;
				node->next->prev = node->prev;
				delete node;
				listSize--;
			}
		}
	}

	void remove(int value) {
		Node* found = find(value);
		while (found != nullptr) {
			erase(found);
			found = find(value);
		}
	}

	void insert(Node* node, int value) {
		if (node == head)
			push_front(value);
		else if (node == nullptr)
			push_back(value);
		else {
			Node* newNode = new Node;
			newNode->value = value;
			newNode->prev = node->prev;
			node->prev->next = newNode;
			node->prev = newNode;
			newNode->next = node;
			listSize++;
		}
	}

	bool empty() {
		if (head != nullptr) {
			//std::cout << "List is not null.";
			return 0;
		}
		else {
			//std::cout << "List is null.";
			return 1;
		}
	}

	void clear() {
		while (!empty())
			pop_back();
	}

	void print() {
		Node* it = head;
		std::cout << "List: ";
		while (it != nullptr) {
			std::cout << it->value << " ";
			it = it->next;
		}
		std::cout << "\n";
	}

	int size() {
		int c = 0;
		Node* it = head;
		while (it != nullptr) {
			it = it->next;
			c++;
		}
		return c;
	}
};

bool palindrom(List list) {
	int i;
	Node* it, * it2;
	for (i = 0, it = list.head, it2 = list.tail;
		i < list.listSize / 2;
		i++, it = it->next, it2 = it2->prev) {
		if (it->value != it2->value) {
			return 0;
		}
	}
	return 1; // Este palindrom
}

bool compare(List l1, List l2) {
	if (l1.listSize != l2.listSize)
		return 0;
	Node* it = l1.head, * it2 = l2.head;
	while (it != nullptr) {
		if (it->value != it2->value)
			return 0;
		it = it->next;
		it2 = it2->next;
	}
	return 1;
}

void main() {
	List list;
	int running = 1;

	while (running) {
		system("CLS");
		std::cout << "====== Menu ======\n";
		std::cout << "   Choose between options:\n";
		std::cout << "1. Push front\n";
		std::cout << "2. Push back\n";
		std::cout << "3. Pop front\n";
		std::cout << "4. Pop back\n";
		std::cout << "5. Find an element\n";
		std::cout << "6. Erase first encounter\n";
		std::cout << "7. Remove all encounters\n";
		std::cout << "8. Insert before first encounter\n";
		std::cout << "9. Check if list is void\n";
		std::cout << "10. Empty list\n";
		std::cout << "11. Print list\n";
		std::cout << "12. Size of list\n";
		std::cout << "13. Check if current list is palindrome\n";
		std::cout << "14. Compare current list with another\n";
		std::cout << "0. EXIT\n\n";
		int option, value;
		std::cout << "   Your option: ";
		std::cin >> option;

		switch (option) {
		case 0: {
			running = 0;
			break;
		}
		case 1: {
			system("CLS");
			std::cout << "Value to add: ";
			std::cin >> value;
			list.push_front(value);
			break;
		}
		case 2: {
			system("CLS");
			std::cout << "Value to add: ";
			std::cin >> value;
			list.push_back(value);
			break;
		}
		case 3: {
			list.pop_front();
			break;
		}
		case 4: {
			list.pop_back();
			break;
		}
		case 5: {
			system("CLS");
			std::cout << "Value to find: ";
			std::cin >> value;
			Node* res = list.find(value);
			if (res != nullptr)
				std::cout << "Address of value: " << res << "\n";
			else
				std::cout << "Value not found.\n";
			system("pause");
			break;
		}
		case 6: {
			system("CLS");
			std::cout << "Value to remove: ";
			std::cin >> value;
			list.erase(list.find(value));
			break;
		}
		case 7: {
			system("CLS");
			std::cout << "Value to remove: ";
			std::cin >> value;
			list.remove(value);
			break;
		}
		case 8: {
			system("CLS");
			std::cout << "Value to add: ";
			std::cin >> value;
			int value2;
			std::cout << "Before what value should I insert it?: ";
			std::cin >> value2;
			list.insert(list.find(value2), value);
			break;
		}
		case 9: {
			system("CLS");
			if (!list.empty())
				std::cout << "List is not null.";
			else
				std::cout << "List is null.";
			std::cout << "\n";
			system("pause");
			break;
		}
		case 10: {
			list.clear();
			break;
		}
		case 11: {
			system("CLS");
			list.print();
			system("pause");
			break;
		}
		case 12: {
			system("CLS");
			std::cout << "List size: " << list.size() << "\n";
			system("pause");
			break;
		}
		case 13: {
			system("CLS");
			bool res = palindrom(list);
			if (res)
				std::cout << "List is palindrome.";
			else
				std::cout << "List is not palindrome.";
			std::cout << "\n";
			system("pause");
			break;
		}
		case 14: {
			system("CLS");
			List list2;
			std::cout << "Enter second list(enter a character to stop): ";
			int value;
			std::cin >> value;
			while (std::cin) {
				list2.push_back(value);
				std::cin >> value;
			}
			std::cin.clear();
			std::string line;
			std::getline(std::cin, line);
			bool res = compare(list, list2);
			if (res)
				std::cout << "Lists are identical.";
			else
				std::cout << "Lists are not identical";
			std::cout << "\n";
			system("pause");
			break;
		}
		}
	}
}