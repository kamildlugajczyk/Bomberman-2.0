#include <iostream>
#include <SFML/Graphics.hpp>

#include "end_game_screen.hpp"

void EndGameScreen::Draw(sf::RenderWindow & window)
{
	window.draw(mainText);
	window.draw(subText1);
	window.draw(subText2);
}

void EndGameScreen::DisplayPlayer1Win(bool player1win)
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

	subText1.setString("Press R to play again");
	subText2.setString("Press ESC to exit");
}

void EndGameScreen::LoadFont(const sf::Font & font)
{
	mainText.setFont(font);
	subText1.setFont(font);
	subText2.setFont(font);
}
