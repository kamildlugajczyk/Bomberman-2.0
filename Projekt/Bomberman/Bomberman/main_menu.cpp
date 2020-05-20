#include <iostream>
#include <SFML/Graphics.hpp>

#include "main_menu.hpp"

MainMenu::MainMenu()
{

}

void MainMenu::Draw(sf::RenderWindow & window)
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

	menuOptions[0].setString("BOMBERMAN");
	menuOptions[0].setPosition(220, 100);
	menuOptions[0].setCharacterSize(80);
	//menuOptions[0].setOutlineColor(sf::Color::Red);
	//menuOptions[0].setOutlineThickness(3.0);

	menuOptions[1].setString("Local");
	menuOptions[1].setPosition(X_POS, Y_POS_BASE);
	menuOptions[1].setCharacterSize(FONT_SIZE);

	menuOptions[2].setString("LAN");
	menuOptions[2].setPosition(X_POS, Y_POS_BASE + 50);
	menuOptions[2].setCharacterSize(FONT_SIZE);

	menuOptions[3].setString("Statistics");
	menuOptions[3].setPosition(X_POS, Y_POS_BASE + 100);
	menuOptions[3].setCharacterSize(FONT_SIZE);

	menuOptions[4].setString("Map Select");
	menuOptions[4].setPosition(X_POS, Y_POS_BASE + 150);
	menuOptions[4].setCharacterSize(FONT_SIZE);

	menuOptions[5].setString("Exit");
	menuOptions[5].setPosition(X_POS, Y_POS_BASE + 200);
	menuOptions[5].setCharacterSize(FONT_SIZE);

	menuOptions[6].setString(">");
	menuOptions[6].setPosition(X_POS - 40, Y_POS_BASE);
	menuOptions[6].setCharacterSize(FONT_SIZE);

	for (int i = 0; i < OPTION_AMOUNT + 2; i++)
	{
		window.draw(menuOptions[i]);
	}
}

void MainMenu::LoadFont(const sf::Font & font)
{
	for (int i = 0; i < OPTION_AMOUNT + 2; i++)
	{
		menuOptions[i].setFont(font);
	}
}

void MainMenu::MoveUp()
{
	
}

void MainMenu::MoveDown()
{

}
