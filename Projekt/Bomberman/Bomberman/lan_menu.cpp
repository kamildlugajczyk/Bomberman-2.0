#include <iostream>
#include <SFML/Graphics.hpp>

#include "lan_menu.hpp"
#include "textbox.hpp"


LanMenu::LanMenu()
	: selectedItemIndex(0)
{
	indicator.setPosition(310, 250);
}

void LanMenu::Draw(sf::RenderWindow & window)
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

	logo.setString("LAN");
	logo.setPosition(370, 100);
	logo.setCharacterSize(80);

	menuOptions[0].setString("Host game");
	menuOptions[0].setPosition(X_POS, Y_POS_BASE);
	menuOptions[0].setCharacterSize(FONT_SIZE);

	menuOptions[1].setString("Join game");
	menuOptions[1].setPosition(X_POS, Y_POS_BASE + 50);
	menuOptions[1].setCharacterSize(FONT_SIZE);

	menuOptions[2].setString("IP: ");
	menuOptions[2].setPosition(X_POS + 40, Y_POS_BASE + 100);
	menuOptions[2].setCharacterSize(FONT_SIZE);

	menuOptions[3].setString("Back");
	menuOptions[3].setPosition(X_POS, Y_POS_BASE + 150);
	menuOptions[3].setCharacterSize(FONT_SIZE);

	indicator.setString(">");
	indicator.setCharacterSize(FONT_SIZE);

	warning.setString("Enter valid IP adress!");
	warning.setPosition(X_POS - 100, Y_POS_BASE + 300);
	warning.setCharacterSize(FONT_SIZE);

	tip.setString("Tip: to stop hosting game press ESC");
	tip.setPosition(X_POS - 135, Y_POS_BASE + 350);
	tip.setCharacterSize(FONT_SIZE - 10);

	window.draw(logo);
	for (int i = 0; i < OPTION_AMOUNT_LAN; i++)
	{
		window.draw(menuOptions[i]);
	}
	window.draw(indicator);
	box.Draw(window);
	window.draw(tip);


	if (wrongIP)
		window.draw(warning);
}

void LanMenu::LoadFont(const sf::Font & font)
{
	logo.setFont(font);
	for (int i = 0; i < OPTION_AMOUNT_LAN; i++)
	{
		menuOptions[i].setFont(font);
	}
	indicator.setFont(font);
	warning.setFont(font);
	tip.setFont(font);
}

void LanMenu::MoveUp(sf::RenderWindow & window)
{
	if (selectedItemIndex - 1 >= 0)
	{
		indicator.setPosition(menuOptions[selectedItemIndex - 1].getPosition().x - 40, menuOptions[selectedItemIndex - 1].getPosition().y);
		selectedItemIndex--;
	}
}

void LanMenu::MoveDown(sf::RenderWindow & window)
{
	if (selectedItemIndex + 1 < OPTION_AMOUNT_LAN)
	{
		indicator.setPosition(menuOptions[selectedItemIndex + 1].getPosition().x - 40, menuOptions[selectedItemIndex + 1].getPosition().y);
		selectedItemIndex++;
	}
}

void LanMenu::ShowMenu(sf::RenderWindow & window, bool & selectedLan)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::TextEntered:
			{
				if (box.isSelected)
				{
					int charTyped = event.text.unicode;

					if ((charTyped >= 48 && charTyped <= 57) || charTyped == 46 || charTyped == DELETE_KEY || charTyped == ENTER_KEY )
					{
						if (box.text.str().length() <= box.limit)
						{
							box.inputLogic(charTyped);
						}
						else if (box.text.str().length() > box.limit && charTyped == DELETE_KEY)
						{
							box.deleteLastChar();
						}
					}
				}
			}
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					box.SetSelected(false);
					this->MoveUp(window);
					break;

				case sf::Keyboard::Down:
					box.SetSelected(false);
					this->MoveDown(window);
					break;
				case sf::Keyboard::Return:
					switch (this->GetPressedItem())
					{
					case 0:
					{
						Game game{};
						game.PlayLAN(window);				// as server
						break;
					}
					case 1:
					{
						std::string ip = box.text.str();

						for (int i = 0; i < ip.length(); i++)
						{
							if (ip[0] == '\r')
								ip.erase(ip.begin());				// usuniecie '\r' z pierwszego miejsca ip jako pozostalosc po ostreamstring.str()
							else
								break;
						}
						if (box.isIPValid(ip))
						{
							Game game{};
							game.PlayLAN(window, ip);		// as client
						}
						else
							wrongIP = true;

						break;
					}
					case 2:
					{
						wrongIP = false;
						box.SetSelected(true);
						break;
					}
					case 3:
					{
						selectedLan = false;
						wrongIP = false;
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
}
