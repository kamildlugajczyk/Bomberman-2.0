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

	bool selectedLan = false;

	windowSize.x = 960;
	windowSize.y = 700;
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "Bomberman");
	window.setFramerateLimit(60);
	window.clear(sf::Color(42, 42, 42));

	
	MainMenu menu{};
	LanMenu lanMenu{};
	//Textbox text1{};
	//Game game{};

	while (window.isOpen())
	{
		if (!selectedLan)
		{
			menu.ShowMenu(window, selectedLan);
			window.clear(sf::Color(42, 42, 42));
			menu.Draw(window);
		}
		else
		{
			lanMenu.ShowMenu(window, selectedLan);
			window.clear(sf::Color(42, 42, 42));
			lanMenu.Draw(window);
		}

		window.display();
	}

	
	


	return 0;
}