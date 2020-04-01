#include <iostream>
#include <unordered_set>
#include <unordered_map>

#include "classes.h"

void student_map::NoteInput(std::string name, float weight, int node)
{
	map[name].insert({ node, weight });
}

float student_map::NoteAverage(std::string name)
{
	if (map.count(name))
	{
		int w = 0;
		float n = 0;

		for (auto & element : map[name])
		{
			w += element.first;
			n += element.second * element.first;
		}

		return n / w;
	}
	else
		std::cout << "Brak takiego studenta w bazie!" << std::endl;
}

void student_map::ListOutput()
{
	for (const auto & element : map)
		std::cout << element.first. << ' ' << element.second << '\n';
}

void student_map::AssignStudent(std::string name, std::unordered_multimap<float, int> u_map)
{
	for (auto& x : u_map)
		map[name].insert(x);
}

std::unordered_set<float> student_map::AverageSet()
{
	std::unordered_set<float> temp;

	for (auto & element : map)
		temp.insert(this->NoteAverage(element.first));

	return temp;
}



