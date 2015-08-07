#include <iostream>
#include <vector>

 
 

int main()
{
 	int v1[10] = {0,1,2,3,4,5,6,7,8,9};
	int v2[10]; // to become a copy of v1
	
	std::cout<< "v1 = { ";
	
	for (auto h=0; h!=10; ++h) // print elements
		std::cout<< v1[h] <<" ";
	
	std::cout<< "}" << std::endl; 

	for (auto i=0; i!=10; ++i) // copy elements
		v2[i]=v1[i];
		
	std::cout<< "v2 = { ";
	
	for (auto j=0; j!=10; ++j) // print elements
		std::cout<< v2[j] <<" ";
	
	std::cout<< "}" << std::endl; 	   
}
