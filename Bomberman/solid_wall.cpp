#include <iostream>
#include <SFML/Graphics.hpp>

#include "solid_wall.hpp"
#include "block.hpp"

SolidWall::SolidWall()
	:type(solidBlock) {};

void SolidWall::SetUp()
{
	if (!solid_texture.loadFromFile("res/img/SolidBlock.png"))
	{
		throw std::runtime_error("Can't open the file: SolidBlock.png");
	}

	LoadTexture(solid_texture);
}
