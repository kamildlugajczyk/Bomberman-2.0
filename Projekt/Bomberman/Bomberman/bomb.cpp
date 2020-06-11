#include <iostream>
#include <SFML/Graphics.hpp>

#include "bomb.hpp"
#include "explosion.hpp"

Bomb::Bomb() : explodeTime(3.f), collideTime(0.5f), type(bombBlock)
{
	sprite.setOrigin(-10, -10);
}

void Bomb::Update(const sf::Time deltaTime)
{
	sprite.setPosition(position);

	explodeTime -= deltaTime.asSeconds();
	collideTime -= deltaTime.asSeconds();

	if (collideTime <= 0)
		this->Collide();

	 if (explodeTime <= 0)
		this->Destroy();
}

void Bomb::SetUp()
{
	if (!bombTexture.loadFromFile("res/img/bomb.png"))
	{
		throw std::runtime_error("Can't open the file: bomb.png");
	}
	LoadTexture(bombTexture);
}

