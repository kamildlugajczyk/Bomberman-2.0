#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "block.hpp"

class Map
{
	unsigned int gameMap[11][15];						// dwuwymiarowa tablica intow reprezentujacych odpowiednie bloki

public:
	int tileSize;										// standardowy rozmiar kafelka
	Block * blocks[11][15];								// dwuwymiarowa tablica obiektow typu blok zawierajaca wszystkie obiekty na mapie

	/* Konstruktor bezargumentowy ustawiajacy domyslny rozmiar kafelka na 64 */
	Map();			

	/* Destruktor dealokujacy pamiec z tablicy blocks[][] */
	~Map();

	/* Metoda wczytujaca typ bloku z tablicy gameMap[][] i towrzaca
	odpowiednie obiekty ktore zostaja zapisane w tablicy blocks[][] */
	void LoadTiles();

	/* Metoda sprawdzajaca czy bomba zostala zdetonowana, jesli
	tak to tworzy eksplozje w ksztalcie + (jesli to niemozliwe, jesli
	nie to pomija niedostepnie miejsca) 
	@param deltaTime czas od ostatniej iteracji */
	void Update(const sf::Time deltaTime);

	/* Metoda wywolujaca metode Draw() dla kazdego obiektu znajdujacego
	sie w tablicy blocks[][]
	@param window okno gry */
	void Draw(sf::RenderWindow & window);

	/* Metoda wczytujaca z pliku tesktowego "map.txt" uklad blokow
	i zapisuje do tablicy gameMap[][] */
	void LoadFromFile();
};