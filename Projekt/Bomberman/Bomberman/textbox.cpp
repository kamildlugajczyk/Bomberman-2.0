#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

#include "textbox.hpp"

Textbox::Textbox()
	: isSelected(false), limit(100)
{
	textbox.setPosition(350, 300);
	textbox.setCharacterSize(80);

	if (isSelected)
		textbox.setString("_");
	else
		textbox.setString("");
}

void Textbox::SetSelected(bool sel)
{
	isSelected = sel;

	if (!sel) 
	{
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length(); i++) 
		{
			newT += t[i];
		}
		textbox.setString(newT);
	}
}

std::string Textbox::GetText()
{
	return text.str();
}

void Textbox::Draw(sf::RenderWindow & window)
{
	sf::Font font;
	if (!font.loadFromFile("res/fonts/SFPixelate.ttf"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
		return;
	}
	else
		this->LoadFont(font);

	window.draw(textbox);
}

void Textbox::LoadFont(const sf::Font & font)
{
	textbox.setFont(font);
}

void Textbox::deleteLastChar()
{
	std::string t = text.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++) 
	{
		newT += t[i];
	}
	text.str("");
	text << newT;
	textbox.setString(text.str() + "_");
}

void Textbox::inputLogic(int charTyped)
{
	// If the key pressed isn't delete, or the two selection keys, then append the text with the char:
	if (charTyped != DELETE_KEY /*&& charTyped != ENTER_KEY && charTyped != ESCAPE_KEY*/) 
	{
		text << static_cast<char>(charTyped);
	}
	// If the key is delete, then delete the char:
	else if (charTyped == DELETE_KEY) 
	{
		if (text.str().length() > 0) 
		{
			deleteLastChar();
		}
	}
	// Set the textbox text:
	textbox.setString(text.str() + "_");
}
