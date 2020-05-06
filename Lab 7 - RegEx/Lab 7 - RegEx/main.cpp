#include <iostream>

#include "functions.hpp"

int main()
{
	std::string login1("SuperKoksu420");
	std::cout << login1 << " result: " << isLoginValid(login1) << std::endl;

	std::string login2("the_best_gamer");
	std::cout << login2 << " result: " << isLoginValid(login2) << std::endl;

	std::string login3(";DROP TABLE USERS;");
	std::cout << login3 << " result: " << isLoginValid(login3) << std::endl;

	std::string login4("Rick&Morty");
	std::cout << login4 << " result: " << isLoginValid(login4) << std::endl;

	std::string login5("ilikegames");
	std::cout << login5 << " result: " << isLoginValid(login5) << std::endl;

	std::getchar();
	return 0;
}