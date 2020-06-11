#pragma once
#include <string>

template <typename T>
std::string toString(T i)
{
	std::stringstream ss;
	ss << i;

	return ss.str();
}