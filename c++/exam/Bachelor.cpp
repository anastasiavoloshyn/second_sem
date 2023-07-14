#include "Bachelor.h"

void Bachelor::changeGrade(std::string name, int n)
{
    grades[name] = n;
}

bool Bachelor::reddiploma()
{
    int requiredAmountOfFives = grades.size() * 0.75;
    int countFives = this->count(5);

    for (auto el : grades) {
        if (el.second != 4 && el.second != 5) {
            return false;
        }
    }
    return countFives >= requiredAmountOfFives;
}

int Bachelor::count(int grade)
{
    int countgr = 0;
    for (auto it : grades) {
        if (it.second == grade) {
            countgr++;
        }
    }
    return countgr;
}

void Bachelor::read(std::istream& is)
{
    Student s;
    is >> s;
    is >> test;
    num = s.get_num();
    surname = s.get_surname();
    grades = s.get_grades();
   

}

std::istream& operator>>(std::istream& is, Bachelor& b)
{
    b.read(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Bachelor& b)
{
    os << b.num << " " << b.surname << " " << b.test << "\n";
    for (auto it : b.grades) {
        os << it.first << ": " << it.second << "\n";
    }
    return os;

}