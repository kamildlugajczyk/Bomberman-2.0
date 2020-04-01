#include <iostream>
#include <map>

class student_map
{
	std::map<std::string, std::multimap<float, int>> map;

public:
	student_map(std::map<std::string, std::multimap<float, int>> s)
		: map(s) {};

	void NoteInput(std::string name, float weight, int node);


};