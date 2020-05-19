#include <iostream>
#include <vector>
#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "game.hpp"
#include "player.hpp"
#include "map.hpp"
#include "solid_wall.hpp"
#include "breakable_wall.hpp"
#include "bomb.hpp"
#include "end_game_screen.hpp"
#include "main_menu.hpp"

static bool gotConnection = false;

Game::Game()
{
	windowSize.x = 960;
	windowSize.y = 700;
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "Bomberman");

	window.setFramerateLimit(60);

	player1.SetPosition(sf::Vector2f(96, 96));
	player2.SetPosition(sf::Vector2f(864, 604));

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
	MainMenu menu;
	

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
		menu.Draw(window);
		window.display();
		std::getchar();
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
				endGameScreen.DisplayPlayer1Win(false, true);
			}
			else if (player2.IsKilled())
			{
				isOver = true;
				endGameScreen.DisplayPlayer1Win(true, true);
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
	

	// temporary
	char choice;
	std::cout << "s - server, c - client" << std::endl;
	std::cin >> choice;
	//------------


	sf::Clock clock;
	sf::Time time;


	sf::TcpSocket socket;
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	std::string data;
	std::string response;
	std::size_t received;
	char buffer[2000];

	if (choice == 'c')
	{
		//std::cout << "Podaj adres servera: \n";
		//std::cin >> ip;

		socket.connect(ip, 53000);
	}
	else if (choice == 's')
	{
		sf::TcpListener listener;
		listener.listen(53000);
		listener.accept(socket);
		std::cout << "Connection accepted" << std::endl;
		//std::thread listenerTCP;
		//listenerTCP = std::thread([&] { this->ListenTCP(socket); });

	}

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

	
	if (choice == 's')
	{
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
					window.close();
			}

			if (isOver)
			{
				std::string playOrQuit;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{
					playOrQuit = '1';
					socket.send(playOrQuit.c_str(), playOrQuit.length() + 1);
					PlayAgain();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					playOrQuit = '0';
					socket.send(playOrQuit.c_str(), playOrQuit.length() + 1);
					window.close();
				}
			}

			window.clear(sf::Color::Black);
			time = clock.restart();

			if (!isOver)
			{
				bool isOtherPlayerKilled = false;
				bool direction = 1;

				data.clear();																//czyszcze string
				memset(buffer, 0, sizeof buffer);											//czyszcze bufor
				received = 0;																//czyszcze 

				int positionX = 0;
				int positionY = 0;

				int bombX = -1;
				int bombY = -1;

				player1.MoveWSAD(time, map);
				player1.GetDataForLAN(data);
				socket.send(data.c_str(), data.length() + 1);							//wysylam moja pozycje
				socket.receive(buffer, sizeof(buffer), received);						//odbieram pozycje przeciwnika

				sscanf_s(buffer, "%d %d %d %d %d %d ", &positionX, &positionY, &direction, &bombX, &bombY, &isOtherPlayerKilled);
				player2.SetPositionForLAN(positionX, positionY);						//wczytuje pozycje przeciwnika
				player2.SetMovingSate(direction);

				// tymczasowe plantowanie bomby
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
			Update(time);
			Draw();
			window.display();
		}
	}
	else if (choice == 'c')
	{
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
					window.close();

			}

			if (isOver)
			{
				data.clear();																//czyszcze string
				memset(buffer, 0, sizeof buffer);											//czyszcze bufor
				received = 0;

				bool playOrQuit;
				// Dodac czekanie jako osobny watek
				socket.receive(buffer, sizeof(buffer), received);
				sscanf_s(buffer, "%d ", &playOrQuit);

				if (playOrQuit)
				{
					PlayAgain();
				}
				else if (!playOrQuit)
				{
					window.close();
				}
			}

			window.clear(sf::Color::Black);
			time = clock.restart();

			if (!isOver)
			{
				bool isOtherPlayerKilled = false;
				bool direction = 1;

				data.clear();																//czyszcze string
				memset(buffer, 0, sizeof buffer);											//czyszcze bufor
				received = 0;																//czyszcze 

				int bombX = -1;
				int bombY = -1;

				int positionX = 0;
				int positionY = 0;

				player2.MoveArrows(time, map);
				player2.GetDataForLAN(data);
				socket.send(data.c_str(), data.length() + 1);							//wysylam moja pozycje
				socket.receive(buffer, sizeof(buffer), received);						//odbieram pozycje przeciwnika

				sscanf_s(buffer, "%d %d %d %d %d %d", &positionX, &positionY, &direction, &bombX, &bombY, &isOtherPlayerKilled);
				player1.SetPositionForLAN(positionX, positionY);						//wczytuje pozycje przeciwnika
				player1.SetMovingSate(direction);

				// tymczasowe plantowanie bomby
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
			Update(time);
			Draw();
			window.display();
		}
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

void Game::ListenTCP(sf::TcpSocket & socket)
{
	while (!gotConnection)
	{
		sf::TcpListener listener;
		listener.listen(53000);
		listener.accept(socket);	
	}
}
