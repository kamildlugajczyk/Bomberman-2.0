#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "main_menu.hpp"

#define OPTION_AMOUNT 3

class LanMenu : public MainMenu
{
	sf::Text menuOptions[5];

public:

	LanMenu();

	void Draw(sf::RenderWindow & window);

	void LoadFont(const sf::Font & font);

};