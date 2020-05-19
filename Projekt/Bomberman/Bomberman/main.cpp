#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "game.hpp"
#include "main_menu.hpp"

int main()
{
	sf::RenderWindow window;										// okno gry
	sf::Vector2f windowSize;										// rozmiar okna gry

	windowSize.x = 960;
	windowSize.y = 700;
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "Bomberman");
	window.setFramerateLimit(60);
	window.clear(sf::Color::Black);

	MainMenu menu(window);
	window.display();

	/*Game game;
	game.Play(window);*/

	

	/*Game newGame{};
	newGame.PlayLAN();*/
	std::getchar();
	return 0;
}