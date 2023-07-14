#pragma once
#include<string>
#include<map>
#include<iostream>
using std::string;
using std::map;


class Student
{
protected:
    int num;
    string surname;
    map<string, int> grades;

public:
    Student() {
        num = 0;
        surname = " ";
    }
    Student(int _num, string _surname, map<string, int> _grades) :num(_num), surname(_surname), grades(_grades) {  }
    friend std::istream& operator>>(std::istream& is, Student& s) {
        s.read(is);
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const Student& s) {
        os << s.num << " " << s.surname << "\n";
        for (auto it : s.grades) {
            os << it.first << ": " << it.second << "\n";
        }
        return os;
    }

    friend bool operator<(const Student& s1, const Student& s2);
    friend bool operator>(const Student& s1, const Student& s2);

    int gradeByname(std::string& name);
    map<string, int> get_grades();
    int get_num();
    string get_surname();
    virtual int count(int grade);
    virtual void read(std::istream& is);
    int sumgr() const;


};