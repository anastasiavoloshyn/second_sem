#include <iostream>
#include"priorityQueue.h"
#include "Queue.h"


void QueueTest1() {
	QueueList<int> q;
	q.add(7);
	q.add(8);
	q.add(9);
	if (q.peek() == 7) {
		std::cout << "Queue Test1 passed\n";
	}
	else std::cout << "Queue Test1 failed\n";
}
void QueueTest2() {
	QueueList<int> q;
	q.add(7);
	q.add(8);
	q.add(9);
	if (q.del() == 7&&q.peek()==8) {
		std::cout << "Queue Test2 passed\n";
	}
	else std::cout << "Queue Test2 failed\n";
}
void QueueTest3() {
	QueueList<char> q;
	q.add('p');
	q.add('i');
	q.add('t');
	q.add('t');
	q.add('y');
	
	if(q.del()=='p' && q.peek() == 'i') {
		std::cout << "Queue Test3 passed\n";
	}
	else std::cout << "Queue Test3 failed\n";
}

void pQueueTest1() {
	PriorityQueue<int> pq;
	pq.add(5, 1);
	pq.add(6, 2);     
	pq.add(7, 0);     
	pq.add(8, 2);	
	pq.add(5, 2);
	pq.add(12, 13);
	pq.add(1, 13);
	pq.add(2, 13);
	int a=pq.del();
	int b = pq.del();
	int c = pq.del();
	int d = pq.del();
	int e = pq.del();
	if (a==12&&b==1&&c==2&&d==6&&e==8&&pq.peek()==5) {
		std::cout << "pQueue Test1 passed\n";
	}
	else std::cout << "pQueue Test1 failed\n";
}
void pQueueTest2() {
	PriorityQueue<int> pq;
	pq.add(1, 0);
	pq.add(2, 0);
	pq.add(3, 0);
	pq.add(4, 0);
	pq.add(8, 3);
	pq.add(5, 2);
	pq.add(6, 3);
	pq.add(7, 3);
	int a = pq.del();
	int b = pq.del();
	int c = pq.del();
	int d = pq.del();
	int e = pq.del();
	if(a==8&&b==6&&c==7&&d==5&&e==1&&pq.peek()==2) {
		std::cout << "pQueue Test2 passed\n";
	}
	else std::cout << "pQueue Test2 failed\n";

	
}



int main() {

	PriorityQueue<int> q;

	QueueTest1();
	QueueTest2();
	QueueTest3();
	pQueueTest1();
	pQueueTest2();
	
	return 0;
}



















