#include "myString.h"
#include <iostream>
#include <vector>
using namespace std;


void test1() {
	vector<Rule> r;
	Rule r1("bb", "h");
	r.push_back(r1);
	Rule r2("a", "e");
	r.push_back(r2);
	Rule r3("li", "ll");
	r.push_back(r3);
	Rule r4("c", "o");
	r.push_back(r4);
	String expected = "hello";
	String a = markov(r, "bbalic");
	if (expected == a) {
		std::cout << "test1 passed\n";
	}
	else std::cout << "test1 failed\n";
}

void test2() {
	vector<Rule> r;
	Rule r1("kk", "pi");
	r.push_back(r1);
	Rule r2("lo", "na");
	r.push_back(r2);
	Rule r3("kl", "co");
	r.push_back(r3);
	Rule r4("ll", "lada");
	r.push_back(r4);
	String expected = "pinacolada";
	String a = markov(r, "kkloklll");
	if (expected == a) {
		std::cout << "test2 passed\n";
	}
	else std::cout << "test2 failed\n";
}








int main() {

	test1();
	test2();
	system("pause");
	return 0;
}