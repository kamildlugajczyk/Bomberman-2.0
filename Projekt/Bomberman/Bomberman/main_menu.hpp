#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


class MainMenu
{
	sf::Text menuOptions[7];

public:
	MainMenu(sf::RenderWindow & window);

	void Draw(sf::RenderWindow & window);

	void LoadFont(const sf::Font & font);

	void MoveUp();

	void MoveDown();
};