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

	int i = 0;
	bool choice[16] = {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false};

	while (true)
	{
		window.clear(sf::Color(42, 42, 42));

		if (choice[i] == true)
		{
			MainMenu menu{};
			menu.Draw(window);
		}
		else
		{
			LanMenu lan{ };
			lan.Draw(window);
		}

		i++;
		window.display();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	

	

	/*Game game;
	game.Play(window);*/
	/*Game newGame{};
	newGame.PlayLAN();*/

	std::getchar();
	return 0;
}