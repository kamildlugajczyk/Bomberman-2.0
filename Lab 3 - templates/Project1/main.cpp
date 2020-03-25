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
template <typename Type>
class Tlista
{
private:
	struct element
	{
		Type data;
		element * pNext;
	};
	element * pHead;

public:
	Tlista() : pHead(nullptr) {};

	void InsertBegining(Type x)
	{
		if (!pHead)
		{
			element * newElement = new element;
			newElement->data = x;
			newElement->pNext = nullptr;
			pHead = newElement;
		}
		else
		{
			element * newElement = new element;
			newElement->data = x;
			newElement->pNext = pHead;
			pHead = newElement;
		}
	}

	void Show()
	{
		if (!pHead)
		{
			std::cout << "Lista nie zawiera zadnych elementow!" << std::endl;
		}
		else
		{
			element * pHelper = pHead;
			while (pHelper)
			{
				std::cout << pHelper->data << ", ";
				pHelper = pHelper->pNext;
			}
		}
	}
//----------------------------
// zadanie 3


};
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
	Tlista <double> linkedList;

	for (int i = 0; i < 20; i++)
		linkedList.InsertBegining(i);

	linkedList.Show();
	//----------------------------
	// testowanie zadania 3

	std::getchar();
	return 0;
}