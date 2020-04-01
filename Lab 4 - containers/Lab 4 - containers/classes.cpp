#include <iostream>

#include "classes.h"

void student_map::NoteInput(std::string name, float weight, int node)
{
	map[name].insert({ node, weight });
}
