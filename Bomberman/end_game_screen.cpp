#include <iostream>
#include <SFML/Graphics.hpp>

#include "end_game_screen.hpp"

void EndGameScreen::Draw(sf::RenderWindow & window)
{
	window.draw(mainText);
	window.draw(subText1);
	window.draw(subText2);
}

void EndGameScreen::DisplayPlayer1Win(bool player1win, bool host)
{
	mainText.setPosition(270, 200);
	mainText.setCharacterSize(50);

	subText1.setPosition(270, 400);
	subText1.setCharacterSize(25);

	subText2.setPosition(270, 450);
	subText2.setCharacterSize(25);

	if(player1win)
		mainText.setString("Player 1 wins!");
	else
		mainText.setString("Player 2 wins!");

	if (host)
	{
		subText1.setString("Press R to play again");
		subText2.setString("Press ESC to go to main menu");
	}
	else
	{
		subText1.setString("Wait for host's decision...");
	}
}

void EndGameScreen::LoadFont()
{
	if (!font.loadFromFile("res/fonts/SFPixelate.ttf"))
	{
		throw std::runtime_error("Can't open the file: SFPixelate.ttf");
	}
		
	mainText.setFont(font);
	subText1.setFont(font);
	subText2.setFont(font);
}
