#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "game.hpp"

int main()
{
	/*Game newGame{};
	newGame.Play();*/

	//-------- Testing TCP protocole ------- //
	char choice;
	std::cout << "S - server, C - client";
	std::cin >> choice;

	sf::TcpSocket socket;
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	std::string data = "x: 20 y: 25 right";
	std::string response = "Ok thank you!";
	char buffer[2000];
	std::size_t received;

	//-------- Client ------ //
	if (choice == 'c')
	{
		socket.connect(ip, 5300);
		socket.send(data.c_str(), data.length() + 1);
	}
	//-------- Server ------ //
	else if (choice == 's')
	{
		sf::TcpListener listener;
		listener.listen(5300);
		listener.accept(socket);
		socket.send(response.c_str(), response.length() + 1);
	}

	socket.receive(buffer, sizeof(buffer), received);
	std::cout << std::endl << buffer;

	std::getchar();
	std::getchar();

	return 0;
}