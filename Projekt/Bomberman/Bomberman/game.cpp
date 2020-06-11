#include <iostream>
#include <vector>
#include <thread>
#include <exception>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <windows.h>

#include "game.hpp"
#include "player.hpp"
#include "map.hpp"
#include "solid_wall.hpp"
#include "breakable_wall.hpp"
#include "bomb.hpp"
#include "end_game_screen.hpp"
#include "main_menu.hpp"

static bool gotConnection = false;
static bool pressedEsc = false;

Game::Game()
{
	player1.SetPosition(sf::Vector2f(96, 96));
	player2.SetPosition(sf::Vector2f(864, 604));

	isOver = false;
}

void Game::Update(const sf::Time deltaTime, Map & map)
{
	map.Update(deltaTime);
	player1.Update(deltaTime);
	player2.Update(deltaTime);
}

void Game::Draw(sf::RenderWindow & window, Map & map)
{
	map.Draw(window);
	player1.Draw(window);
	player2.Draw(window);

	if (isOver)
		endGameScreen.Draw(window);
}

void Game::Play(sf::RenderWindow & window)
{
	Map map;														// mapa gry

	sf::Clock clock;
	sf::Time time;

	try
	{
		player1.LoadTexture("res/img/character1.png");
		player2.LoadTexture("res/img/character2.png");
		endGameScreen.LoadFont();
		map.LoadFromFile();
		map.LoadTiles();
	}
	catch (std::runtime_error & exception)
	{
		std::string message;
		message = exception.what() + (std::string)". Program will abort.";
		MessageBoxA(NULL, (LPCSTR)message.c_str(), "Exception", MB_ICONSTOP);
		return;
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
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
					PlayAgain(map);
				else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
					return;
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
				endGameScreen.DisplayPlayer1Win(false, true);
			}
			else if (player2.IsKilled())
			{
				isOver = true;
				endGameScreen.DisplayPlayer1Win(true, true);
			}
		}

		Update(time, map);

		Draw(window, map);
		window.display();

	}
}

void Game::PlayLAN(sf::RenderWindow & window)
{
	sf::TcpSocket socket;
	pressedEsc = false;
	gotConnection = false;

	std::thread listenerTCP(&Game::ListenTCP, std::ref(socket));
	
	while (!gotConnection && !pressedEsc)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					pressedEsc = true;
					break;
				}
			}
		}
	}

	listenerTCP.join();

	if (pressedEsc)
		return;
	else
	{
		Map map;														// mapa gry
		sf::Clock clock;
		sf::Time time;
		std::string data;
		std::string response;
		std::size_t received;
		char buffer[2000];

		try
		{
			player1.LoadTexture("res/img/character1.png");
			player2.LoadTexture("res/img/character2.png");
			endGameScreen.LoadFont();
			map.LoadFromFile();
			map.LoadTiles();
		}
		catch (std::runtime_error & exception)
		{
			std::string message;
			message = exception.what() + (std::string)". Program will abort.";
			MessageBoxA(NULL, (LPCSTR)message.c_str(), "Exception", MB_ICONSTOP);
			return;
		}

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			if (isOver)
			{
				int playOrQuit;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{
					playOrQuit = 1;
					socket.send(toString(playOrQuit).c_str(), toString(playOrQuit).length() + 1);
					PlayAgain(map);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					playOrQuit = 0;
					socket.send(toString(playOrQuit).c_str(), toString(playOrQuit).length() + 1);

					socket.disconnect();
					isOver = false;
					return;
				}
			}

			window.clear(sf::Color::Black);
			time = clock.restart();

			if (!isOver)
			{
				data.clear();																//czyszcze string
				memset(buffer, 0, sizeof buffer);											//czyszcze bufor
				received = 0;																//czyszcze 

				int positionX = 0;
				int positionY = 0;

				int bombX = -1;
				int bombY = -1;

				isOtherPlayerKilled = false;
				direction = 1;

				player1.MoveWSAD(time, map);
				player1.GetDataForLAN(data);
				socket.send(data.c_str(), data.length() + 1);							//wysylam moja pozycje
				socket.receive(buffer, sizeof(buffer), received);						//odbieram pozycje przeciwnika

				sscanf_s(buffer, "%d %d %d %d %d %d", &positionX, &positionY, &direction, &bombX, &bombY, &isOtherPlayerKilled);
				player2.SetPositionForLAN(positionX, positionY);						//wczytuje pozycje przeciwnika
				player2.SetMovingSate(direction);

				if (bombX != -1 && bombY != -1)
				{
					Bomb * bomb = new Bomb{};
					bomb->SetUp();
					player2.bombPlaced++;

					sf::Vector2f bombXY;
					bombXY.x = bombX;
					bombXY.y = bombY;

					bomb->SetPosition(bombXY);
					map.blocks[(int)(bombXY.y) / 64][(int)(bombXY.x) / 64] = bomb;
					map.blocks[(int)(bombXY.y) / 64][(int)(bombXY.x) / 64]->type = bombBlock;
				}

				if (player1.IsKilled())
				{
					isOver = true;
					endGameScreen.DisplayPlayer1Win(false, true);
				}
				else if (isOtherPlayerKilled)
				{
					isOver = true;
					endGameScreen.DisplayPlayer1Win(true, true);
				}
			}
			Update(time, map);
			Draw(window, map);
			window.display();
		}
	}
}

