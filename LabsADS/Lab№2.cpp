#include <iostream>
#include <stack>



class Stack {
private:
	int* array;
	int capacity;
	int top_index;
public:
	Stack(int size = 10) {
		array = new int[size];
		capacity = size;
		top_index = -1;
	}
	~Stack() {
		delete[]array;
	}
	bool IsEmpty() {
		return(top_index == -1);
	}
	bool IsFull() {
		return (top_index == capacity - 1);
	}
	int Top() {
		if (IsEmpty()) {
			std::cout << "Stack is empty\n";
		}
		else return array[top_index];
	}
	int Pop() {
		if (IsEmpty()) {
			std::cout << "Stack is empty\n";
		}
		int value = array[top_index];
		top_index--;
		return value;
	}
	int Push(int value) {
		if (IsFull()) {
			std::cout << "Stack is full\n";
		}
		top_index++;
		array[top_index] = value;
		return value;
	}
	void Print() {
		int i;
		std::cout << "stack is: ";
		for (i = top_index; i >= 0; i--)
		{
			std::cout << array[i] << " ";

		}
		std::cout << "\n";
	}
	int Size() {
		return top_index + 1;
	}


};


bool TestSTL1() //перевірка push(), pop(), top()
{
	std::stack<int> st1;
	st1.push(2);

	if (st1.top() != 2) {
		return false;
	}

	st1.pop();
	st1.push(4);
	st1.push(3);

	if (st1.top() != 3) {
		return false;
	}

	st1.pop();

	if (st1.top() != 4) {
		return false;
	}

	return true;
}

bool TestSTL2() //перевірка size()
{
	std::stack<int> st1;
	st1.push(111);
	st1.push(0);
	st1.push(6);

	if (st1.size() != 3) {
		return false;
	}

	st1.pop();

	if (st1.size() != 2) {
		return false;
	}

	if (st1.size() != 2) {
		return false;
	}

	st1.pop();

	if (st1.size() != 1) {
		return false;
	}

	st1.push(4);

	if (st1.size() != 2) {
		return false;
	}

	return true;
}

bool TestSTL3() //перевірка empty()
{
	std::stack<int> st1;

	if (!st1.empty()) {
		return false;
	}

	st1.push(65);
	st1.push(6);

	if (st1.empty()) {
		return false;
	}

	st1.pop();
	st1.pop();

	if (!st1.empty()) {
		return false;
	}

	return true;
}






bool Test1() {
	
	Stack st(1);
	if ( !st.IsEmpty()) {
		return false;
	}
	
	st.Push(1);
	if ( st.IsEmpty()) {
		return false;
	}
	return true;
}

bool Test2() {
	
	Stack st(2);
	st.Push(1);
	st.Push(2);
	
	if ( st.Top() != 2) {
		return false;
	}
	return true;
}
bool Test3() {
	Stack st(3);
	st.Push(1);
	st.Push(2);
	st.Push(3);
	if (!st.IsFull())
	{
		return false;
	};
	return true;
}
bool Test4() {
	Stack st(3);
	st.Push(1);
	st.Push(2);
	st.Push(3);
	int popped1 = st.Pop();
	int popped2 = st.Pop();
	int popped3 = st.Pop();
	if (popped1 != 3 || popped2 != 2 || popped3 != 1 || !st.IsEmpty()) {
		return false;
	}
	return true;
}


void Check() {
	if (Test1()) {
		std::cout << "Test 1 passed\n";
	}
	else {
		std::cout << "Test 1 failed\n";
	}

	if (Test2) {
		std::cout << "Test 2 passed\n";
	}
	else {
		std::cout << "Test 2 failed\n";
	}
	if (Test3) {
		std::cout << "Test 3 passed\n";
	}
	else {
		std::cout << "Test 3 failed\n";
	}
	if (Test4) {
		std::cout << "Test 4 passed\n";
	}
	else {
		std::cout << "Test 4 failed\n";
	}
	if (TestSTL1) {
		std::cout << "Test1 for stack STL passed\n";
	}
	else {
		std::cout << "Test1 for stack STL failed\n";
	}
	if (TestSTL2) {
		std::cout << "Test2 for stack STL passed\n";
	}
	else {
		std::cout << "Test2 for stack STL failed\n";
	}
	if (TestSTL3) {
		std::cout << "Test3 for stack STL passed\n";
	}
	else {
		std::cout << "Test3 for stack STL failed\n";
	}





}



int main()
{
	Check();
}



