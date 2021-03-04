#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "main_menu.hpp"
#include "textbox.hpp"

#define OPTION_AMOUNT_LAN 4

class LanMenu : public MainMenu
{
	sf::Text menuOptions[OPTION_AMOUNT_LAN];		// tablica opcji menu jako tekst
	sf::Text logo;									// tekst logo
	sf::Text indicator;								// tekst znaku '>'
	sf::Text warning;								// tekst ostrzezenia o niepoprawnym adresie IP
	sf::Text tip;									// tekst podpowiedzi
	Textbox box;									// pole tekstowe do wpisywania IP

	int selectedItemIndex;							// aktualnie wybrana opcja
	bool wrongIP = false;						

public:
	/* Konstruktor bezargumentowy pod menu do gry sieciowej */
	LanMenu();

	/* Metoda rysujaca wszystkie elementy menu */
	void Draw(sf::RenderWindow & window);

	/* Metoda odpowiedzialna na wczytanie czcionki uzywanej
	w pod menu gry sieciowej */
	void LoadFont(const sf::Font & font);

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
};