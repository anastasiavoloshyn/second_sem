#pragma once
#include <iostream>

template<typename T>
struct qNode {
    T data;
    int priority;
    qNode* next;
    qNode(T data_ = T(), int priority_ = 0) : data(data_), priority(priority_), next(nullptr) { }
};

template<typename T>
class PriorityQueue {
    qNode<T>* first;
public:
    PriorityQueue() : first(nullptr) {}
    ~PriorityQueue() {
        while (!isEmpty()) {
            del();
        }
    }
    bool isEmpty() {
        return first == nullptr;
    }
    void add(T value, int priority) {
        qNode<T>* newEl = new qNode<T>(value, priority);
        if (isEmpty()) {
            first = newEl;
        }
        else if (priority > first->priority) {
            newEl->next = first;
            first = newEl;
        }
        else {
            qNode<T>* iter = first;
            while (iter->next != nullptr && priority <= iter->next->priority) {
                iter = iter->next;
            }
            newEl->next = iter->next;
            iter->next = newEl;
        }
    }
    T del() {
        if (isEmpty()) {
            throw "Queue is already empty";
        }
        T result = first->data;
        qNode<T>* elem = first->next;
        delete first;
        first = elem;
        return result;
    }
    T peek() {
        if (isEmpty()) {
            throw "Queue is empty";
        }
        return first->data;
    }
    void print() {
        qNode<T>* iter = first;
        while (iter != nullptr) {
            std::cout << iter->data << " ";
            iter = iter->next;
        }
        std::cout << "\n";
    }
};




