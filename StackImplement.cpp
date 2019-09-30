#include <iostream>
#include <string>
#include <stdexcept> // exception

using std::cout;
using std::endl;
using std::logic_error;
using std::string;

class StackException : public logic_error
{
	public:
    	StackException(const string& message = "")
        	: logic_error(message.c_str())
    {}
};

template <typename T> 
class MyStack
{
	private: 
		static const int MAX_SIZE = 6;
    	T data[MAX_SIZE];
    	int tos;     // top of stack
      
    public:
        MyStack() // constructor
        {
        	tos = -1;        	
        }
        
        ~MyStack() // destructor
        {
        	tos = -1;
//        	while (!empty())
//        		pop();
		} // Assertion: tos == -1
        
 		T top() const throw(StackException)
		 {
    		if (empty())
        		throw StackException("Stack is Empty");
    		else
 				return data[tos];
		 }
		 
        void push(T item) throw(StackException)
        {
        	// cout << "tos = " << tos << endl; // debugging
            if(tos + 1 > (MAX_SIZE - 1))
            {
                throw StackException("Stack Overflow");
            }
            else
				data[++tos] = item;
        }
        
        void pop() throw(StackException)
        {
            if(empty())
            {
                throw StackException("Stack Underflow");
            }
            else
                tos--;
        }
        
        bool empty() const
		{  // const means it doesn't modify the stack
        	return (tos == -1);
		}
		
		int size() const
		{    // const means it doesn't modify the stack
			return (tos + 1);
		}
};


int main(){
	MyStack<char> school;
	cout << school.empty() << endl;       // prints 1 (true)
	// cout << school.top()  << endl;     // Stack is Empty Exception
	// school.pop();                      // what():  Stack Underflow
	school.push('M');
	school.push('-');
	school.push('U');
	school.push('S');
	school.push('L');
	school.push('D');
	cout << school.empty() << endl;   // prints 0 (false)
	cout << school.top()  << endl;    // prints 'D'
	cout << school.size() << endl;    // prints 6
	// school.push('X');  //          // Stack Overflow
    while( !school.empty() )
    {
        cout << school.top();
        school.pop();
    }                                 // prints "DLSU-M" 
   cout << endl;                             
   cout << school.size() << endl;     // prints 0
   return 0;
}

 
