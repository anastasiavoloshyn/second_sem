#pragma once
#include<iostream>
#include <string>
using std::string;
class Monitors
{
protected:
	string model;
	double d;
public:
	Monitors(string model="", double d=0) :model(model), d(d) { }
	virtual void print(std::ostream& os) = 0;
	virtual  void read(std::istream& is) = 0;
	//friend std::ostream& operator<<(std::ostream& os, const Monitors& m);
	//friend std::istream& operator>>(std::istream& is, Monitors& m);
	bool operator<(const Monitors& other)const {
		return d < other.d;
	}
	bool operator>(const Monitors& other)const {
		return d > other.d;
	}
	bool operator>=(const Monitors& other)const {
		return d >= other.d;
	}
	bool operator<=(const Monitors& other)const {
		return d <= other.d;
	}
	bool operator==(const Monitors& other)const {
		return d == other.d;
	}
	string getModel() {
		return model;
	}
	double getD() {
		return d;
	}
	virtual double getFrequency() = 0;

};