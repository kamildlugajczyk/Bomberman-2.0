#include <iostream>
#include <string>

// zadanie 1
template<typename Type>
Type operacja_na_liczbach(Type x, Type y)
{
	return x + y;
}

template<>
double operacja_na_liczbach(double x, double y)
{
	return x - y;
}
//----------------------------
// zadanie 2


int main()
{
	// testowanie zadania 1
	int firstInt = 20,
		secondInt = 44;

	std::cout << "Wynik dla typu int: " << operacja_na_liczbach(firstInt, secondInt) << std::endl;

	long firstLong = 20,
		secondLong = 44;

	std::cout << "Wynik dla typu long: " << operacja_na_liczbach(firstLong, secondLong) << std::endl;

	double firstDouble = 20.0,
		secondDouble = 44.0;

	std::cout << "Wynik dla typu double: " << operacja_na_liczbach(firstDouble, secondDouble) << std::endl;
	//----------------------------
	// testowanie zadania 2



	std::getchar();
	return 0;
}