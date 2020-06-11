#include <iostream>
#include <SFML/Graphics.hpp>

#include "main_menu.hpp"
#include "lan_menu.hpp"

MainMenu::MainMenu()
	: selectedItemIndex(0) 
{
	indicator.setPosition(310, 250);
}

void MainMenu::Draw(sf::RenderWindow & window)
{
	logo.setString("BOMBERMAN");
	logo.setPosition(220, 100);
	logo.setCharacterSize(80);

	menuOptions[0].setString("Local");
	menuOptions[0].setPosition(X_POS, Y_POS_BASE);
	menuOptions[0].setCharacterSize(FONT_SIZE);

	menuOptions[1].setString("LAN");
	menuOptions[1].setPosition(X_POS, Y_POS_BASE + 50);
	menuOptions[1].setCharacterSize(FONT_SIZE);

	menuOptions[2].setString("Exit");
	menuOptions[2].setPosition(X_POS, Y_POS_BASE + 150);
	menuOptions[2].setCharacterSize(FONT_SIZE);

	indicator.setString(">");
	indicator.setCharacterSize(FONT_SIZE);

	window.draw(logo);
	for (int i = 0; i < OPTION_AMOUNT_MAIN; i++)
	{
		window.draw(menuOptions[i]);
	}
	window.draw(indicator);
}

void MainMenu::LoadFont(const sf::Font & font)
{
	logo.setFont(font);
	for (int i = 0; i < OPTION_AMOUNT_MAIN + 2; i++)
	{
		menuOptions[i].setFont(font);
	}
	indicator.setFont(font);
}

void MainMenu::MoveUp(sf::RenderWindow & window)
{
	if (selectedItemIndex - 1 >= 0)
	{
		indicator.setPosition(menuOptions[selectedItemIndex - 1].getPosition().x - 40, menuOptions[selectedItemIndex - 1].getPosition().y);
		selectedItemIndex--;
	}
}

void MainMenu::MoveDown(sf::RenderWindow & window)
{
	if (selectedItemIndex + 1 < OPTION_AMOUNT_MAIN)
	{
		indicator.setPosition(menuOptions[selectedItemIndex + 1].getPosition().x - 40, menuOptions[selectedItemIndex + 1].getPosition().y);
		selectedItemIndex++;
	}
}

void MainMenu::ShowMenu(sf::RenderWindow & window, bool & selectedLan)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				this->MoveUp(window);
				break;

			case sf::Keyboard::Down:
				this->MoveDown(window);
				break;

			case sf::Keyboard::Return:
				switch (this->GetPressedItem())
				{
				case 0:
				{
					Game game{};
					game.Play(window);
					break;
				}
				case 1:
				{
					selectedLan = true;
					break;
				}
				case 2:
					window.close();
					break;
				}
				break;
			}
			break;
		case sf::Event::Closed:
			window.close();
			break;
		}
	}
}

void MainMenu::LoadFont()
{
	if (!font.loadFromFile("res/fonts/SFPixelate.ttf"))
	{
		throw std::runtime_error("Can't open the file: SFPixelate.ttf");
	}
	else
		this->LoadFont(font);
}
