#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


class MainMenu
{
	sf::Text menuOptions[5];

public:
	MainMenu();

	void Draw(sf::RenderWindow & window);

	void LoadFont(const sf::Font & font);
};