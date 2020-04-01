#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <ctime>


std::ostream& operator<<(std::ostream & stream, const std::list<std::string> & list)
{
	for (const auto& element : list)
		stream << element << std::endl;

	return stream;
}

std::ostream& operator<<(std::ostream & stream, const std::multimap<float, int> & multimap)
{
	for (const auto& element : multimap)
		stream << element.first << ' ' << element.second << std::endl;

	return stream;
}

int main()
{
	std::list<std::string> workers = { "Johnson", "Newman", "Robin", "Oldman", "Parrot" };
	std::multimap<float, int> map = { {2.0, 1}, {3.99, 4} };

	std::cout << workers;
	std::cout << map;


	


	std::getchar();
	return 0;
}