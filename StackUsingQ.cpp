#include <iostream> 
#include <queue>
  
using namespace std; 
  
template <typename E>
class MyStack { 

    queue<E> primary; 
	queue<E> buffer; 
    int count; 
  
    public: 
	    MyStack() 
	    { 
	        count = 0; 
	    } 
	  
	    void push(E item) 
	    { 
	        buffer.push(item); 
	  
	        while (!primary.empty()) { 
	            buffer.push(primary.front()); 
	            primary.pop(); 
	        } 
	        queue<E> temp = primary;  
	        primary = buffer; 
	        buffer = temp; // clear buffer
	        ++count;
	    } 
	  
	    void pop() 
	    { 
	        if (primary.empty()) 
	            return; 
	        primary.pop(); 
	        --count; 
	    } 
	  
	    E top() const
	    { 
	        if (primary.empty()) 
	            return -1; 
	        return primary.front(); 
	    } 
	    
	  	bool empty() const
		{
	        return count == 0;
	    }
	    
	    int size() const 
	    { 
	        return count; 
	    }
}; 
  
  
int main() 
{ 
    MyStack<char> s; 
    s.push('U'); 
    s.push('S'); 
    s.push('L'); 
    s.push('D');
	while(!s.empty()){
		cout << s.top() << endl; 
		// cout << "size() = " << s.size() << endl; 
	    s.pop(); 	
	}
    return 0; 
} 
