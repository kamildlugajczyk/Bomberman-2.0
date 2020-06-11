#include <iostream>
#include <SFML/Graphics.hpp>

#include "explosion.hpp"

Explosion::Explosion() : flameTime(1.f)
{
	collisionBox.top = this->GetPosition().y;
	collisionBox.left = this->GetPosition().x;
	collisionBox.width = 64;
	collisionBox.height = 64;

	sprite.setOrigin(-10, -10);
}

void Explosion::Update(const sf::Time deltaTime)
{
	sprite.setPosition(position);

	flameTime -= deltaTime.asSeconds();
	if (flameTime <= 0)
		this->Explode();
}

void Explosion::SetUp()
{
	if (!explosionTexture.loadFromFile("res/img/flame.png"))
	{
		throw std::runtime_error("Can't open the file: flame.png");
	}

	LoadTexture(explosionTexture);
}
