#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "wall.hpp"
#include "enum.hpp"

class BreakableWall : public Wall
{
	int type;										// zmienna informujaca o typie bloku
	sf::Texture breakable_wall;						// tesktura zniszczalnej sciany
public:
	/* Konstruktor bezargumentowy ustawiajacy typ bloku */
	BreakableWall();

	/* Metoda wczytujaca odpowiednia teksture zniszczalnej sciany */
	virtual void SetUp() override;
};