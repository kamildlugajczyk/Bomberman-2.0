#pragma once

#include <iostream>
#include <sstream>
#include <regex>
#include <SFML/Graphics.hpp>

#include "main_menu.hpp"

#define DELETE_KEY 8
#define ENTER_KEY 13

class Textbox
{


public:
	sf::Text textbox;
	std::ostringstream text;

	bool isSelected = false;
	int limit = 0;

	void deleteLastChar();

	void inputLogic(int charTyped);
	//----------------------
	Textbox();

	void SetSelected(bool sel);

	void Draw(sf::RenderWindow &window);

	void LoadFont(const sf::Font & font);

	bool isIPValid(std::string ip);
};
