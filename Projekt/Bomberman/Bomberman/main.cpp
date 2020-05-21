#include <iostream>
#include <stdio.h>

#include <thread>
#include <chrono>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "game.hpp"
#include "main_menu.hpp"
#include "lan_menu.hpp"

int main()
{
	sf::RenderWindow window;										// okno gry
	sf::Vector2f windowSize;										// rozmiar okna gry

	windowSize.x = 960;
	windowSize.y = 700;
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "Bomberman");
	window.setFramerateLimit(60);
	window.clear(sf::Color(42, 42, 42));


	
	LanMenu lanMenu{};
	MainMenu menu{};

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp(window);
					break;

				case sf::Keyboard::Down:
					menu.MoveDown(window);
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear(sf::Color(42, 42, 42));

		menu.Draw(window);

		window.display();
	}

	/*Game game;
	game.Play(window);*/
	/*Game newGame{};
	newGame.PlayLAN();*/

	std::getchar();
	return 0;
}