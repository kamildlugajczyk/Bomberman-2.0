#include <iostream>
#include <regex>


#include "functions.hpp"

bool isLoginValid(std::string login)
{
	std::regex checkRegex("^\\w+$");
	return std::regex_match(login, checkRegex);
}