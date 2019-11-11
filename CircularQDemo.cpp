#include <iostream>

using namespace std;

const int MAX = 6;
int q[MAX];
int head = 0; // index of front
int tail = 0; // index of first free slot

int size(){
	return ((tail - head + MAX) % MAX);
}

void push(int item){
	if (size() == MAX - 1) {
		cout << "Queue Overflow";
		return;
	}
	q[tail] = item;
	tail=(tail+1)%MAX;
}

void pop(){
	head = (head+1) % MAX;
}

bool empty(){
	return (head == tail);
}

int front(){
	return q[head%MAX];
}

int main(){
	push(10);
	push(20);
	push(30);
	push(40);
	push(50); // 10 20 30 40 50
	// push(60); // Overflow
	pop();
	pop();
	pop();     // 40 50
	push(33);  // 40 50 33 WALANG ISSUE TO
	cout << "tail = " << tail << endl;
	while(!empty()){
    	cout << front() << endl;
    	cout << "size = " << size() << endl;
    	pop();
	}
	return 0;
}
