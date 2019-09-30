#include <iostream>
#include <string>
#include <stdexcept> // exception

using std::cout;
using std::endl;
using std::out_of_range;
using std::string;
using std::exception;

class ArrayException : public out_of_range
{
	public:
    	ArrayException(const string& message = "")
        	: out_of_range(message.c_str())
    {}
};

template <typename T> 
class MyArray
{
	private: 
    	T *data;
    	int capacity;    
      
    public:
        MyArray(int n)  
        {
        	capacity = n;
			data = new T[capacity];
			for(int i = 0; i<capacity; i++)
         		data[i] = 0;	        	
        }
        
        ~MyArray() // destructor
        {
 			delete data;
		}  
		
		T get(int idx) throw(ArrayException)
		{
			if (idx < 0 || idx > (capacity - 1))
				throw ArrayException("Out of Range");
			return data[idx];  
		}
        
		void set(int idx, T item)
		{   
			if (idx < 0 || idx > (capacity - 1))
				throw ArrayException("Out of Range");
			data[idx] = item;
		} 		
		
		int size() const
		{   
			return capacity;
		}
};


int main(){
	MyArray<char> myArray(5);
	myArray.set(0, 'D'); 
	myArray.set(1, 'L'); 
	myArray.set(2, 'S'); 
	myArray.set(3, 'U'); 
	myArray.set(4, 'M'); 
	try {
		myArray.set(5, 'X'); //  Out of Range Exception
	}  catch (exception& e)
  	{
    	cout << e.what() << endl;
  	}
	
	for (int i = 0; i < myArray.size(); ++i){
		cout << myArray.get(i);		
	}
	return 0;	
}
