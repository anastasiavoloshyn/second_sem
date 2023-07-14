#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;


string postfix(string s) {
	stack<char> operators;
	string postfix = "";
	for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] == '(') {
		operators.push(s[i]);
		}
		else if (isdigit(s[i])) {
			postfix += s[i];
			if (!isdigit(s[i + 1])) {
				postfix += " ";
			}
		}
		else if (s[i] == ')') {
			while (operators.top() != '(') {
				postfix += operators.top();
				postfix += " ";
				operators.pop();
			}
			operators.pop();
		}
		else if (s[i] == '+' || s[i] == '-') {

			if (i > 0&&s[i]=='-' && ( s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/'))
			{
				postfix += '0';
				postfix += " ";
			}
			while (!operators.empty() && (operators.top() == '+' || operators.top() == '-' || operators.top() == '*' || operators.top() == '/')) {
				postfix += operators.top();
				postfix += " ";
				operators.pop();
			}
			operators.push(s[i]);
		}
		else if (s[i] == '*' || s[i] == '/') {
			if (i > 0 && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/')) {
				postfix += '0';
				postfix += " ";
			}
			while (!operators.empty() && (operators.top() == '*' || operators.top() == '/')) {
				postfix += operators.top();
				postfix += " ";
				operators.pop();
			}
			operators.push(s[i]);
		}
	}
	while (!operators.empty()) {
		postfix += operators.top();
		postfix += " ";
		operators.pop();
	}
	return postfix;
}


double calculate(string postfix) {
	stack<double> operands;
	stringstream ss(postfix);
	string token;
	while (getline(ss, token, ' ')) {
		if (isdigit(token[0])) {
			operands.push(stod(token));
		}
		else if (token == "+") {
			double b = operands.top();
			operands.pop();
			double a = operands.top();
			operands.pop();
			operands.push(a + b);
		}
		else if (token == "-") {
			double b = operands.top();
			operands.pop();
			double a = operands.top();
			operands.pop();
			operands.push(a - b);
		}
		else if (token == "*") {
			double b = operands.top();
			operands.pop();
			double a = operands.top();
			operands.pop();
			operands.push(a * b);
		}
		else if (token == "/") {
			double b = operands.top();
			operands.pop();
			double a = operands.top();
			operands.pop();
			operands.push(a / b);
		}
		else if (token == "-") {
			double a = operands.top();
			operands.pop();
			operands.push(-a);
		}
	}
	return operands.top();
}

void test1() {
	string s = "(((-5)*2)/5)";
	string postfix_ = postfix(s);
	string expected = "0 5 - 2 * 5 / ";
	double a = calculate(postfix_);
	double expectedA = -2;
	if (expected == postfix_&&a==expectedA) {
		std::cout << "test1 passed\n";
	}
	else std::cout << "test1 failed\n";

}
void test2() {
	string s = "(((-5)*(-5))/5)";
	string postfix_ = postfix(s);
	string expected = "0 5 - 0 5 - * 5 / ";
	double a = calculate(postfix_);
	double expectedA = 5;
	if (expected == postfix_ && a == expectedA) {
		std::cout << "test2 passed\n";
	}
	else std::cout << "test2 failed\n";

}
void test3() {
	string s = "((-1)*(-1)*(-1))";
	string postfix_ = postfix(s);
	string expected = "0 1 - 0 1 - * 0 1 - * ";
	double a = calculate(postfix_);
	double expectedA = -1;
	if (expected == postfix_ && a == expectedA) {
		std::cout << "test3 passed\n";
	}
	else std::cout << "test3 failed\n";
}

void test4() {
	string s = "((2*(-3))-(4+5))";
	string postfix_ = postfix(s);
	string expected = "2 0 3 - * 4 5 + - ";
	double a = calculate(postfix_);
	double expectedA = -15;
	if (expected == postfix_ && a == expectedA) {
		std::cout << "test4 passed\n";
	}
	else std::cout << "test4 failed\n";
}
void test5() {
	string s = "(((-10)*(-10))-((-2)*2))";
	string postfix_ = postfix(s);
	string expected = "0 10 - 0 10 - * 0 2 - 2 * - ";
	double a = calculate(postfix_);
	double expectedA = 104;
	if (expected == postfix_ && a == expectedA) {
		std::cout << "test5 passed\n";
	}
	else std::cout << "test5 failed\n";
}


int main() 
{
	test1();
	test2();
	test3();
	test4();
	test5();
	
}