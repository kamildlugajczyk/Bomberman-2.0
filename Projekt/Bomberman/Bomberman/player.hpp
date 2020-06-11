#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

#include "graphic_object.hpp"
#include "enum.hpp"
#include "bomb.hpp"
#include "map.hpp"
#include "templates.hpp"

static bool isOtherPlayerKilled = false;
static bool direction = 1;

class Player : public GraphicObject
{
	sf::Vector2f velocity;										// predkosc gracza
	sf::Vector2f defaultVelocity;								// domyslna predkosc gracza
	States playerState;											// aktualny stan poruszania sie gracza
	std::string name;											// nazwa gracza
	bool canGoUp, canGoDown, canGoLeft, canGoRight;				// wartosci informujace o mozliwosci poruszania sie w danym kierunku
	float timeSinceBomb, bombCooldown;							// czas od postawienia ostatniej bomby | czas po ktorym mozna postawic kolejna bombe
	sf::Vector2f bombLocation;

public:
	sf::Texture texture_p1, texture_p2;							// tekstrura gracza 1 | tekstura gracza 2
	int bombPlaced;												// licznik postawioncyh bomb podczas calej rozgrywki
	bool killed = false;										// zmienna inforumjaca czy gracz zginal
	
	/* Konstruktor jedno argumentowy ustawiajacy nazwe gracza oraz domyslna 
	wartosc bombCoolDown, defaultVelocity, playerState, bombPlaced, wysokosc
	i szerokosc obszaru kolizyjnego oraz ustawiajacy sprite.Origin() czyli
	srodek testrury wzgledem ktorej jest odbijana 
	@param name nazwa gracza */
	Player(std::string name);

	/* Metoda sprawdzajaca ktory klawisz na klawiaturze (W, S, A, D)
	jest wcisniety i zgodnie z tym wybierajaca kierunek poruszania 
	postaci badz postawienie bomby 
	@param deltaTime czas od poprzedniej iteracji
	@param map mapa rozgrywki */
	void MoveWSAD(const sf::Time & deltaTime, Map & map);

	/* Metoda sprawdzajaca ktora strzalka na klawiaturze (gpra, dol, lewo, prawo)
	jest wcisniety i zgodnie z tym wybierajaca kierunek poruszania
	postaci badz postawienie bomby 
	@param deltaTime czas od poprzedniej iteracji
	@param map mapa rozgrywki */
	void MoveArrows(const sf::Time & deltaTime, Map & map);

	/* Metoda zmieniajaca pozycje gracza na osi Y w gore
	oraz zmieniajaca movingState 
	@param deltaTime czas od poprzedniej iteracji
	@param map mapa rozgrywki*/
	void GoUp(const sf::Time & deltaTime, Map & map);

	/* Metoda zmieniajaca pozycje gracza na osi Y w dol
	oraz zmieniajaca movingState 
	@param deltaTime czas od poprzedniej iteracji
	@param map mapa rozgrywki*/
	void GoDown(const sf::Time & deltaTime, Map & map);

	/* Metoda zmieniajaca pozycje gracza na osi X w lewo
	oraz zmieniajaca movingState 
	@param deltaTime czas od poprzedniej iteracji
	@param map mapa rozgrywki*/
	void GoLeft(const sf::Time & deltaTime, Map & map);

	/* Metoda zmieniajaca pozycje gracza na osi X w prawo
	oraz zmieniajaca movingState 
	@param deltaTime czas od poprzedniej iteracji
	@param map mapa rozgrywki*/
	void GoRight(const sf::Time & deltaTime, Map & map);

	/* Metoda ustwiajaca wartos canGoLeft na false */
	void ForbidGoingLeft() { canGoLeft = false; };

	/* Metoda ustwiajaca wartos canGoRight na false */
	void ForbidGoingRight() { canGoRight = false; };

	/* Metoda ustwiajaca wartos canGoDown na false */
	void ForbidGoingDown() { canGoDown = false; };

	/* Metoda ustwiajaca wartos canGoUp na false */
	void ForbidGoingUp() { canGoUp = false; };

	/* Metoda ustwiajaca wartos canGoLeft na true */
	void AllowGoingLeft() { canGoLeft = true; };

	/* Metoda ustwiajaca wartos canGoRight na true */
	void AllowGoingRight() { canGoRight = true; };

	/* Metoda ustwiajaca wartos canGoDown na true */
	void AllowGoingDown() { canGoDown = true; };

	/* Metoda ustwiajaca wartos canGoUp na true */
	void AllowGoingUp() { canGoUp = true; };

	/* Metoda wywolujaca metode UpdateSprite(), UpdateCollisionBox()
	oraz ustawiajaca pozycje sprite
	@param deltaTime czas od poprzedniej iteracji */
	void Update(const sf::Time deltaTime);

	/* Metoda odbijaca teksture sprite'a tak aby postac zwrocona
	byla twarza w aktualnym kierunku poruszania */
	void UpdateSprite();

	/* Metoda aktualizuja obszar kolizyjny postaci na podstawie
	jej aktualnej pozycji */
	void UpdateCollisionBox();

	/* Metoda sprawdzajaca czy nastepuje kolizja z eksplozja za 
	pomoca metody intersects(), a nastepnie sprawdza czy gracz
	koliduje z ktorymkolwiek z otaczajacych go blokow i odpowiednio
	blokuje lub odblokowywuje mozliwosc ruchu w wybranym kierunku 
	@param deltaTime czas od poprzedniej iteracji
	@param map mapa rozgrywki */
	void CheckForCollisions(const sf::Time & deltaTime, Map & map);

	/* Metoda zwracajaca zmienna killed */
	bool IsKilled() { return killed; };

	/* Metoda ustawiajaca zmienna killed na true */
	void Kill() { killed = true; };
	
	/* Metoda zapisujaca do pliku statistics.txt statystyki z zakonczonej
	wlasnie rozgrywki. Sa to data i czas rozegrania, ktory z graczy wygral
	ilosc postawionych przez graczy bomb 
	@param param parametr true dla gracza wygranego, po to by dwa razy nie
				 wypisywac daty i godziny */
	void SaveToFile(bool param);

	void SetPositionForLAN(int x, int y);

	void GetDataForLAN(std::string & data);

	//void GetDataForLAN(std::string & data, bool isOver);

	void SetMovingSate(bool direction);
};