#include <iostream>
#include <stdexcept>

#include "class.h"

int main()
{
	Bank bank(500, 200);

	for (int i = 0; i < 20; i++)
	{
		try 
		{
			std::cout << "Transakcja karta \n" << std::endl;
			bank.ZaplacKarta(50);
		}
		catch (std::runtime_error & error) 
		{
			std::cout << error.what() << " Transakcja mozliwa jedynie gotowka. " << std::endl;
		}
		catch (std::logic_error & error) 
		{
			try 
			{
				bank.WezKredyt(200);
				std::cout << error.what() << " Wzieto kredyt. ";

				try 
				{
					bank.ZaplacKarta(100);
					std::cout << "Transakcja karta." << std::endl;
				}
				catch (std::exception & subError) 
				{
					std::cout << subError.what() << "Wystapily problemy z bankiem. Transakcja mozliwa jedynie gotowka." << std::endl;
				}
			}
			catch (std::logic_error & subError) 
			{
				std::cout << subError.what() << " " << subError.what() << " Transakcja mozliwa jedynie gotowka." << std::endl;
			}

		}
	}

	getchar();
	return 0;
}