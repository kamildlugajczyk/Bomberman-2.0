#include <iostream>
#include <thread>
#include <string>

#include "reactor.hpp"

class ReaktorMK2 : public Reaktor
{
public:
	ReaktorMK2(int arg_paliwo, std::string arg_nazwa)
		: Reaktor{ arg_paliwo, arg_nazwa } {};

	void operator() (int moc);
};