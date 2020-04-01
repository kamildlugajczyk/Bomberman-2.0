#include <iostream>

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
