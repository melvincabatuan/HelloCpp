#include <iostream>

void type_demo() // function that doesn’t return a value
{
	double d = 2.2; // initialize floating-point number
	int i = 7; 		// initialize integer
	d = d + i; 		//assign sum to d
	std::cout << "d = "<< d << std::endl;
	i = d*i; 		//assign product to i (truncating the double d*i to an int)
	std::cout << "i = "<< i << std::endl;
}


int main()
{
 	type_demo();
}
