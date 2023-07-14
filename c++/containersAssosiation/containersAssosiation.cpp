#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <set>

using namespace std;
int d = 12;

list<int> func1(list<int>& a,int index) {
	
	int count = 0;
	for (list<int>::iterator it = a.begin(); it != a.end(); it++) {
		if (count == index - 1) {
			a.insert(it, d);
		}
		count++;
	}
	return a;
}

list<int> func2(list<int>&a) {
	list<int>::iterator it = a.begin();
	int num;
	for (it; it != a.end(); ++it) {
		num = *it;
		if (it == a.begin()) {
			a.insert(it, num);
		}
	}
	a.push_back( num);
	return a;
}
list<int> func3(list<int>&a,int index,int k) {
	//int num;
	//list<int>::iterator it = a.begin();
	//for (int i = 0; i < a.size(); ++i) {
	//	if (i == index) {
	//		num = *it;
	//		a.erase(it);
	//		std::advance(it, -k);
	//		a.insert(it, num);
	//		return a;
	//	}
	//}
	if (k >= a.size()) {
		throw "cannot calculate the exp";
	}
	list<int>::iterator it = a.begin();
	std::advance(it, index);
	int num = *it;
	a.erase(it);
	list<int>::iterator iter = a.begin();
	std::advance(iter, index-k);
	a.insert(iter, num);
	return a;

}

list<int> func4(list<int>& a) {
	
	list<int>::iterator it = a.begin();
	int num;
	int i = 0;
	for (it; it != a.end();) {
		num = *it;
		if ((i == a.size() - 1) && (i % 2 == 1)) {
			a.push_back(num);
			break;
		}
		
		if (i % 2 == 1) {
			a.insert(it, num);
		}
		i++;
		it++;
		
	}
	return a;


}
list<int> func5(list<int>& a) {

	list<int>::iterator it = a.begin();
	list<int> b;
	for (it; it != a.end();) {
		if (*it < 0) {
			b.push_back(*it);
		}
		it++;
	}
	return b;
}

list<int> func5NORM(list<int>& a) {

	list<int>::iterator it = a.begin();
	for (it; it != a.end();) {
		if (*it < 0) {
			it=a.erase(it);
		}
		it++;
	}
	return a;
}
list<int> func6(list<int> a,int k) {

	list<int>::iterator it = a.begin();
	list<int>::iterator iter = a.begin();
	list<int> b;
	for (int i = 0; i < a.size();i++) {
		if (it == a.end()) {
			it = a.begin();
		}
		std::advance(it, a.size() - k);
		b.push_back(*it);
		iter++;
		it++;
	}
	return b;
}

void func7(list<int>& a) {
	list<int>::iterator max = a.begin();
	list<int>::iterator it = a.begin();
	for (it; it != a.end(); it++) {
		if (*it > *max) {
			max = it;
		}
	}
	a.erase(max);
	for (int& elem : a) {
		std::cout << elem << "\t";
	}

}

void func8(list<int>& a) {
	
	for (list<int>::iterator i = a.begin(); i != a.end(); ) {
		list<int>::iterator it = i;
		++it;
		while (it != a.end()) {
			if (*i == *it) {
				it = a.erase(it);
			}
			else {
				++it;
			}
		}
		++i;
	}
	for (int& elem : a) {
		std::cout << elem << "\t";
	}
}
void func9(list<int>& a,list<int>&b) {

	std::list<int>::iterator it = a.begin();
	while (it != a.end()) {
		bool found = false;
		for (std::list<int>::iterator i = b.begin(); i != b.end(); ++i) {
			if (*it == *i) {
				it = a.erase(it);
				found = true;
				break;
			}
		}
		if (!found) {
			++it;
		}
	}

	for (int& elem : a) {
		std::cout << elem << "\t";
	}


}

void func10(list<int>& a, list<int>& b) {
	list<int>::iterator it = a.begin();
	while (it != a.end() && (*it) >= 0) {
		++it;
	}
	a.insert(it, b.begin(), b.end());
	for (int& elem : a) {
		std::cout << elem << "\t";
	}

}

