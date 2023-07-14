#include <iostream>
#include <map>
#include <string>
#include <fstream>

using std::map;
using std::string;

class Value {
	string sign;
	string mark;
	int year;
public:
	Value(string sign="", string mark="", int year=0) : sign(sign), mark(mark), year(year) { }
	friend std::ostream& operator<<(std::ostream& os, const Value& v) {
		os << v.sign << " " << v.mark <<" " << v.year;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Value& v) {
		is >> v.sign >> v.mark >> v.year;
		return is;
	}
};

namespace std {
	std::ostream& operator<<(std::ostream& os, const map<string, Value>& m) {
		auto it = m.begin();
		while (it != m.end()) {
			os << it->first<<" " << it->second << '\n';
			++it;
		}
		return os;
	}
}

void read(string fileName, map<string, Value>& database) {
	std::ifstream fin(fileName);
	string name;
	Value v;
	while (!fin.eof()) {
		fin >> name >> v;
		database.emplace(name, v);
	}
}
void writeToFile(string fileName, map<string, Value>& database) {
	std::ofstream fout;
	fout.open(fileName);
	fout << database;
}
void addElFromKeyboard(map<string, Value>& database) {
	string name;
	Value v;
	std::cin >> name >> v;
	database.emplace(name, v);
	
}
void addElFromFile(string fileName,map<string, Value>& database) {
	string name;
	Value v;
	std::ifstream fin(fileName);
	fin >> name >> v;
	database.emplace(name, v);
	
}
void searchByName(const map<string, Value>& database) {
	string name;
	std::cin >> name;
	auto it=database.find(name);
	std::cout<<"found element values are: " << it->second<<'\n';
}

int main() {
	
	map<string, Value> database;
	read("data.txt", database);
	/*std::cout << database;*/
	addElFromFile("add.txt", database);
	/*addElFromKeyboard(database);*/
	std::cout << database;
	searchByName(database);

	

}