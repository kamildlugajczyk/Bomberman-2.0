#include <iostream>
#include <thread>

#include "reactor.hpp"
#include "reactorMK2.hpp"

int main()
{
	Reaktor reaktor1{ 1225, "Pierwszy" };
	Reaktor reaktor2{ 4000, "Drugi" };
	Reaktor reaktor3{ 300, "Trzeci" };
	Reaktor reaktor4{ 745, "Czwarty" };

	std::thread thread1{ reaktor1, 400 };
	std::thread thread2{ reaktor2, 700 };
	std::thread thread3{ reaktor3, 25 };
	std::thread thread4{ reaktor4, 50 };

	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();

	std::getchar();
	return 0;
}