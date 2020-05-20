#include <iostream>
#include <SFML/Graphics.hpp>

#include "lan_menu.hpp"


LanMenu::LanMenu()
{
}

void LanMenu::Draw(sf::RenderWindow & window)
{
	// to przemyslec
	sf::Font font;
	if (!font.loadFromFile("res/fonts/SFPixelate.ttf"))
	{
		std::cout << "Load failed! " << std::endl;
		getchar();
		return;
	}
	else
		this->LoadFont(font);

	menuOptions[0].setString("LAN");
	menuOptions[0].setPosition(280, 100);
	menuOptions[0].setCharacterSize(80);
	//menuOptions[0].setOutlineColor(sf::Color::Red);
	//menuOptions[0].setOutlineThickness(3.0);

	menuOptions[1].setString("Host game");
	menuOptions[1].setPosition(X_POS, Y_POS_BASE);
	menuOptions[1].setCharacterSize(FONT_SIZE);

	menuOptions[2].setString("Join game");
	menuOptions[2].setPosition(X_POS, Y_POS_BASE + 50);
	menuOptions[2].setCharacterSize(FONT_SIZE);

	menuOptions[3].setString("Back");
	menuOptions[3].setPosition(X_POS, Y_POS_BASE + 100);
	menuOptions[3].setCharacterSize(FONT_SIZE);

	menuOptions[4].setString(">");
	menuOptions[4].setPosition(X_POS - 40, Y_POS_BASE);
	menuOptions[4].setCharacterSize(FONT_SIZE);

	for (int i = 0; i < OPTION_AMOUNT + 2; i++)
	{
		window.draw(menuOptions[i]);
	}
}

void LanMenu::LoadFont(const sf::Font & font)
{
	for (int i = 0; i < OPTION_AMOUNT + 2; i++)
	{
		menuOptions[i].setFont(font);
	}
}
