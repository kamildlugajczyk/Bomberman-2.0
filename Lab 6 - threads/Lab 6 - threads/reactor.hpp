#include <iostream>
#include <string>

class Reaktor
{
	int paliwo;
	std::string nazwa;

public:
	Reaktor(int arg_paliwo, std::string arg_nazwa)
		: paliwo(arg_paliwo), nazwa(arg_nazwa) {};

	void operator() (int moc);
};
