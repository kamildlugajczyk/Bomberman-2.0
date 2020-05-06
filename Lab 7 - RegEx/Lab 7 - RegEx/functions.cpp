#include <iostream>
#include <regex>


#include "functions.hpp"

bool isLoginValid(std::string login)
{
	std::regex checkRegex("\\w+");
	return std::regex_match(login, checkRegex);
}

bool isEmailValid(std::string email)
{
	std::regex checkRegex("([a-zA-Z]+[a-zA-Z0-9_\\-\\.]{0,20})@([a-zA-Z0-9_\\-\\.]{1,10})\\.([a-zA-Z]{2,5})");
	return std::regex_match(email, checkRegex);
}
