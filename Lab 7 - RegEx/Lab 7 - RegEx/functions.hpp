#pragma once
#include <iostream>
#include <regex>

bool isLoginValid(std::string login);

bool isEmailValid(std::string email);

void showMatches(std::string string, std::regex regex);