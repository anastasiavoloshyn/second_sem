#pragma once
#include"Student.h"


class Bachelor :public Student
{
private:
    int test;
public:
    Bachelor() {
        test = 0;
    }
    Bachelor(int _num, string _surname, map<string, int> _grades, int _test) : Student(_num, _surname, _grades), test(_test) { }

    void changeGrade(std::string name, int n);
    bool reddiploma();
    virtual int count(int grade);
    friend std::istream& operator>>(std::istream& is, Bachelor& b);
    friend std::ostream& operator<<(std::ostream& os, const Bachelor& b);
    virtual void read(std::istream& is);

};