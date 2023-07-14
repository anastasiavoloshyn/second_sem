#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std;
class HashNode {
private:
	string key;
	int value;
	HashNode* next;
public:
	HashNode(string key, int value) :key(key), value(value) {
		next = nullptr;
	}
	void setValue(int v) {
		value = v;
	}
	void setNext(HashNode* n) {
		next = n;
	}
	string getKey() {
		return key;
	}
	int getValue() {
		return value;
	}
	HashNode*& getNext() {
		return next;
	}
};

class HashTable {
private:
	vector<HashNode*> table;
	int Hash(string key) {
		int sum = 0;
		for (int i = 0; i < key.length(); i++) {
			sum += key[i];
		}
		return sum%table.size();
	}
public:
	HashTable(int size) {
		table.resize(size, nullptr);
	}
	void add(string key, int value) {
		int index = Hash(key);
		HashNode* newNode = new HashNode(key, value);
		if (table[index] == nullptr) {
			table[index] = newNode;
		}
		else {
			HashNode* current = table[index];
			while (current->getNext() != nullptr) {
				current = current->getNext();
			}
			current->setNext(newNode);
		}
	}
	int get(string key) {
		int index = Hash(key);
		HashNode* current = table[index];

		while (current != nullptr) {
			if (current->getKey() == key) {
				return current->getValue();
			}
			current = current->getNext();
		}
		return -1; 
	}
	void del(string key) {
		int index = Hash(key);
		if (table[index] == nullptr) {
			return;
		}
		HashNode* current = table[index];
		HashNode* prev = nullptr;
		while (current != nullptr && current->getKey() != key) {
			prev = current;
			current = current->getNext();
		}
		if (current == nullptr) {
			return;
		}
		if (prev == nullptr) {
			table[index] = current->getNext();
		}
		else {
			prev->setNext(current->getNext());
		}

		delete current;
	}
	void replace(string key, int newValue) {
		int index = Hash(key);
		HashNode* current = table[index];

		while (current != nullptr) {
			if (current->getKey() == key) {
				current->setValue(newValue);
				return;
			}
			current = current->getNext();
		}
	}
};
void test1() {
	HashTable ht(5);
	ht.add("apple", 3);
	ht.add("banana", 2);
	ht.add("orange", 4);
	if (ht.get("apple") != 3 || ht.get("banana") != 2 || ht.get("orange") != 4) {
		std::cout << "Test 1 failed\n";
	}
	else std::cout << "Test 1 passed\n";

}

void test2() {
	HashTable ht(5);
	ht.add("apple", 3);
	ht.add("banana", 2);
	ht.add("orange", 4);
	ht.del("banana");
	if (ht.get("banana") != -1) {
		std::cout << "Test 2 failed\n";
	}
	else std::cout << "Test 2 passed\n";

}
	
void test3() {
	HashTable ht(5);
	ht.add("apple", 3);
	ht.add("banana", 2);
	ht.add("orange", 4);
	ht.replace("orange", 5);
	if (ht.get("orange") != 5) {
		std::cout << "Test 3 failed\n";
	}
	else std::cout << "Test 3 passed\n";
	
}

int main() {
	test1();
	test2();
	test3();
}