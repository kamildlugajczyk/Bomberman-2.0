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

	logo.setString("BOMBERMAN");
	logo.setPosition(220, 100);
	logo.setCharacterSize(80);
	//menuOptions[0].setOutlineColor(sf::Color::Red);
	//menuOptions[0].setOutlineThickness(3.0);

	menuOptions[0].setString("Local");
	menuOptions[0].setPosition(X_POS, Y_POS_BASE);
	menuOptions[0].setCharacterSize(FONT_SIZE);

	menuOptions[1].setString("LAN");
	menuOptions[1].setPosition(X_POS, Y_POS_BASE + 50);
	menuOptions[1].setCharacterSize(FONT_SIZE);

	menuOptions[2].setString("Statistics");
	menuOptions[2].setPosition(X_POS, Y_POS_BASE + 100);
	menuOptions[2].setCharacterSize(FONT_SIZE);

	menuOptions[3].setString("Map Select");
	menuOptions[3].setPosition(X_POS, Y_POS_BASE + 150);
	menuOptions[3].setCharacterSize(FONT_SIZE);

	menuOptions[4].setString("Exit");
	menuOptions[4].setPosition(X_POS, Y_POS_BASE + 200);
	menuOptions[4].setCharacterSize(FONT_SIZE);

	indicator.setString(">");
	indicator.setPosition(X_POS - 40, Y_POS_BASE);
	indicator.setCharacterSize(FONT_SIZE);

	window.draw(logo);
	for (int i = 0; i < OPTION_AMOUNT; i++)
	{
		window.draw(menuOptions[i]);
	}
	window.draw(indicator);
}

void MainMenu::LoadFont(const sf::Font & font)
{
	logo.setFont(font);
	for (int i = 0; i < OPTION_AMOUNT + 2; i++)
	{
		menuOptions[i].setFont(font);
	}
	indicator.setFont(font);
}

void MainMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		indicator.setPosition(menuOptions[selectedItemIndex].getPosition().x - 40, menuOptions[selectedItemIndex].getPosition().y);
		selectedItemIndex--;
	}
}

void MainMenu::MoveDown()
{
	if (selectedItemIndex + 1 < OPTION_AMOUNT)
	{
		indicator.setPosition(menuOptions[selectedItemIndex].getPosition().x - 40, menuOptions[selectedItemIndex].getPosition().y);
		selectedItemIndex++;
	}
}