void func11(list<int>& a) {
	list<int> b;
	list<int>::iterator it = a.begin();
	while (it != a.end()) {
		if (*it  < 0) {
			b.push_back(*it);
			a.insert(a.begin(), *it);
			it = a.erase(it);
		}
		else { ++it; }
	}
	b.sort();
	it = a.begin();
	auto i = a.begin();
	while (i != a.end()) {
		if (*i > 0) {
			break;
		}
		++i;
	}
	while (it != i) {
		it = a.erase(it);
	}
	a.insert(a.begin(), b.begin(), b.end());
	for (int& elem : a) {
		std::cout << elem << "\t";
	}
}


list <int> read() {
	cout << "input size:\n";
	int n;
	cin >> n;
	int b;
	list<int> a;
	for (int i = 0; i < n; ++i) {
		cin >> b;
		a.push_back(b);
	}
	return a;
}
void printList(list<int> a) {
	for (int& elem: a) {
		std::cout << elem << "\t";
	}
	std::cout << "\n";
}


void negative(list<int>&a,int n) {
	for (auto it = a.begin(); it != a.end(); ++it) {
		if (*it < 0) {
			*it = std::pow(*it, n);
		}
	}
}

void Del6(list<int>& a) {
	for (auto it = a.begin(); it != a.end();) {
		if (*it % 10 == 6||*it%10==-6||*it==6) {
			it = a.erase(it);
		}
		else { 
		++it;
		}
	}
}

void mulByNum(list<int>& a, int n) {
	auto it = a.begin();
	for (int i = 0; i < a.size(); ++i) {
		if (i % 2 == 0) {
			*it = *it * n;
		}
		++it;
	}
}

int findSum(list<int> a) {
	int sum = 0;
	for (auto it = a.begin(); it != a.end(); ++it) {
		if (*it > 100) {
			sum += *it;
		}
	}
	return sum;
}


class rem {
	int n;
	int m;
public:
	rem(int _n) {
		n = _n;
		m = 0;
	}
	bool operator()(int x) {
		return x <= n;
	}
};








int main() {
//	std::fstream fin("data.txt");
//	std::istream_iterator<int> it(fin), enditer;
//	list<int>v;
//	std::copy(it, enditer, std::back_inserter(v));
//	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
//	std::cout << "\n";
//	std::copy_if(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "), [](int a) {
//		return a > 0; });
//	int n4=std::count_if(v.begin(), v.end(), [](int a) {
//		return a == 4; });
//	int nB4=std::count_if(v.begin(), v.end(), [](int a) {
//		return a > 4; });
//	std::cout << "\namount of 4: " << n4 << ", amount of numbers bigger than 4: " << nB4 << '\n'; //if you want to compare with inputted m, 
//	std::cout << "max:" << *std::max_element(v.begin(), v.end(), [](int a, int b)					//than you can access from predicat by [&m]; 
//		return std::abs(a) < std::abs(b);
//}) << "\n";
//	std::list<int>::iterator  firstt0 = std::find(v.begin(), v.end(), 0);
//	std::list<int>::reverse_iterator last0 = std::find(v.rbegin(), v.rend(), 0);
//	std::copy(firstt0, last0.base(), std::ostream_iterator<int>(std::cout, " "));

	std::set<int> set;
	std::fstream fin("data.txt");
	std::istream_iterator<int> it(fin), enditer;
	std::copy(it, enditer, inserter(set,set.end()));
	std::copy(set.begin(), set.end(), std::ostream_iterator<int>(std::cout, " ")); 
	cout << '\n';
	int m;
	cin >> m;
	set.erase(m);
	auto it1= set.lower_bound(m); //
	set.erase(set.begin(), it1);
	std::copy(set.begin(), set.end(), std::ostream_iterator<int>(std::cout, " "));
	cout << '\n';
	std::set<int> set1;
	std::istream_iterator<int> cinIt(cin), endCinIter;
	std::copy(cinIt, endCinIter, inserter(set1, set1.end()));
	std::set_intersection(set.begin(), set.begin(), set1.begin(), set1.end(), std::ostream_iterator<int>(std::cout," "));

}
	
	


	




