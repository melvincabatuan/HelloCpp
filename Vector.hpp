#include <stdexcept>      // std::length_error


class Vector {

	public:

		Vector(int s) :elements{new double[s]}, sz{s} { 
			if (s < 0) throw std::length_error{"Length Error"};
			elements = new double[s];
			sz = s;
		} // construct a Vector
		
		double& operator[](int i) { 
			return elements[i]; 
			} // element access: subscripting
			
		int size() { return sz; }

	private:

		double* elements; // pointer to the elements
		int sz; // the number of elements
};
