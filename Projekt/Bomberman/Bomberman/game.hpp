#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>


#include "player.hpp"
#include "map.hpp"
#include "end_game_screen.hpp"

class Game
{
	Player player1{"Player 1"};										// gracz 1
	Player player2{"Player 2"};										// gracz 2
	Map map;														// mapa gry
	EndGameScreen endGameScreen;									// widok konca gry
	sf::Font font;													// czcionka
	bool isOver;													// zmienna informujaca czy gra sie skonczyla
	bool once = true;												// zmienna pomocniczna

public:
	/* Konstruktor bezargumentowy ustawiajacy szerokosc i wysokosc okna gry,
	tworzy okno gry, ustawia limit klatek na sekunde, ustawia pozycje obu
	graczy, ustawia zmienna isOver na false */
	Game();

	/* Metoda wywolujaca kolejne metody tj. update dla mapy oraz
	dla obu graczy 
	@param deltaTime czas od ostatniej iteracji */
	void Update(const sf::Time deltaTime);

	/* Metoda wywolujaca kolejne metody tj. draw dla mapy oraz
	dla obu graczy oraz jesli gra sie skonczyla to draw dla
	widoku konca gry */
	void Draw(sf::RenderWindow & window);

	/* Glowna metoda zawieraja cala logike gry w ktorej wywolywane
	sa kolejne metody, zawiera glowna petle gry */
	void Play(sf::RenderWindow & window);

	void PlayLAN(sf::RenderWindow & window);

	/* Metoda przywracajaca stan gry do warunkow poczatkowych
	(pozycje obu graczy, ponowne wczytanie planszy, wyzerowanie
	licznika podstawionych bomb oraz ustawienie atrybutu killed
	obu graczy na false */
	void PlayAgain();

	void ListenTCP(sf::TcpSocket & socket);
};