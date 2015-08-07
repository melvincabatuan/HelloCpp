#include <iostream>
#include <complex>
#include <vector>






inline void print(std::vector<int> v)
{
 
	for (auto element : v) // for each x in v
		std::cout << element << " "; 
}


inline void initialization_demo() // function that doesn’t return a value
{
	double d1 = 2.3;
	std::cout<< "d1 = "<< d1 << std::endl;
	
	double d2 {2.3};
	std::cout<< "d2 = "<< d2 << std::endl;
	
	std::complex<double> z = 1; // a complex number with double-precision floating-point scalars
	std::cout<< "z = "<< z << std::endl;
	
	std::complex<double> z2 {d1,d2};
	std::cout<< "z2 = "<< z2 << std::endl;
	
	std::complex<double> z3 = {1,2}; // the = is optional with { ... }
	std::cout<< "z3 = "<< z3 << std::endl;
	
	std::vector<int> v{1,2,3,4,5,6}; // a vector of ints
	std::cout<< "v = { ";
	print(v);
	std::cout<< "}"<< std::endl;
}



int main()
{
 	initialization_demo();
}
