#include "myString.h"

String::String() :size(0), line(nullptr) {}
String::String(const char* c) {
    size = strlen(c);
    line = new char[size];
    memcpy(line, c, size);
}
String::String(const String& s) {
    size = s.size;
    line = new char[size];
    memcpy(this->line, s.line, size);
}
String::~String() {
    delete[] line;
}

int String::getSize() const {
    return size;
}
void String::resize(int s) {
    size = s;
    char* temp = new char[size];
    memcpy(temp, line, size);
    line = temp;
    temp = nullptr;
}
int String::find(const String& s) const {
    int ssize = s.size;
    int temp = 0, ctr = 0;
    while (temp <= (size - ssize) && ssize > 0) {
        if ((line[temp]) == s.line[0]) {
            ctr = 0;
            for (int count = temp; count < (temp + ssize); count++) {
                if (line[count] == s.line[ctr])
                    ++ctr;
                else {
                    ctr = 0;
                    break;
                }
            }
            if (ctr == ssize)
                return temp;
        }
        ++temp;
    }
    return -1;
}
void String::replace(const String& fromS, const String& toS) {
    int pos = find(fromS);
    if (pos != -1) {
        int temp = fromS.getSize();
        if (temp == -1) {
            temp = size - pos;
        }
        int last = size - (temp + pos);
        for (int i = 0; i < last; i++) {
            line[pos + i] = line[pos + temp + i];
        }
        size -= temp;
        resize(size);
        char* tos = toS.line;
        int tosSize = toS.getSize(), s = size;
        size += tosSize;
        resize(size);
        char* p = line + pos;
        for (int i = s - 1; i >= 0; --i) {
            p[i + tosSize] = p[i];
        }
        for (int i = 0; i < tosSize; i++) {
            *p++ = *tos++;
        }
    }
}

String String::operator+(const String& s) {
    String result;
    result.size = this->size + s.size;
    result.line = new char[result.size];
    memcpy(result.line, this->line, this->size);
    memcpy(result.line + this->size, s.line, s.size);
    return result;
}
String& String::operator=(const String& s) {
    size = s.size;
    delete[] line;
    line = new char[size];
    memcpy(line, s.line, size);
    return *this;
}
bool String::operator==(const String& s) {
    if (size == s.size) {
        for (int i = 0; i < size; i++) {
            if (line[i] != s.line[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}
char& String::operator[](const int i) const {
    if (i >= 0 && i < size) {
        return line[i];
    }
    char value = '\0';
    return value;
}

std::ostream& operator<<(std::ostream& out, const String& s) {
    for (int i = 0; i < s.size; i++) {
        out << s.line[i];
    }
    return out;
}


Rule::Rule()
    : startString(""), replaceString(""), terminal(false) {}
Rule::Rule(String ss, String rs)
    : startString(ss), replaceString(rs), terminal(false) {}
Rule::Rule(String ss, String rs, bool t)
    : startString(ss), replaceString(rs), terminal(t) {}

String markov(std::vector<Rule> r, String s) {
    if (r.empty()) {
        throw "No rules.";
    }
    String out = s;
    std::vector<Rule>::iterator it = r.begin();
    int count = 0;
    while (it != r.end()) {
        int pos = out.find(it->startString);
        if (pos != -1) {
            out.replace(it->startString, it->replaceString);
            if (it->terminal) {
                break;
            }
            it = r.begin();
        }
        else {
            ++it;
        }
        ++count;
    }
    if (count > 1000) {
        throw "Error.";
    }
    return out;
}