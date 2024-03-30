// #2

#include <iostream>
#include <vector>
#include <fstream>

struct Node {
	float value = NULL;
	Node* prev = nullptr, * next = nullptr;
};

struct List {
	Node* head = nullptr, * tail = nullptr;
	int listSize = 0;

	void push_back(float value) {
		Node* newNode = new Node;
		newNode->value = value;
		newNode->prev = tail;
		if (tail == nullptr)
			head = newNode;
		else
			tail->next = newNode;
		tail = newNode;
		listSize++;
	}

	float get(int index) {
		if (index >= listSize)
			return 0;
		int c = 0;
		Node* it = head;
		while (c != index) {
			it = it->next;
			c++;
		}
		return it->value;
	}

	void replace(int index, float value) {
		if (index < listSize) {
			int c = 0;
			Node* it = head;
			while (c != index) {
				it = it->next;
				c++;
			}
			it->value = value;
		}
	}
};

void InsertionSort(List bucket) {
	for (int i = 0; i < bucket.listSize; i++) {
		float key = bucket.get(i);
		int j = i - 1;
		while (j >= 0 && bucket.get(j) > key) {
			bucket.replace(j + 1, bucket.get(j));
			j--;
		}
		bucket.replace(j + 1, key);
	}
}

void BucketSort(std::vector<float>& arr) {
	std::vector<List> BucketsArr;
	BucketsArr.resize(arr.size());
	for (const float& elem : arr)
		BucketsArr[int(elem * BucketsArr.size())].push_back(elem);
	for (int i = 0; i < BucketsArr.size(); i++)
		InsertionSort(BucketsArr[i]);
	int index = 0;
	for (int i = 0; i < arr.size(); i++)
		for (int j = 0; j < BucketsArr[i].listSize; j++)
			arr[index++] = BucketsArr[i].get(j);
}

void main() {
	List list;

	std::ifstream in("file.in");
	std::vector<float> arr;
	float value;
	while (in >> value)
		arr.push_back(value);

	BucketSort(arr);
	for (const float& elem : arr)
		std::cout << elem << " ";

	in.close();
}