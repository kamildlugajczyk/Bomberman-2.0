#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "game.hpp"

int main()
{
	/*Game game;
	game.Play();*/

	char choice;
	std::cout << "s - server, c - client" << std::endl;
	std::cin >> choice;

	Game newGame{};
	newGame.PlayLAN(choice);

	////-------- Testing TCP protocole ------- //
	//char choice;
	//std::cout << "S - server, C - client";
	//std::cin >> choice;

	//sf::TcpSocket socket;
	//sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	//std::string data;
	//std::string response = "4 10";
	//char buffer[2000];
	//std::size_t received;

	//int positionx = 44, positiony = 22;
	//int gotPositionx, gotPositiony = 22;

	////-------- Client ------ //
	//if (choice == 'c')
	//{
	//	data.clear();
	//	data += std::to_string(positionx) + ' ' + std::to_string(positiony);
	//	std::cout << std::endl << data;
	//	socket.connect(ip, 5300);
	//	socket.send(data.c_str(), data.length() + 1);
	//}
	////-------- Server ------ //
	//else if (choice == 's')
	//{
	//	sf::TcpListener listener;
	//	listener.listen(5300);
	//	listener.accept(socket);
	//	//socket.send(response.c_str(), response.length() + 1);
	//}

	//socket.receive(buffer, sizeof(buffer), received);
	//std::cout << "Char array" << std::endl << buffer << std::endl;

	//sscanf_s(buffer, "%d %d", &gotPositionx, &gotPositiony);
	//std::cout << "\nInt values" << std::endl << gotPositionx << std::endl << gotPositiony << std::endl;
	//std::cout << gotPositionx + gotPositiony;

	//std::getchar();
	//std::getchar();

	return 0;
}