#include <iostream>
#include <stdexcept>
#include <time.h>

#include "class.h"

void Bank::ZaplacKarta(double kwota)
{
	srand(time(NULL));
	int failure = rand() % 3;

	if (failure) 
	{
		if (kwota > konto) 
			throw std::logic_error("Transakacja zablokowana! Niewystarczajaca ilosc srodkow na koncie. \n");
		else 
			konto -= kwota;
	}
	else 
		throw std::runtime_error("Nastapila awaria systemu platnosci! \n");
}

void Bank::WezKredyt(double kwota)
{

}
