#include <iostream>
#include <stack>

using namespace std;

int main ()
{
  		stack<int> stacks;
  		int add (0);

  		for (int i=1;i<=100;i++) 
		  stacks.push(i);

  		while (!stacks.empty())
		{
			add += stacks.top();
			stacks.pop();
		}

  		cout <<"\n \n \n \t \t \t"<< "The sum of all numbers is: " << add << endl;
  
    	return 0;
    }

