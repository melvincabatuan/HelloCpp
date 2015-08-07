#include <iostream>
#include <vector>


void walkAnArray()
{
	int v[] = {0,1,2,3,4,5,6,7,8,9};
	std::cout<< "v = { ";
	for (auto& x : v)
		std::cout<< ++x << " ";
	std::cout<< " }\n";	 
}
 
 

int main()
{
 	walkAnArray();   
}
