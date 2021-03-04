#include <iostream>
#include <vector>
#include <exception>
#include <SFML/Graphics.hpp>

#include "map.hpp"
#include "solid_wall.hpp"
#include "breakable_wall.hpp"
#include "background.hpp"
#include "bomb.hpp"
#include "explosion.hpp"

Map::Map() : tileSize(64) {};

Map::~Map()
{
	for (int w = 0; w < 11; w++)
	{
		for (int k = 0; k < 15; k++)
		{
			delete blocks[w][k];
			blocks[w][k] = nullptr;
		}
	}
}


void Map::LoadTiles()
{
	Bomb * checkBomb = new Bomb{};				// testowe stworzenie bomby w celu
	checkBomb->SetUp();							// sprawdzenia czy tekstura znajduje
	delete checkBomb;							// sie w plikach 

	Explosion * checkExplosion = new Explosion{};	// testowe stworzenie eksplozji w celu
	checkExplosion->SetUp();						// sprawdzenia czy tekstura znajduje
	delete checkExplosion;							// sie w plikach 

	for (int w = 0; w < 11; w++)
	{
		for (int k = 0; k < 15; k++)
		{
			if (gameMap[w][k] == 1)									// 0 nic , 1 do zniszczenia, 2 nie do zniszczenia
			{
				Block * breakable = new BreakableWall{};
				blocks[w][k] = breakable;
				blocks[w][k]->SetPosition(sf::Vector2f(k * tileSize, w * tileSize));
				blocks[w][k]->SetUp();
				blocks[w][k]->type = breakableBlock;
			}
			else if (gameMap[w][k] == 2)
			{
				Block * solid = new SolidWall{};
				blocks[w][k] = solid;
				blocks[w][k]->SetPosition(sf::Vector2f(k * tileSize, w * tileSize));
				blocks[w][k]->SetUp();
				blocks[w][k]->type = solidBlock;
			}
			else if (gameMap[w][k] == 0)
			{
				Block * background = new Background{};
				blocks[w][k] = background;
				blocks[w][k]->SetPosition(sf::Vector2f(k * tileSize, w * tileSize));
				blocks[w][k]->SetUp();
				blocks[w][k]->type = backgroundBlock;
			}
		}
	}
}

void Map::Update(const sf::Time deltaTime)
{
	for (int w = 0; w < 11; w++)
		for (int k = 0; k < 15; k++)
		{
			blocks[w][k]->Update(deltaTime);

			if (blocks[w][k]->ShouldCollide())
				blocks[w][k]->type = solidBlock;

			if (blocks[w][k]->IsDestroyed())
			{
				delete blocks[w][k];													// usuwam bombe

				Block * explosion1 = new Explosion{};
				blocks[w][k] = explosion1;												
				blocks[w][k]->SetPosition(sf::Vector2f(k * tileSize, w * tileSize));
				blocks[w][k]->SetUp();
				blocks[w][k]->type = explosionBlock;

				if (blocks[w - 1][k]->type != solidBlock)
				{
					delete blocks[w - 1][k];

					Block * explosion4 = new Explosion{};
					blocks[w - 1][k] = explosion4;											
					blocks[w - 1][k]->SetPosition(sf::Vector2f(k * tileSize, (w - 1) * tileSize));
					blocks[w - 1][k]->SetUp();
					blocks[w - 1][k]->type = explosionBlock;
				}
				if (blocks[w + 1][k]->type != solidBlock)
				{
					delete blocks[w + 1][k];

					Block * explosion5 = new Explosion{};
					blocks[w + 1][k] = explosion5;												
					blocks[w + 1][k]->SetPosition(sf::Vector2f(k * tileSize, (w + 1) * tileSize));
					blocks[w + 1][k]->SetUp();
					blocks[w + 1][k]->type = explosionBlock;
				}
				if (blocks[w][k - 1]->type != solidBlock)
				{
					delete blocks[w][k - 1];

					Block * explosion2 = new Explosion{};
					blocks[w][k - 1] = explosion2;											
					blocks[w][k - 1]->SetPosition(sf::Vector2f((k - 1) * tileSize, w * tileSize));
					blocks[w][k - 1]->SetUp();
					blocks[w][k - 1]->type = explosionBlock;
				}
				if (blocks[w][k + 1]->type != solidBlock)
				{
					delete blocks[w][k + 1];

					Block * explosion3 = new Explosion{};
					blocks[w][k + 1] = explosion3;												
					blocks[w][k + 1]->SetPosition(sf::Vector2f((k + 1) * tileSize, w * tileSize));
					blocks[w][k + 1]->SetUp();
					blocks[w][k + 1]->type = explosionBlock;
				}
			}

			if (blocks[w][k]->IsExploded())
			{
				delete blocks[w][k];

				Background * background = new Background{};								// w tym miejscu tworze blok tla
				blocks[w][k] = background;												// .
				blocks[w][k]->SetPosition(sf::Vector2f(k * tileSize, w * tileSize));				// .
				blocks[w][k]->SetUp();
				blocks[w][k]->type = backgroundBlock;
			}
		}
}

void Map::Draw(sf::RenderWindow & window)
{
	for (int w = 0; w < 11; w++)			
		for (int k = 0; k < 15; k++)
			blocks[w][k]->Draw(window);
}

void Map::LoadFromFile()
{
	std::ifstream inputFile("res/map/map.txt");
	if (inputFile.is_open())
	{
		for (int w = 0; w < 11; w++)
			for (int k = 0; k < 15; k++)
			{
				inputFile >> gameMap[w][k];
			}
		inputFile.close();
	}
	else
	{
		throw std::runtime_error("Can't open the file: map.txt");
	}
}