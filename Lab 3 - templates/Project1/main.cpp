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

	void InsertBeginning(Type x)
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
			std::cout << std::endl;
		}
	}
};
//----------------------------
// zadanie 3
template <typename Type>
class TPrzechowalnia 
{
	Type data;

public:
	TPrzechowalnia()
	{
		Clear();
	}

	void Clear()
	{
		data = 0;
	}

	void Add(Type newElement)
	{
		data += newElement;
	}

	Type Show()
	{
		return data;
	}
};

template<>
class TPrzechowalnia<char> 
{
	std::string text;
public:
	void Add(char newElement)
	{
		text += newElement;
	}

	std::string Show()
	{
		return text;
	};
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
	Tlista <int> linkedList;

	for (int i = 0; i < 20; i++)
		linkedList.InsertBeginning(i);

	linkedList.Show();

	Tlista <double> linkedListDouble;

	linkedListDouble.InsertBeginning(4.25);
	linkedListDouble.InsertBeginning(2.99);
	linkedListDouble.InsertBeginning(10.23);

	linkedListDouble.Show();
	//----------------------------
	// testowanie zadania 3

	TPrzechowalnia<float> storeFloat;
	std::cout << storeFloat.Show() << std::endl;
	storeFloat.Add(12.99);
	std::cout << storeFloat.Show() << std::endl;
	storeFloat.Clear();
	std::cout << storeFloat.Show() << std::endl;

	TPrzechowalnia<char> storeChar;
	storeChar.Add('t');
	std::cout << storeChar.Show() << std::endl;

	std::getchar();
	return 0;
}