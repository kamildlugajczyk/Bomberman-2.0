#include <iostream>
#include <SFML/Graphics.hpp>

#include "breakable_wall.hpp"

BreakableWall::BreakableWall()
	:type(breakableBlock) {};

void BreakableWall::SetUp()
{
	if (!breakable_wall.loadFromFile("res/img/explodableBlock.png"))
	{
		throw std::runtime_error("Can't open the file: explodableBlock.png");
	}

	LoadTexture(breakable_wall);
}
