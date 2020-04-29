#include <iostream>
#include <thread>
#include <atomic>

#include "reactorMK2.hpp"

//std::atomic_flag lock = ATOMIC_FLAG_INIT;

void ReaktorMK2::operator()(int moc)
{
	while (paliwo - moc > 0)
	{
		paliwo -= moc;
		std::this_thread::sleep_for(std::chrono::microseconds(500));

		//while (lock.test_and_set(std::memory_order_acquire));
		std::cout << " Nazwa: " << nazwa << "\n Ilosc paliwa: " << paliwo << std::endl << std::endl;
		//lock.clear(std::memory_order_release);
	}
}
