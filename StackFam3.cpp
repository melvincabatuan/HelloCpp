#include <iostream>
#include <stack>

using namespace std;

int main ()
{
  		stack <int> integer;
  		cout <<"\n\n\n\t\t\t"<< "Element 0. size: " << integer.size() << endl;

  		for (int i=0; i<5; i++) 
		  integer.push(i);
  		
  		
 		cout <<"\n\n\n\t\t\t"<< "Element 1. Size: " << integer.size() << endl;
  		integer.pop();

  		cout <<"\n\n\n\t\t\t"<< "Element 2. Size: " << integer.size() << endl;
		integer.pop();
 		cout <<"\n\n\n\t\t\t"<< "Element 3. Size: " << integer.size() << endl;
   		integer.pop();
  		cout <<"\n\n\n\t\t\t"<< "Element 4. Size: " << integer.size() << endl;
   		integer.pop();
  		cout <<"\n\n\n\t\t\t"<< "Element 5. Size: " << integer.size() << endl;

     	return 0;
     }

