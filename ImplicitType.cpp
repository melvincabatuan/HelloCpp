#include <iostream>
#include <cmath>  // needed by sqrt 

void implicit_demo() // function that doesn’t return a value
{
	auto b = true; // a bool
	std::cout<<"b = "<< b << std::endl;
	
	auto ch = 'x'; // a char
	std::cout<<"ch = "<< ch << std::endl;
	
	auto i = 123; // an int
	std::cout<<"i = "<< i << std::endl;
	
	auto d = 1.2; // a double
	std::cout<<"d = "<< d << std::endl;
	
	auto z = sqrt(i); // z has the type of whatever sqr t(y) returns
	std::cout<<"z = "<< z << std::endl;
}


int main()
{
 	implicit_demo();
}
