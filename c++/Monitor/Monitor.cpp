#include<iostream>
#include<fstream>
#include<string>
#include"Monitors.h"
#include"Beam.h"
#include"Plasm.h"

void sort(Monitors** arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-i-1; j++) {
			if (arr[j]->getD() < arr[j + 1]->getD()) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}




using namespace std;
int main() {
	ifstream fin("data.txt");
	int size;
	fin>>size;
	Monitors** arr = new Monitors * [size];
	char type;
	for (int i = 0; i < size; i++) {
		fin >> type;
		if (type == 'p') {
			arr[i] = new Plasm;
			arr[i]->read(fin);
		}
		if (type == 'b') {
			arr[i] = new Beam;
			arr[i]->read(fin);
		}
	}
	for (int i = 0; i < size; i++) {
		arr[i]->print(std::cout);
		std::cout << "\n";
	}
	sort(arr, size);
	std::cout << "\n";
	for (int i = 0; i < size; i++) {
		arr[i]->print(std::cout);
		std::cout << "\n";
	}
	double a = 100, b = 300;
	for (int i = 0; i < size; i++) {
		if ((dynamic_cast<Beam*>(arr[i])) != nullptr) {
			if (arr[i]->getFrequency() >= a && arr[i]->getFrequency() <= b) {
				arr[i]->print(std::cout);
				std::cout << "\n";
			}
		}
	}
	
	 
	
	

}