#pragma once
#include <string>

/* Metoda szablonowa przyjmujaca rozne typy danych ktore
zamienia na ciag znakow. Potrzeba napisania wlasnej funkcji
spowodowana byla niepoprawna konwersja liczby calkowitej np. 2
na string 2.000000 co przeszkadzalo w przesylaniu danych. */
template <typename T>
std::string toString(T i)
{
	std::stringstream ss;
	ss << i;

	return ss.str();
}