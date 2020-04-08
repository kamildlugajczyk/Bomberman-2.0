#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <iterator>



int main()
{
	//------------------------ zadanie 1 ------------------------//

	std::vector<int> intVector;
	std::vector<int> copy_intVector(20);
	srand(time(NULL));

	for (int i = 0; i < 20; i++)
		intVector.push_back(rand() % 50 + 1);

	copy(intVector.begin(), intVector.end(), copy_intVector.begin());

	for_each(copy_intVector.begin(), copy_intVector.end(), [&](int & value) {std::cout << value << ", "; });

	std::cout << std::endl;
	sort(copy_intVector.begin(), copy_intVector.end());

	for_each(copy_intVector.begin(), copy_intVector.end(), [&](int & value) {std::cout << value << ", "; });

	std::cout << "\nMax: " << *max_element(copy_intVector.begin(), copy_intVector.end()) << std::endl;
	std::cout << "Max: " << *min_element(copy_intVector.begin(), copy_intVector.end()) << std::endl;

	//------------------------ zadanie 2 ------------------------//

	generate(intVector.begin(), intVector.end(), [n = 1]() mutable { return n++; });

	std::cout << "\n\nRosnaco: ";
	for_each(intVector.begin(), intVector.end(), [&](int & value) {std::cout << value << ", "; });

	reverse(intVector.begin(), intVector.end());

	std::cout << "\nMalejaco: ";
	for_each(intVector.begin(), intVector.end(), [&](int & value) {std::cout << value << ", "; });

	if (find(intVector.begin(), intVector.end(), 7) != intVector.end())
		std::cout << "\nZnaleziono szukana 7!\n\n" << std::endl;
	else
		std::cout << "\nNie znaleziono szukanej 7!\n\n" << std::endl;

	//------------------------ zadanie 3 ------------------------//

	std::vector<int> intVector2(10);
	std::vector<int> copy_intVector2(5);
	std::vector<int>::iterator i;
	std::vector<int>::reverse_iterator rev_i;

	generate(intVector2.begin(), intVector2.end(), [n = 1]() mutable { return n++; });

	for (i = intVector2.begin(); i != intVector2.end(); i++)
		std::cout << *i << ", ";
	std::cout << std::endl;

	for (rev_i = intVector2.rbegin(); rev_i != intVector2.rend(); rev_i++)
		std::cout << *rev_i << ", ";
	std::cout << std::endl;

	generate(copy_intVector2.begin(), copy_intVector2.end(), [n = 50]() mutable { return n++; });
	for_each(copy_intVector2.begin(), copy_intVector2.end(), [&](int & value) {std::cout << value << ", "; });
	std::cout << std::endl;

	copy(intVector2.begin(), intVector2.end(), std::inserter(copy_intVector2, copy_intVector2.begin()));
	for_each(copy_intVector2.begin(), copy_intVector2.end(), [&](int & value) {std::cout << value << ", "; });


	std::getchar();
	return 0;
}