#include <iostream>
#include <string>


int main()
{
	std::string username;
	std::string password;
	bool isOk;

	do {
		std::cout << "Username: ";
		std::cin >> username;
		std::cout << "Password: ";
		std::cin >> password;

		if (username == "MyName" && password == "secret") {
			std::cout << "\nHello MyName!\n";
			isOk = true;
		}
		else if (username == "YourName" && password == "secret") {
			std::cout << "\nHello YourName!\n";
			isOk = true;
		}
		else {
			std::cout << "Login Failed!";
			isOk = false;
		}

	} while (!isOk);
    std::cout << "\nCongratulations! Login Success!";
    system("pause");
    return 0;
}
