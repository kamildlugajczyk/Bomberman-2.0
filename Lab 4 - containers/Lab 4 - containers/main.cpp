#include <iostream>
#include <string>
#include <list>
#include <map>
#include <cstdlib>

#include "classes.h"


std::ostream& operator<<(std::ostream & stream, const std::list<std::string> & list)
{
	for (const auto& element : list)
		stream << element << std::endl;

	return stream;
}

std::ostream& operator<<(std::ostream & stream, const std::multimap<float, int> & multimap)
{
	for (const auto& element : multimap)
		stream << element.first << ' : ' << element.second << std::endl;

	return stream;
}

int main()
{
	std::list<std::string> students = { "Johnson", "Newman", "Robin", "Oldman", "Parrot" };
	std::multimap<float, int> multiMap = { {2.0, 1}, {3.99, 4} };

	std::cout << students;
	std::cout << multiMap;

	std::map<std::string, std::multimap<float, int>> map;

	student_map studentMap(map);
	
	studentMap.NoteInput("Johnson", 4.5, 2);
	studentMap.NoteInput("NewMan", 4.0, 3);
	studentMap.NoteInput("Johnson", 2.37, 2);
	studentMap.NoteInput("Johnson", 5, 1);

	std::getchar();
	return 0;
}