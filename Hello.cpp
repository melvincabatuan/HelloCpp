#include <iostream>
#include <string>
#include <stdexcept> // exception

using std::cout;
using std::endl;
using std::logic_error;
using std::string;

class QueueException : public logic_error
{
public:
    QueueException(const string& message = "")
        : logic_error(message.c_str())
    {}
};

template <typename T>
class CircularQueue   
{
	private:
		static const int MAX_SIZE = 8;
	    T data[MAX_SIZE];
	    int head;  // index of next item to be removed
		int tail;  // index of the first free slot
     
    public:    	
        CircularQueue() // constructor
        {
        	head = 0;
        	tail = 0;      
        }
       
        ~CircularQueue() // destructor
        {
            clear();  
		}  
       
		T front() const throw(QueueException)
		{
		    if (empty())
		        throw QueueException("Queue is Empty");
		  	return data[head];
		}

		T back() const throw(QueueException)
		{
		    if (empty())
		        throw QueueException("Queue is Empty");
		  	return data[(tail - 1 + MAX_SIZE) % MAX_SIZE];
		}

        void push(T item) throw(QueueException)
        {
            if(size() == MAX_SIZE - 1)
                throw QueueException("Queue Overflow!");
			data[tail] = item;
			tail = (tail + 1) % MAX_SIZE;
        }
       
        void pop() throw(QueueException)
        {
            if(empty())
                throw QueueException("Queue is Empty");
            head = (head + 1) % MAX_SIZE;
        }
       
        bool empty() const
		{  
		    return (head == tail);
		}

		int size() const
		{    
			int gap = tail - head;
			return ((MAX_SIZE + gap) % MAX_SIZE);
		}

		void clear() 
		{
			head = tail = 0;
		}	
};


int main(){
	CircularQueue<char> school;
	cout << school.empty() << endl;        // prints 1 (true)
	//cout << school.front()  << endl;     // Queue Empty Exception
	//cout << school.back()  << endl;      // Queue Empty Exception
	//school.pop();                          // what(): Queue Underflow
	school.push('M');
	school.push('-');
	school.push('U');
	school.push('S');
	school.push('L');
	school.push('D');
    cout << school.empty() << endl;      // prints 0 (false)
    cout << school.front()  << endl;     // prints 'M'
    cout << school.back()  << endl;      // prints 'D'
    cout << school.size() << endl;       // prints 6
    
    school.pop();
    school.pop();    
    cout << school.size() << endl;       // prints 4
    
    school.push('X');
    cout << school.back()  << endl;      // prints 'X'
    cout << school.size() << endl;       // prints 5
    school.push('Y');
    cout << school.back()  << endl;      // prints 'Y'
    cout << school.size() << endl;       // prints 6
    school.push('Z');                    // Queue Overflow if Linear Queue
    cout << school.back()  << endl;      // prints 'Z'
    cout << school.size() << endl;       // prints 7
    // school.push('U');                 // Queue Overflow even for Ring Buffer!

    while( !school.empty() )
    {
        cout << school.front();
        school.pop();
    }                                    // prints "M-USLD"
   cout << endl;                            
   cout << school.size() << endl;        // prints 0
   return 0;
}
