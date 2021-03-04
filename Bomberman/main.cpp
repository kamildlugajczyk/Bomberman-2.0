#include <iostream>
#include <stdio.h>
#include <thread>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <windows.h>

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

	try
	{
		menu.LoadFont();
	}
	catch (std::runtime_error & exception)
	{
		std::string message;
		message = exception.what() + (std::string)". Program will abort.";
		MessageBoxA(NULL, (LPCSTR)message.c_str(), "Exception", MB_ICONSTOP);
		return 0;
	}

	while (window.isOpen())
	{
		window.clear(sf::Color(42, 42, 42));

		if (!selectedLan)
		{
			menu.ShowMenu(window, selectedLan);
			menu.Draw(window);
		}
		else
		{
			lanMenu.ShowMenu(window, selectedLan);
			lanMenu.Draw(window);
		}
		window.display();
	}


	return 0;
}