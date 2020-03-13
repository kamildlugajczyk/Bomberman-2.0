#include <iostream>
#include <SFML/Graphics.hpp>

#include "breakable_wall.hpp"

BreakableWall::BreakableWall()
	:type(breakableBlock) {};

void BreakableWall::SetUp()
{
	if (!breakable_wall.loadFromFile("res/img/explodableBlock.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
	}

	LoadTexture(breakable_wall);
}
