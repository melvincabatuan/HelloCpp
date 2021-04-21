#include <iostream>
#include <stack>
#include <stdbool.h>

using namespace std;

int main(){
    stack<int> binary;
    int x;
    bool negativeNumber;
    cout << "Input decimal number: ";
    cin >> x;
    if(x < 0){
    	x *= -1;
    	negativeNumber = true;
	}
	
	while(x > 0){
		if(x % 2 == 0){
        	x = x/2;
        	binary.push(0);
    	}
		else{
        	x--;
        	x = x/2;
        	binary.push(1);
    	}
	}
	
    cout << "In Binary: ";
    if(negativeNumber == true){
    	cout << "-";
	}
    while(!binary.empty()){
        cout << binary.top();
        binary.pop();
    }
}
