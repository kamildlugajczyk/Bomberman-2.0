#include <iostream>
#include <string>
#include <list>
#include <unordered_set>
#include <unordered_map>
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

std::ostream& operator<<(std::ostream& stream, const std::map<std::string, std::multimap<float, int>>& multiMap)
{
	for (const auto& element : multiMap)
		stream << element.first << '\n' << element.second << '\n';
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
	
	studentMap.NoteInput("Johnson", 3, 2);
	studentMap.NoteInput("Johnson", 5, 2);
	studentMap.NoteInput("NewMan", 4.0, 3);
	studentMap.NoteInput("Robin", 2.37, 2);
	studentMap.NoteInput("Oldman", 5, 1);

	std::cout << "Srednia: " << studentMap.NoteAverage("Johnson") << std::endl;

	studentMap.ListOutput();

	std::unordered_multimap<float, int> temp = { {2.3, 2}, {4.2, 4}, {3.75, 1} };
	studentMap.assignStudent("Janoski", temp);

	std::getchar();
	return 0;
}