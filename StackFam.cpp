#include <iostream>
#include <stack>   

using namespace std;

int main ()
{
  stack<char> stack1;
  char x;
  for (int i=1; i<=5; ++i) 
		{
		  cout<<"Enter a character: ";
		  cin>>x;
  	       stack1.push(x);
  	   	}
  	cout << "Last in First Out of Characters: ";
  	while (!stack1.empty())
  		{
     		cout << " " << stack1.top();
     		stack1.pop();
 		}
cout << endl;
return 0;
}