void Game::PlayLAN(sf::RenderWindow & window, std::string ip)
{
	sf::TcpSocket socket;

	if (socket.connect(ip, 53000) != sf::Socket::Done)
	{
		return;
	}
	else
	{
		Map map;														// mapa gry
		sf::Clock clock;
		sf::Time time;

		std::string data;
		std::string response;
		std::size_t received;
		char buffer[2000];

		try
		{
			player1.LoadTexture("res/img/character1.png");
			player2.LoadTexture("res/img/character2.png");
			endGameScreen.LoadFont();
			map.LoadFromFile();
			map.LoadTiles();
		}
		catch (std::runtime_error & exception)
		{
			std::string message;
			message = exception.what() + (std::string)". Program will abort.";
			MessageBoxA(NULL, (LPCSTR)message.c_str(), "Exception", MB_ICONSTOP);
			return;
		}
		

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			if (isOver)
			{
				int playOrQuit = 0;

				socket.receive(buffer, sizeof(buffer), received);

				sscanf_s(buffer, "%d", &playOrQuit);										
				memset(buffer, 0, sizeof buffer);											
				received = 0;

				if (playOrQuit)
				{
					PlayAgain(map);
				}
				else
				{
					socket.disconnect();
					return;
				}
			}

			window.clear(sf::Color::Black);
			time = clock.restart();

			if (!isOver)
			{
				data.clear();																//czyszcze string
				memset(buffer, 0, sizeof buffer);											//czyszcze bufor
				received = 0;																//czyszcze 

				int bombX = -1;
				int bombY = -1;

				int positionX = 0;
				int positionY = 0;

				isOtherPlayerKilled = false;
				direction = 1;

				player2.MoveWSAD(time, map);
				player2.GetDataForLAN(data);
				socket.send(data.c_str(), data.length() + 1);							//wysylam moja pozycje
				socket.receive(buffer, sizeof(buffer), received);						//odbieram pozycje przeciwnika

				sscanf_s(buffer, "%d %d %d %d %d %d", &positionX, &positionY, &direction, &bombX, &bombY, &isOtherPlayerKilled);
				player1.SetPositionForLAN(positionX, positionY);						//wczytuje pozycje przeciwnika
				player1.SetMovingSate(direction);

				if (bombX != -1 && bombY != -1)
				{
					Bomb * bomb = new Bomb{};
					bomb->SetUp();
					player1.bombPlaced++;

					sf::Vector2f bombXY;
					bombXY.x = bombX;
					bombXY.y = bombY;

					bomb->SetPosition(bombXY);
					map.blocks[(int)(bombXY.y) / 64][(int)(bombXY.x) / 64] = bomb;
					map.blocks[(int)(bombXY.y) / 64][(int)(bombXY.x) / 64]->type = bombBlock;
				}

				if (isOtherPlayerKilled)
				{
					isOver = true;
					endGameScreen.DisplayPlayer1Win(false, false);
				}
				else if (player2.IsKilled())
				{
					isOver = true;
					endGameScreen.DisplayPlayer1Win(true, false);
				}
			}
			Update(time, map);
			Draw(window, map);
			window.display();
		}
	}
}

void Game::PlayAgain(Map & map)
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

void Game::ListenTCP(sf::TcpSocket & socket)
{
	sf::TcpListener listener;
	listener.listen(53000);
	listener.setBlocking(false);

	while (!gotConnection && !pressedEsc)
	{
		if (listener.accept(socket) == sf::Socket::Done)
		{
			gotConnection = true;
		}
	}
}