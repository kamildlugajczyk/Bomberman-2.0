#include <iostream>
#include <SFML/Graphics.hpp>

#include "bomb.hpp"
#include "explosion.hpp"

Bomb::Bomb() : explodeTime(3.f), type(bombBlock)
{
	sprite.setOrigin(-10, -10);
}

void Bomb::Update(const sf::Time deltaTime)
{
	sprite.setPosition(position);

	explodeTime -= deltaTime.asSeconds();
	if (explodeTime <= 0)
		this->Destroy();
}

void Bomb::SetUp()
{
	if (!bombTexture.loadFromFile("res/img/bomb.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}
	LoadTexture(bombTexture);
}

