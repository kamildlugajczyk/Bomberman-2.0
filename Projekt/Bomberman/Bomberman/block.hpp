#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "graphic_object.hpp"
#include "enum.hpp"

class Block : public GraphicObject
{
public:
	int type;											// zmienna informujaca o typie bloku
	bool destroyed = false;								// zmienna informujaca o tym czy blok zostal zniszczony
	bool exploded = false;								// zmienna informujaca o tym czy blok zostal eksplodowany

	/* Wirtualna metoda ustawiajaca pozycje sprite'a
	@param deltaTime czas od ostatniej iteracji*/
	virtual void Update(const sf::Time deltaTime);

	/* Czysto wirtualna metoda pozwalajaca na wczytanie
	odpowiedniej dla kazdego bloku tekstury */
	virtual void SetUp() = 0;

	/* Metoda ustawiajaca zmienna expoloded na true */
	void Explode() { exploded = true; };

	/* Metoda ustawiajaca zmienna destroyed na true */
	void Destroy() { destroyed = true; };

	/* Metoda zwracajaca zmienna destroyed*/
	bool IsDestroyed() { return destroyed; };

	/* Metoda zwracajaca zmienna exploded*/
	bool IsExploded() { return exploded; };
};