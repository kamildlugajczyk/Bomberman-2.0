#include <iostream>
#include <thread>

#include "reactor.hpp"

void Reaktor::operator() (int moc)
{
	while (paliwo - moc > 0)
	{
		paliwo -= moc;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << " Nazwa: " << nazwa << "\n Ilosc paliwa: " << paliwo << std::endl << std::endl;
	}
}
