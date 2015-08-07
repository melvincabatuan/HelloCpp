#include <iostream>
#include "Vector.hpp"



// read s integers from cin and return their sum; s is assumed to be positive
inline double read_and_sum(int s)
{
	Vector v(s);
	
	std::cout<<"Input "<< s <<" integers: \n";

	for (int i=0; i!=s; ++i)
		std::cin >> v[i]; // read into elements

	double sum = 0;

	for (int i=0; i!=s; ++i)
		sum += v[i]; // take the sum of the elements

	return sum;
}


 
 

int main()
{
	double total = read_and_sum(5);
 	std::cout<<"The sum is "<< total << std::endl; 
}
