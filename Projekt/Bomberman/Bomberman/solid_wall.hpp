#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "wall.hpp"

class SolidWall : public Wall
{
	int type;											// zmienna informujaca o typie bloku
	sf::Texture solid_texture;							// tesktura niezniszczalnej sciany
public:
	/* Konstruktor bezargumentowy ustawiajacy typ bloku */
	SolidWall();

	/* Metoda wczytujaca odpowiednia teksture niezniszczalnej sciany */
	virtual void SetUp() override;
};