#include <iostream>
#include <stack>

using namespace std;

void run(){
	stack<int> stacks;
  		int number, remainder, binary;
  		
  		cout<<"Enter a number: ";
  		cin>>number;
  		for(int i=1;number>0;i++){
  			remainder = number % 2;
  			stacks.push(remainder);
  			number = number / 2;
		  }
  		while(!stacks.empty()){
  			binary = stacks.top();
			stacks.pop();
  			cout<<binary;
		  }
}

int main ()
{
  	run();
    }
