#include <iostream>
#include <stack>   

using namespace std;

void decToBin(int num){
	stack<int> stack;
	while(num > 0){
		int rem = num % 2;
		num = num / 2;
		stack.push(rem);
	}
	while(!stack.empty()){
		int x;
		x = stack.top();
		stack.pop();
		cout << x;
	}
}

main (){
	int y;
	cout << "Enter a number: ";
	cin >> y;
	cout << "Converted to Binary: ";
	decToBin(y);
	return 0;
}


