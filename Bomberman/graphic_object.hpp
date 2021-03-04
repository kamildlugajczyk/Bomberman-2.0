#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class GraphicObject
{
protected:
	sf::Vector2f position;
	sf::FloatRect collisionBox;
	sf::Sprite sprite;

public:
	/* Metoda zwarajaca aktualna pozycje obiektu */
	 sf::Vector2f GetPosition();

	 /* Metoda ustawiajaca aktualna pozycje obiektu */
	void SetPosition(const sf::Vector2f & position);

	/* Metoda zwarajaca obszar kolizyjny obiektu */
	sf::FloatRect GetCollisionBox();

	/* Metoda wczytujaca do sprite'a podana w parametrze teksture */
	void LoadTexture(const sf::Texture & texture);

	/* Metoda rysujaca sprite'y */
	void Draw(sf::RenderWindow & window);
};