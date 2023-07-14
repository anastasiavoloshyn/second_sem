#include<iostream>
#include "graph.h"
using namespace std;


void test() {
	Graph G(6);
	G.addEdge(0, 1, 1);
	G.addEdge(0, 2, 2);
	G.addEdge(1, 3, 3);
	G.addEdge(1, 4, 4);
	G.addEdge(3, 5, 5);
	G.addEdge(4, 5, 6);
	if (G.dijkstra(2, 3) == 6) {
		std::cout << "test 1 passed\n";
	}
	else cout << "test 1 failed\n"; 
	Graph G1(5);
	G1.addEdge(0, 2, 3);
	G1.addEdge(1, 3, 5);
	G1.addEdge(2, 3, 2);
	if (G1.dijkstra(1, 4) == -1) {
		cout << "test 2 passed\n";
	}
	else cout << "test 2 failed\n";
	if (G1.dijkstra(0, 1) == 10&&G1.dijkstra(2,1)==7) {
		std::cout << "test 3 passed\n";
	}
	else std::cout << "test 3 failed\n";

	

}

int main()
{
	test();
	system("pause");
	return 0;
}