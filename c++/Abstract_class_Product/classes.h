#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Product
{
protected:
	int price;
	string mark;
public:
	Product(int price=0,string mark="") : price(price), mark(mark) {}
	virtual void Input(istream&) = 0;
	virtual void Print(ostream&) = 0;
	
};

class Computer :public Product {
private:
	int speed;
	int op;
public:
	Computer(int price=0,string mark="", int speed=0, int op=0) :Product(price, mark), speed(speed),op(op) {
	}
	virtual void Input(istream&) override;
	virtual void Print(ostream&) override;
	int getPrice() {
		return price;
	}
};

class Printer : public Product {
private:
	int speed;
	int amountOfColors;
public:
	Printer(int price = 0, string mark = "", int speed = 0, int amountOfColors = 0) : Product(price, mark), speed(speed), amountOfColors(amountOfColors) {

	}
	virtual void Input(istream&) override;
	virtual void Print(ostream&) override;
	int GetColors() {
		return amountOfColors;
	}
};

class Server : public Computer {
private:
	int disk;
public:
	Server(int price = 0, string mark = "", int speed = 0, int op = 0, int disk = 0) :Computer(price,mark,speed, op), disk(disk) {

	}
	virtual void Input(istream&) override;
	virtual void Print(ostream&) override;
};
class Laptop : public Computer {
private:
	int d;
	int weight;
public:
	Laptop(int price = 0, string mark = "", int speed = 0, int op = 0, int d = 0,int weight=0) : Computer(price, mark, speed, op), d(d),weight(weight) {

	}
	virtual void Input(istream&) override;
	virtual void Print(ostream&) override;
};