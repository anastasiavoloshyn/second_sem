#include<iostream>
#include <fstream>
#include <string>
#include"classes.h"

int main() {

	ifstream fin("data.txt");
	int size;
	fin >> size;
	Product** array = new Product * [size];
	string type;
	for (int i = 0; i < size; i++) {
		int price, speed, op, weight,disk,amountOfColors,d;
		string mark;
		fin >> type;
		if (type == "Computer") {
			fin >> type;
			if (type == "Laptop") {
				fin >> price >> mark >> speed >> op >> d >> weight;
				array[i] = new Laptop(price, mark, speed, op, d, weight);

			}
			if (type == "Server") {
				fin >> price >> mark >> speed >> op >> disk;
				array[i] = new Server(price, mark, speed, op, disk);

			}

		}
		if (type == "Printer") {
		fin >> price >> mark >> speed >> amountOfColors;
		array[i] = new Printer(price,mark,speed,amountOfColors);
		}
		
	}
	for (int i = 0; i < size; i++) {
		array[i]->Print(cout);
		cout << "\n";
	}
	std::cout << "\nPrinters are:\n";
	for (int i = 0; i < size; i++) {
		Printer* printer = dynamic_cast<Printer*>(array[i]);
		if (printer&&printer->GetColors() >= 3) {
			array[i]->Print(cout);
			cout << "\n";
		}
	}
	Computer* maxComputer = nullptr;
	for (int i = 0; i < size; i++) {
		if (dynamic_cast<Computer*>(array[i]) != nullptr) { 
			Computer* computer = dynamic_cast<Computer*>(array[i]); 
			if (maxComputer == nullptr || computer->getPrice() > maxComputer->getPrice()) {
				maxComputer = computer;
			}
		}
	}

	if (maxComputer != nullptr) {
		cout << "The most expensive computer is: ";
		maxComputer->Print(cout);
	}

}
