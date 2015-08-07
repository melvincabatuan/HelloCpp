#include <iostream>
 


struct Vector {
	int size; 			// number of elements
	double* elements;  // pointer to elements
};



inline void vector_init(Vector& v, int s)
{
	v.elements = new double[s]; // allocate an array of s doubles
	v.size = s;
}



// read s integers from cin and return their sum; s is assumed to be positive
inline double read_and_sum(int s)
{
	Vector v;
	vector_init(v,s); //allocate s elements for v
	
	std::cout<<"Input "<< s <<" integers: \n";

	for (int i=0; i!=s; ++i)
		std::cin >> v.elements[i]; // read into elements

	double sum = 0;

	for (int i=0; i!=s; ++i)
		sum += v.elements[i]; // take the sum of the elements

	return sum;
}




 
 

int main()
{
	double total = read_and_sum(5);
 	std::cout<<"The sum is "<< total << std::endl; 
}
