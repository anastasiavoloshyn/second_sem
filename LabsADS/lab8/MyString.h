#pragma once
#include <iostream>
#include <string.h>
#include <vector>

class String {
private:
	char* line;
	int size;
public:
	String();
	String(const char* c);
	String(const String& s);
	~String();

	int getSize() const;
	void resize(int s);
	int find(const String& s) const;
	void replace(const String& fromS, const String& toS);

	String operator+(const String& s);
	String& operator=(const String& s);
	bool operator==(const String& s);
	char& operator[](const int i) const;

	friend std::ostream& operator<<(std::ostream& out, const String& s);
};

struct Rule {
	String startString;
	String replaceString;
	bool terminal;
	Rule();
	Rule(String ss, String rs);
	Rule(String ss, String rs, bool t);
};

String markov(std::vector<Rule> r, String s);