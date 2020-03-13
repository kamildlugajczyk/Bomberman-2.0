#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "block.hpp"

class Bomb : public Block
{
	int type;									// typ bloku
	float explodeTime;							// zmienna okreslajaca czas po ktorym eksploduje bomba
	sf::Texture bombTexture;					// tesktura bomby

public:
	/* Konstruktor bezargumentowy bomby ustawiajacy jej domyslny
	explodeTime oraz ustawiajacy setOrigin() w celu wysrodkowania 
	jej w kafelku gry */
	Bomb();

	/* Metoda ustawiajaca pozycje sprite'a oraz sprawdzajaca
	czy nadszedl czas na zniszczenie bomby (a wstawienie eksplozji)
	@param deltaTime czas od ostatniej iteracji */
	virtual void Update (const sf::Time deltaTime) override;

	/* Metoda wczytujaca odpowiednia teksture bomby i 
	ustawiajaca ja dla sprite'a */
	virtual void SetUp() override;
};