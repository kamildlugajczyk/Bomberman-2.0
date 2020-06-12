#pragma once

#include <iostream>
#include <sstream>
#include <regex>
#include <SFML/Graphics.hpp>

#include "main_menu.hpp"

#define DELETE_KEY 8
#define ENTER_KEY 13

class Textbox
{
public:
	sf::Text textbox;				
	std::ostringstream text;

	bool isSelected = false;
	int limit = 0;

	/* Konstruktor bezargumentowy pola tesktowego */
	Textbox();

	/* Metoda usuwajaca ostatni wpisany znak w pole tekstowe */
	void deleteLastChar();

	/* Metoda odpowiedzialna za mechanike wpisywania adresu IP 
	w pole tekstowe. */
	void inputLogic(int charTyped);

	/* Metoda odpowiedzialna dopisane w ostatnie pole znaku '_'
	jesli uzytkownik chce wpisac adres IP */
	void SetSelected(bool sel);

	/* Metoda rysujaca pole tekstowe */
	void Draw(sf::RenderWindow &window);

	/* Metoda wczytujaca czcionke do uzywana w polu tekstowym */
	void LoadFont(const sf::Font & font);

	/* Metoda dokonujaca sprawdzenia poprawnosci wpisanego 
	adresu IP poprzez uzycie wyrazen regularnych (RegEx) */
	bool isIPValid(std::string ip);
};
