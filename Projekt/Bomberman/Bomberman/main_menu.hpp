#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.hpp"

#define OPTION_AMOUNT_MAIN 3
#define FONT_SIZE 35
#define X_POS 350
#define Y_POS_BASE 250

class MainMenu
{
	sf::Font font;
	sf::Text menuOptions[OPTION_AMOUNT_MAIN];
	sf::Text logo;
	sf::Text indicator;

	int selectedItemIndex;
public:

	/* Konstruktor bezargumentowy menu gry */
	MainMenu();

	/* Metoda rysujaca wszystkie elementy menu */
	void Draw(sf::RenderWindow & window);

	/* Metoda odpowiedzialna za poruszanie sie po menu w gore
	(po wcisnieciu strzalki w gore) */
	void MoveUp(sf::RenderWindow & window);

	/* Metoda odpowiedzialna za poruszanie sie po menu w dol
	(po wcisnieciu strzalki w dol) */
	void MoveDown(sf::RenderWindow & window);

	/* Metoda zwracajaca selectedItemIndex, czyli wybrana opcje menu */
	int GetPressedItem() { return selectedItemIndex; }

	/* Metoda wyswietlajaca cale pod menu, zawiera mozliwosc wyoru
	przez uzytkownika wybranej opcji */
	void ShowMenu(sf::RenderWindow & window, bool & selectedLan);

	/* Metoda odpowiedzialna na wczytanie czcionki uzywanej w menu */
	void LoadFont();
};