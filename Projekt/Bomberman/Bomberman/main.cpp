#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "game.hpp"
#include "main_menu.hpp"

int main()
{
	Game game;
	game.Play();

	

	/*Game newGame{};
	newGame.PlayLAN();*/

	return 0;
}