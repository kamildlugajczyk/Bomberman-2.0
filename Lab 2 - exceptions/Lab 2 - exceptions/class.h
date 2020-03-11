#include <iostream>
#include <stdexcept>

class Bank
{
	double konto = 500;
	double zdolnoscKredytowa = 200;

public:
	void ZaplacKarta(double kwota);
	void WezKredyt(double kwota);
	Bank();
};