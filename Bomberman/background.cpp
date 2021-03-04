#include <iostream>
#include <SFML/Graphics.hpp>

#include "background.hpp"

Background::Background()
	: type(backgroundBlock) {};

void Background::SetUp()
{
	if (!backgroundTexture.loadFromFile("res/img/background.png"))
	{
		throw std::runtime_error("Can't open the file: background.png");
	}

	LoadTexture(backgroundTexture);
}
