#include <iostream>
#include <string>

int main()
{
	std::string username;
	std::string password;
	std::cout << "Password Checking!\n";
	bool isOK = false;

	do {
		std::cout << "\nUsername: ";
		std::cin >> username;
		std::cout << "Password: ";
		std::cin >> password;

		if (username == "Melvin" && password == "secret") {
			std::cout << "Hello Melvin!";
			isOK = true;
		}
		else {
			std::cout << "Login Failed";
			isOK = false;
		}

	} while (!isOK);
	std::cout << "\nCongratulations! Login Success!\n";
	system("pause");
  return 0;
}
