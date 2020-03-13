#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "block.hpp"

class Explosion : public Block
{
	int type;										// typ bloku
	float flameTime;								// zmienna okreslajaca czas po ktorym zniknie eksplozja
	sf::Texture explosionTexture;					// tesktura bomby

public:
	/* Konstruktor bezargumentowy bomby ustawiajacy jej domyslny
	flameTime oraz ustawiajacy setOrigin() w celu wysrodkowania
	jej w kafelku gry oraz obszar kolizyjny */
	Explosion();

	/* Metoda ustawiajaca pozycje sprite'a oraz sprawdzajaca
	czy nadszedl czas na usuniecie eksplozji
	@param deltaTime czas od ostatniej iteracji */
	void Update(const sf::Time deltaTime) override;

	/* Metoda wczytujaca odpowiednia teksture eksplozji 
	i ustawiajaca ja dla sprite'a */
	virtual void SetUp() override;
};