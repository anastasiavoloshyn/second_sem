#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<fstream>
#include"Student.h"
#include <set>
#include <deque>
#include"Bachelor.h"
using std::vector;
using std::set;


int main() {
    vector<Student*> students;
    std::ifstream file("Text.txt");
    string type;
    while (!file.eof()) {
        file >> type;
        if (type == "S") {
            Student* s=new Student;
            s->read(file);
            students.push_back(s);

        }
        else {
            Bachelor* be=new Bachelor;
            be->read(file);
            students.push_back(be);
        }
    }
    for (auto it : students) {
        std::cout << *it << "\n";
    }







}