#include <iostream>
#include <map>

class student_map
{
	std::map<std::string, std::multimap<float, int>> studentMap;

public:
	student_map(std::map<std::string, std::multimap<float, int>> s)
		: studentMap(s) {};


};