#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.hpp"

#define OPTION_AMOUNT_MAIN 5
#define FONT_SIZE 35
#define X_POS 350
#define Y_POS_BASE 250

class MainMenu
{
	sf::Text menuOptions[OPTION_AMOUNT_MAIN];
	sf::Text logo;
	sf::Text indicator;

	int selectedItemIndex;
public:

	MainMenu();

	void Draw(sf::RenderWindow & window);

	void LoadFont(const sf::Font & font);

	void MoveUp(sf::RenderWindow & window);

	void MoveDown(sf::RenderWindow & window);

	int GetPressedItem() { return selectedItemIndex; }

	void ShowMenu(sf::RenderWindow & window, bool & selectedLan);
};