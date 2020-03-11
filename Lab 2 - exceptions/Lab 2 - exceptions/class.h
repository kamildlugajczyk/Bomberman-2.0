#include <iostream>
#include <stdexcept>

class Bank
{
	double konto = 500;
	double zdolnoscKredytowa = 200;

public:
	void ZaplacKarta(double kwota);

	void WezKredyt(double kwota);

	Bank(double arg_konto, double arg_zdolnoscKredytowa) 
		: konto(arg_konto), zdolnoscKredytowa(arg_zdolnoscKredytowa) {};
}; 