#include <iostream>
 

bool accept()
{
	std::cout << "Do you want to proceed (y or n)?\n";  
	char answer = 0;
	std::cin >> answer; // read answer
	
	if (answer == 'y') 
		return true;
	
	return false;
}


bool accept2()
{
	std::cout << "Do you want to proceed (y or n)?\n";  
	char answer = 0;
	std::cin >> answer; // read answer
	
	switch (answer) {
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			std::cout << "I'll take that for a no.\n";
			return false;
	}
}


bool accept3()
{
	int tries = 1;

	while (tries<4) {
		std::cout << "Do you want to proceed (y or n)?\n";  
		char answer = 0;
		std::cin >> answer; // read answer

		switch (answer) {
			case 'y':
				return true;
			case 'n':
				return false;
			default:
				std::cout << "Sorry, I don't understand that.\n";
				++tries; // increment
		} // END SWITCH
	} // END WHILE
	
	std::cout << "I'll take that for a no.\n";
	return false;
}



int main()
{
 	//std::cout<< accept() << std::endl;
 	//std::cout<< accept2() << std::endl;
 	std::cout<< accept3() << std::endl;
}
