#include <iostream>
#include <typeinfo>

#include "classes.hpp"

int main()
{
	Hurt * hurt = new Hurt;
	Detal * detal = new Detal;
	Komputery * pc = new Komputery;
	Sluchawki * headphones = new Sluchawki;

	Firma * firmy[] = { hurt , detal, pc, headphones };

	for (auto firma : firmy)
	{
		Nabywca *nabywca = dynamic_cast<Nabywca*>(firma);
		if (nabywca != nullptr)
		{
			for (int i = 0; i < 3; i++)
				nabywca->sprzedaz();

			std::cout << "Dziedziczy z nabywca.\n";
		}

		Dostawca *dostawca = dynamic_cast<Dostawca*>(firma);
		if (dostawca != nullptr)
		{
			for (int i = 0; i < 4; i++)
				dostawca->dostawa();

			std::cout << "Dziedziczy z dostawca.\n";
		}

		std::cout << "Klasa: " << typeid(*firma).name();
		std::cout << "\nKwota do uregulowania: " << firma->do_uregulowania << "\n\n";
	}

	std::getchar();
	return 0;
}