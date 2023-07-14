#pragma once
#include <iostream>
template<typename T>
struct Node {
	T data;
	Node* next;
	Node(T data_ = T()) : next(nullptr), data(data_) {}
};

template<typename T>
class QueueList {
	Node<T>* first;
	Node<T>* last;
public:
	QueueList() :first(nullptr), last(nullptr) { }
	~QueueList() {
		while (!isEmpty()) {
			del();
		}
	}
	void add(T value) {
		Node<T>* newEl = new Node<T>(value);
		if (!isEmpty()) {
			last->next = newEl;
			last = newEl;
		}
		else {
			first = newEl;
			last = newEl;
		}

	}
	bool isEmpty() {
		return first == nullptr;
	}
	T del() {

		if (isEmpty()) {
			throw "Queue is already empty";
		}
		T result = first->data;
		Node<T>* elem = first->next;
		delete first;
		first = elem;
		if (first == nullptr) {
			last = nullptr;
		}

		return result;
	}
	T peek() {
		if (first == nullptr) {
			throw "Queue is empty";
		}
		return first->data;
	}
	void print() {
		Node<T>* iter = first;
		while (iter != nullptr) {
			std::cout << iter->data << " ";
			iter = iter->next;
		}
		std::cout << "\n";
	}
};