#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "main_menu.hpp"
#include "textbox.hpp"

#define OPTION_AMOUNT_LAN 3

class LanMenu : public MainMenu
{
	sf::Text menuOptions[OPTION_AMOUNT_LAN];
	sf::Text logo;
	sf::Text indicator;


	int selectedItemIndex;

public:

	LanMenu();

	void Draw(sf::RenderWindow & window);

	void LoadFont(const sf::Font & font);

	void MoveUp(sf::RenderWindow & window);

	void MoveDown(sf::RenderWindow & window);

	int GetPressedItem() { return selectedItemIndex; }

	void ShowMenu(sf::RenderWindow & window, bool & selectedLan);
};