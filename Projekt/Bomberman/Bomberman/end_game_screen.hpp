#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class EndGameScreen
{
	sf::Text mainText;									// tekst glowny wyswietlany u gory
	sf::Text subText1;									// pierwszy tekst dodatkowy wyswietlany pod mainText
	sf::Text subText2;									// drugi tekst dodatkowy wyswietlany pod mainText

public:

	/* Metoda rysujaca mainText oraz subText
	@param window okno gry */
	void Draw(sf::RenderWindow & window);

	/* Metoda wywietlajaca informacje o wygranej ktoregos z graczy
	@param player1win true gdy wygral gracz 1, false gdy wygral gracz 2*/
	void DisplayPlayer1Win(bool player1win, bool host);

	/* Metoda wczytujaca czcionke podana w parametrze
	@param font wybrana czcionka */
	void LoadFont(const sf::Font & font);
};