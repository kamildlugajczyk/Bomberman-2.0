#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "player.hpp"
#include "map.hpp"
#include "solid_wall.hpp"
#include "breakable_wall.hpp"
#include "bomb.hpp"
#include "end_game_screen.hpp"

Game::Game()
{
	windowSize.x = 960;
	windowSize.y = 700;
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "Bomberman");

	window.setFramerateLimit(60);

	player1.SetPosition(sf::Vector2f( 96, 96));
	player2.SetPosition(sf::Vector2f( 864, 604));

	isOver = false;
}

void Game::Update(const sf::Time deltaTime)
{
	map.Update(deltaTime);
	player1.Update(deltaTime);
	player2.Update(deltaTime);
}

void Game::Draw()
{
	map.Draw(window);
	player1.Draw(window);
	player2.Draw(window);

	if (isOver)
		endGameScreen.Draw(window);
}

void Game::Play()
{
	sf::Clock clock;
	sf::Time time;

	if (!font.loadFromFile("res/fonts/SFPixelate.ttf"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
		return;
	}
	else
		endGameScreen.LoadFont(font);

	////-------------- gracz 1 ---------------------------
	if (!player1.texture_p1.loadFromFile("res/img/character1.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
		return;
	}
	//-------------- gracz 2 ---------------------------
	if (!player2.texture_p2.loadFromFile("res/img/character2.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
		return;
	}
	//--------------------------------------------------

	player1.LoadTexture(player1.texture_p1);
	player2.LoadTexture(player2.texture_p2);
	map.LoadFromFile();
	map.LoadTiles();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();

			if (isOver)
			{
				if (player2.IsKilled() && once)
				{
					player1.SaveToFile(true);
					player2.SaveToFile(false);
				}
				else if (player1.IsKilled() && once)
				{
					player2.SaveToFile(true);
					player1.SaveToFile(false);
				}

				once = false;

				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
					PlayAgain();
				else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
					window.close();
			}
		}

		window.clear(sf::Color::Black);
		time = clock.restart();


		if (!isOver)
		{
			player1.MoveWSAD(time, map);
			player2.MoveArrows(time, map);

			if (player1.IsKilled())
			{
				isOver = true;
				endGameScreen.DisplayPlayer1Win(false);
			}
			else if (player2.IsKilled())
			{
				isOver = true;
				endGameScreen.DisplayPlayer1Win(true);
			}
		}

		Update(time);

		Draw();
		window.display();

	}
}

//-------------------LAN-------------------//

void Game::PlayLAN()
{
	sf::Clock clock;
	sf::Time time;

	if (!font.loadFromFile("res/fonts/SFPixelate.ttf"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
		return;
	}
	else
		endGameScreen.LoadFont(font);

	////-------------- gracz 1 ---------------------------
	if (!player1.texture_p1.loadFromFile("res/img/character1.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
		return;
	}
	//-------------- gracz 2 ---------------------------
	if (!player2.texture_p2.loadFromFile("res/img/character2.png"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
		return;
	}
	//--------------------------------------------------

	player1.LoadTexture(player1.texture_p1);
	player2.LoadTexture(player2.texture_p2);
	map.LoadFromFile();
	map.LoadTiles();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();

			if (isOver)
			{
				if (player2.IsKilled() && once)
				{
					player1.SaveToFile(true);
					player2.SaveToFile(false);
				}
				else if (player1.IsKilled() && once)
				{
					player2.SaveToFile(true);
					player1.SaveToFile(false);
				}

				once = false;

				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
					PlayAgain();
				else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
					window.close();
			}
		}

		window.clear(sf::Color::Black);
		time = clock.restart();


		if (!isOver)
		{
			player1.MoveWSAD(time, map);
			player2.MoveArrows(time, map);

			if (player1.IsKilled())
			{
				isOver = true;
				endGameScreen.DisplayPlayer1Win(false);
			}
			else if (player2.IsKilled())
			{
				isOver = true;
				endGameScreen.DisplayPlayer1Win(true);
			}
		}
		//---------- TODO Update -----------//
		Update(time);
		//----------------------------------//

		Draw();
		window.display();

	}
}

//-----------------------------------------//

void Game::PlayAgain()
{
	isOver = false;

	map.LoadFromFile();
	map.LoadTiles();

	player1.SetPosition(sf::Vector2f(96, 96));
	player2.SetPosition(sf::Vector2f(864, 604));

	player1.killed = false;
	player2.killed = false;

	player1.bombPlaced = 0;
	player2.bombPlaced = 0;

	once = true;
}
