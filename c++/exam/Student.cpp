#include "Student.h"

int Student::gradeByname(string& name)
{
    return grades[name];
}

map<string, int> Student::get_grades()
{
    return grades;
}

int Student::get_num()
{
    return num;
}

string Student::get_surname()
{
    return surname;
}

int Student::count(int grade)
{
    int countgr = 0;
    for (auto it : grades) {
        if (it.second == grade) {
            countgr++;
        }
    }
    return countgr;
}

void Student::read(std::istream& is)
{
    is >>num >> surname;
    std::pair<string, int> p;
    grades.clear();
    for (int i = 0; i < 3; ++i) {
        is >> p.first >> p.second;
        grades.insert(p);
    }
    
}



int Student::sumgr() const
{
    int sum = 0;
    for (auto it : grades) {
        sum += it.second;
    }
    return sum;
}

bool operator<(const Student& s1, const Student& s2)
{
    return s1.sumgr() < s2.sumgr();
}

bool operator>(const Student& s1, const Student& s2)
{
    return s1.sumgr() > s2.sumgr();
}