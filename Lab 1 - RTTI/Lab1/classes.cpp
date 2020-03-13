#include <iostream>
#include <typeinfo>
#include "classes.hpp"

void Firma::uregulowana()
{
	do_uregulowania = 0;
}

void Detal::sprzedaz()
{
	do_uregulowania += 4000;
}

void Hurt::sprzedaz()
{
	do_uregulowania += 3000;
}

void Komputery::dostawa()
{
	do_uregulowania -= 60000;
}

void Sluchawki::dostawa()
{
	do_uregulowania -= 5000;
}
