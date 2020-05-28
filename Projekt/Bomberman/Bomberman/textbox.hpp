#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

// Define keys:
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox {
public:
	Textbox();

	void SetSelected(bool sel);

	std::string GetText();

	void Draw(sf::RenderWindow &window);

	void LoadFont(const sf::Font & font);


private:
	sf::Text textbox;
	std::ostringstream text;

	bool isSelected = false;
	int limit = 0;

	void deleteLastChar();

	void inputLogic(int charTyped);

	friend class LanMenu;
};