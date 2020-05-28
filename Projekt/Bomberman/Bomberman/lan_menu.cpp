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

	logo.setString("LAN");
	logo.setPosition(280, 100);
	logo.setCharacterSize(80);
	//menuOptions[0].setOutlineColor(sf::Color::Red);
	//menuOptions[0].setOutlineThickness(3.0);

	menuOptions[0].setString("Host game");
	menuOptions[0].setPosition(X_POS, Y_POS_BASE);
	menuOptions[0].setCharacterSize(FONT_SIZE);

	menuOptions[1].setString("Join game");
	menuOptions[1].setPosition(X_POS, Y_POS_BASE + 50);
	menuOptions[1].setCharacterSize(FONT_SIZE);

	menuOptions[2].setString("IP: ");
	menuOptions[2].setPosition(X_POS + 40, Y_POS_BASE + 100);
	menuOptions[2].setCharacterSize(FONT_SIZE);

	box.textbox.setPosition(X_POS + 100, Y_POS_BASE + 100);
	box.textbox.setCharacterSize(FONT_SIZE);
	//box.textbox.setString("192.168.1.1");

	menuOptions[3].setString("Back");
	menuOptions[3].setPosition(X_POS, Y_POS_BASE + 150);
	menuOptions[3].setCharacterSize(FONT_SIZE);

	indicator.setString(">");
	indicator.setCharacterSize(FONT_SIZE);

	//playerText.setPosition(X_POS, Y_POS_BASE + 100);
	//playerText.setCharacterSize(FONT_SIZE);

	window.draw(logo);
	for (int i = 0; i < OPTION_AMOUNT_LAN; i++)
	{
		window.draw(menuOptions[i]);
	}
	window.draw(indicator);
	box.Draw(window);
	
}

void LanMenu::LoadFont(const sf::Font & font)
{
	logo.setFont(font);
	for (int i = 0; i < OPTION_AMOUNT_LAN; i++)
	{
		menuOptions[i].setFont(font);
	}
	indicator.setFont(font);
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
		//case sf::Event::KeyReleased:
		//	switch (event.key.code)
		//	{
		//	case sf::Keyboard::Up:
		//		this->MoveUp(window);
		//		break;

		//	case sf::Keyboard::Down:
		//		this->MoveDown(window);
		//		break;
		//	case sf::Keyboard::Return:
		//		switch (this->GetPressedItem())
		//		{
		//		case 0:
		//		{
		//			//box.SetSelected(false);

		//			Game game{};
		//			game.PlayLAN(window, true);			// as server
		//			break;
		//		}
		//		case 1:
		//		{
		//			//box.SetSelected(false);

		//			Game game{};
		//			game.PlayLAN(window, false);			// as client
		//			break;
		//		}
		//		case 2:
		//		{
		//				box.SetSelected(true);
		//			
		//			break;
		//		}
		//		case 3:
		//		{
		//			//box.SetSelected(false);

		//			selectedLan = false;
		//			break;
		//		}
		//		break;
		//		}
		//		break;
		//	case sf::Event::Closed:
		//		window.close();
		//		break;
		//	}
		case sf::Event::TextEntered:
			/*if (box.isSelected)
			{*/
				int charTyped = event.text.unicode;

				if (charTyped < 128)
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
			//}
			break;
		}
	}
}
