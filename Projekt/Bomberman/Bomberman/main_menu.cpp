#include <iostream>
#include <SFML/Graphics.hpp>

#include "main_menu.hpp"

MainMenu::MainMenu()
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

	menuOptions[0].setString("Local");
	menuOptions[0].setPosition(270, 200);
	menuOptions[0].setCharacterSize(25);


	menuOptions[1].setString("LAN");
	menuOptions[1].setPosition(270, 250);
	menuOptions[1].setCharacterSize(25);

	menuOptions[2].setString("Statistics");
	menuOptions[2].setPosition(270, 300);
	menuOptions[2].setCharacterSize(25);

	menuOptions[3].setString("Map Select");
	menuOptions[3].setPosition(270, 350);
	menuOptions[3].setCharacterSize(25);

	menuOptions[4].setString("Exit");
	menuOptions[4].setPosition(270, 400);
	menuOptions[4].setCharacterSize(25);

}

void MainMenu::Draw(sf::RenderWindow & window)
{
	window.draw(menuOptions[0]);
	window.draw(menuOptions[1]);
	window.draw(menuOptions[2]);
	window.draw(menuOptions[3]);
	window.draw(menuOptions[4]);

	/*for (auto element : menuOptions)
	{
		window.draw(element);
	}*/
}

void MainMenu::LoadFont(const sf::Font & font)
{
	menuOptions[0].setFont(font);
	menuOptions[1].setFont(font);
	menuOptions[2].setFont(font);
	menuOptions[3].setFont(font);
	menuOptions[4].setFont(font);

	/*for (auto element : menuOptions)
	{
		element.setFont(font);
	}*/
}
