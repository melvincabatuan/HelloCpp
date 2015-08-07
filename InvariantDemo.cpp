#include <iostream>
#include <stdexcept>      // std::length_error
#include "Vector.hpp"


inline void test()
{
	try {
		Vector v(-27);
	}
	
	catch (std::length_error) {
		// handle negative size
		std::cout<<"std::length_error thrown.\n";
	}
	catch (std::bad_alloc) {
		// handle memory exhaustion
		std::cout<<"std::bad_alloc thrown.\n";
	}
}



int main()
{
	test(); 
}
